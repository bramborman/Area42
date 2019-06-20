using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace StorageTools.Modules
{
    public sealed class DuplicatesFinderModule : AModule
    {
        public override string Name { get; } = "Duplicates finder";
        public override string Description { get; } = "Duplicates finder";

        protected override void RunCore()
        {
            bool inputActive = true;
            LinkedList<string> roots = new LinkedList<string>();

            //TODO: What about relative paths?
            //TODO: What about environment variables? such as %appdata% etc.
            //TODO: FIX IT!
            do
            {
                Console.Write("Enter a folder path to scan for duplicates (enter nothing to start scanning): ");

                string path = Console.ReadLine();

                if (path.EndsWith(":"))
                {
                    path += "\\";
                }

                path = path.Replace('/', '\\');

                if (string.IsNullOrEmpty(path))
                {
                    if (roots.Count == 0)
                    {
                        Console.WriteLine("You must enter at least one valid path");
                    }
                    else
                    {
                        inputActive = false;
                    }
                }
                else if (!Directory.Exists(path) || !ValidForChecking(path))
                {
                    Console.WriteLine("Invalid path. It either doesn't exist or is not valid for scanning.");
                }
                else
                {
                    roots.AddLast(path);
                }
            } while (inputActive);

            Dictionary<byte[], FileInfo> hashes = new Dictionary<byte[], FileInfo>(new HashComparer());
            int filesScanned = 0;
            int directoriesScanned = 0;
            int warnings = 0;
            int errors = 0;
            int duplicates = 0;
            long duplicatesSize = 0;

            DateTime started = DateTime.Now;
            Console.WriteLine("Scan started at " + started.ToShortDateString() + ' ' + started.ToLongTimeString());
            Stopwatch stopwatch = Stopwatch.StartNew();

            CancellationTokenSource cts = new CancellationTokenSource();
            cts.Token.ThrowIfCancellationRequested();

            Task<string> scanningTask = Task.Run(() =>
            {
                StringBuilder logBuilder = new StringBuilder();

                using (MD5 algorithm = MD5.Create())
                {
                    foreach (string root in roots)
                    {
                        if (cts.IsCancellationRequested)
                        {
                            break;
                        }

                        CheckDirectory(root);
                    }


                    void CheckDirectory(string directory)
                    {
                        directoriesScanned++;

                        try
                        {
                            foreach (string file in Directory.EnumerateFiles(directory).Where(ValidForChecking))
                            {
                                if (cts.IsCancellationRequested)
                                {
                                    break;
                                }

                                filesScanned++;

                                try
                                {
                                    using (FileStream fileStream = File.OpenRead(file))
                                {
                                        // Skip empty files
                                        if (fileStream.Length == 0)
                                        {
                                            continue;
                                        }

                                        byte[] hash = algorithm.ComputeHash(fileStream);

                                        if (hashes.TryGetValue(hash, out FileInfo fileInfo))
                                        {
                                            duplicates++;
                                            duplicatesSize += fileInfo.Size;

                                            ValidateAndLogWarning(fileStream.Length == fileInfo.Size, "Different size.");
                                            ValidateAndLogWarning(string.Equals(Path.GetExtension(file), fileInfo.Extension), "Different extension.");


                                            void ValidateAndLogWarning(bool condition, string warningMessageIfNotTrue)
                                            {
                                                if (!condition)
                                                {
                                                    warnings++;
                                                    logBuilder.AppendLine($"WARNING: {warningMessageIfNotTrue} File path: " + file);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            fileInfo = new FileInfo(fileStream.Length, Path.GetExtension(file));
                                            hashes[hash] = fileInfo;
                                        }

                                        fileInfo.Paths.AddLast(file);
                                    }
                                }
                                catch (Exception exception)
                                {
                                    LogException(exception, file, false);
                                }
                            }

                            foreach (string subDirectory in Directory.EnumerateDirectories(directory).Where(ValidForChecking))
                            {
                                if (cts.IsCancellationRequested)
                                {
                                    break;
                                }

                                CheckDirectory(subDirectory);
                            }

                        }
                        catch (Exception exception)
                        {
                            LogException(exception, directory, true);
                        }
                    }


                    void LogException(Exception exception, string path, bool directory)
                    {
                        errors++;

                        logBuilder.AppendLine($"ERROR: An exception occured. {(directory ? "Directory" : "File")} path: " + path);
                        logBuilder.AppendLine("       Exception message:");

                        foreach (string messageLine in exception.Message.Split('\n'))
                        {
                            logBuilder.AppendLine("       " + messageLine);
                        }
                    }
                }

                return logBuilder.ToString();
            }, cts.Token);


            const string SCANNING_MESSAGE = "Scanning";

            if (WriteDotProgress(SCANNING_MESSAGE, true, () => !scanningTask.Wait(1000)))
            {
                //                                                      Scanning  . . . <= remove the dots after the message
                Console.Write('\r' + new string(' ', SCANNING_MESSAGE.Length) + "      \r");
                cts.Cancel();
                WriteDotProgress("Aborting", false, () => !scanningTask.Wait(1000));
            }

            if (scanningTask.Status == TaskStatus.RanToCompletion)
            {
                if (!cts.IsCancellationRequested)
                {
                    Console.WriteLine($"\r{SCANNING_MESSAGE} finished");
                }
                else
                {
                    Console.WriteLine($"\r{SCANNING_MESSAGE} aborted by user");
                }
            }
            else
            {
                Console.WriteLine($"\r{SCANNING_MESSAGE} aborted due to an unknown error");
            }

            stopwatch.Stop();
            DateTime ended = DateTime.Now;

            Console.WriteLine($"Scan ended after {stopwatch.Elapsed} at {ended.ToShortDateString()} {ended.ToLongTimeString()}");
            Console.WriteLine($"Attempted to scan {filesScanned:N0} files in {directoriesScanned:N0} directories");
            Console.WriteLine($"Found {duplicates:N0} duplicates with complete size of {FormatSize(duplicatesSize)}");
            Console.WriteLine($"There were {errors:N0} errors and {warnings:N0} warnings during scan");

            //TODO: Export the log somewhere
            //if (!string.IsNullOrWhiteSpace(scanningTask.Result))
            //{
            //    Console.WriteLine(scanningTask.Result);
            //}


            bool WriteDotProgress(string message, bool cancellable, Func<bool> predicate)
            {
                Console.Write(message);

                int iteration = 0;

                while (predicate())
                {
                    if (cancellable && Console.KeyAvailable)
                    {
                        ConsoleKeyInfo cki = Console.ReadKey(true);

                        if (cki.Key == ConsoleKey.Escape &&
                            !cki.Modifiers.HasFlag(ConsoleModifiers.Alt) &&
                            !cki.Modifiers.HasFlag(ConsoleModifiers.Shift) &&
                            !cki.Modifiers.HasFlag(ConsoleModifiers.Control))
                        {
                            // Clear input buffer
                            while (Console.KeyAvailable)
                            {
                                Console.ReadKey(true);
                            }

                            return true;
                        }
                    }

                    if (iteration == 3 || iteration == 6)
                    {
                        Console.CursorLeft = message.Length;

                        if (iteration == 6)
                        {
                            iteration = 0;
                        }
                    }

                    if (iteration < 3)
                    {
                        Console.Write(" .");
                    }
                    else if (iteration < 6)
                    {
                        Console.Write("  ");
                    }

                    iteration++;
                }

                return false;
            }

            string FormatSize(long size)
            {
                char[] thingies = new[] { 'k', 'M', 'G', 'T' };

                double calculatedSize = size;
                int divides = 0;

                while (calculatedSize >= 1024d)
                {
                    calculatedSize /= 1024d;
                    divides++;
                }

                return divides == 0 ? size + " B" : $"{calculatedSize:N} {thingies[divides - 1]}B ({size:N0} B)";
            }

            // just a quickie
            // should be refactored
            bool ValidForChecking(string path)
            {
                // Probably a volume, for example "C:\"
                // Not the right way of doing this
                if (string.Equals(Path.GetPathRoot(path), path, StringComparison.InvariantCultureIgnoreCase))
                {
                    return true;
                }

                FileAttributes attributes = File.GetAttributes(path);

                if (attributes.HasFlag(FileAttributes.System) || attributes.HasFlag(FileAttributes.Hidden) || attributes.HasFlag(FileAttributes.Temporary))
                {
                    return false;
                }

                // Should also be like hidden probably
                // At least on Linux, maybe macOS
                // and maybe all Unix-like OSes?
                // Or does FileAttributes.Hidden apply even
                // for these items?
                if (Path.GetFileName(path).StartsWith("."))
                {
                    return false;
                }

                string[] blacklist = new string[]
                {
                    // Is this ok?
                    // I mean all of them
                    // and specifically the name
                    // of recycle bin
                    @"C:\$RECYCLE.BIN", @"C:\Program Files", @"C:\Program Files (x86)", @"C:\Users\Administrator", @"C:\Users\Default", @"C:\Windows"
                };

                if (attributes.HasFlag(FileAttributes.Directory) && blacklist.Any(p => string.Equals(p, path, StringComparison.InvariantCultureIgnoreCase)))
                {
                    return false;
                }

                return true;
            }
        }


        private sealed class FileInfo
        {
            public LinkedList<string> Paths { get; } = new LinkedList<string>();
            public long Size { get; }
            public string Extension { get; }

            public FileInfo(long size, string extension)
            {
                Size = size;
                Extension = extension;
            }
        }

        private sealed class HashComparer : IEqualityComparer<byte[]>
        {
            public bool Equals(byte[] x, byte[] y)
            {
                return x.SequenceEqual(y);
            }

            public int GetHashCode(byte[] obj)
            {
                return ((IStructuralEquatable)obj).GetHashCode(EqualityComparer<object>.Default);
            }
        }
    }
}

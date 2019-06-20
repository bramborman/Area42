using System;
using System.IO;
using System.Linq;
using System.Security.Cryptography;

namespace StorageTools.Modules
{
    public sealed class FolderComparerModule : AModule
    {
        public override string Name { get; } = "Folder comparer";
        public override string Description { get; } = "Folder comparer";

        protected override void RunCore()
        {
            const string F1 = @"";
            const string F2 = @"";

            if (!Directory.Exists(F1) || !Directory.Exists(F2))
            {
                Console.WriteLine("F1 or F2 doesn't exist");
                Console.ReadLine();

                Environment.Exit(17);
                return;
            }

            Console.WriteLine("Comparing F2 to F1");
            Compare(F2, F1);
            Console.ReadLine();


            void Compare(string f1, string f2)
            {
                int same = 0;
                int ds = 0;
                int nf = 0;
                int i = 0;

                foreach (string file1 in Directory.EnumerateFiles(f1, "*", SearchOption.AllDirectories))
                {
                    string file2 = file1.Replace(f1, f2);

                    if (File.Exists(file2))
                    {
                        long size1 = GetFileSize(file1);
                        long size2 = GetFileSize(file2);

                        Console.ForegroundColor = ConsoleColor.White;
                        Console.WriteLine("file #" + ++i);

                        if (size1 == size2)
                        {
                            using (MD5 h = MD5.Create())
                            {
                                using (FileStream f1s = File.OpenRead(file1), f2s = File.OpenRead(file2))
                                {
                                    if (!h.ComputeHash(f1s).SequenceEqual(h.ComputeHash(f2s)))
                                    {
                                        throw new Exception(":(");
                                    }
                                }
                            }

                            string tdp = file1;

                            //if (CheckRoot(tdp, @"E:\"))
                            //{
                            //    //File.Delete(tdp);
                            //}

                            //if (CheckFolder(tdp, @"C:\Users\marian\OneDrive\others\scr"))
                            //{
                            //    //File.Delete(tdp);
                            //}

                            same++;
                        }
                        else
                        {
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.WriteLine($"different size of files: ({size1}) & ({size2})");
                            Console.WriteLine("\tfile1: " + file1);
                            Console.WriteLine("\tfile2: " + file2);

                            ds++;
                        }
                    }
                    else
                    {
                        //File.Move(file1, file2);
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine("file not found:");
                        Console.WriteLine("\tfile1: " + file1);
                        Console.WriteLine("\tfile2: " + file2);
                        nf++;
                    }
                }

                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Same:\t\t" + same);
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("Different size:\t" + ds);
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("Not found:\t" + nf);
            }

            bool CheckRoot(string path, string root)
            {
                return string.Equals(Path.GetPathRoot(path), root, StringComparison.InvariantCultureIgnoreCase);
            }

            bool CheckFolder(string path, string folder)
            {
                return string.Equals(Path.GetDirectoryName(path), folder, StringComparison.InvariantCultureIgnoreCase);
            }

            // Is this function correct?
            // I mean, working correctly all the time?
            // Who knows
            // And who cares :))))
            long GetFileSize(string path)
            {
                using (FileStream fileStream = File.OpenRead(path))
                {
                    return fileStream.Length;
                }
            }
        }
    }
}

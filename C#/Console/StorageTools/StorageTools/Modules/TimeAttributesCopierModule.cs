using System;
using System.IO;

namespace StorageTools.Modules
{
    public sealed class TimeAttributesCopierModule : AModule
    {
        public override string Name { get; } = "Time attributes copier";
        public override string Description { get; } = "Time attributes copier";

        protected override void RunCore()
        {
            string sourceFolder = GetFolder("Enter source folder path");
            string destinationFolder = GetFolder("Enter destination folder path");

            string confirmation;

            do
            {
                Console.Write($"\nAre you sure?" +
                              $"\nWe'll copy time attributes of all files from '{Path.GetFileName(sourceFolder)}' to '{Path.GetFileName(destinationFolder)}'? [Y/n]: ");
                confirmation = Console.ReadLine().ToLowerInvariant();
            } while (confirmation != "y" && confirmation != "n");

            if (confirmation == "y")
            {
                foreach (string sourceFile in Directory.EnumerateFiles(sourceFolder, "*", SearchOption.AllDirectories))
                {
                    string fileName = Path.GetFileName(sourceFile);

                    try
                    {
                        string destinationFile = Path.Combine(destinationFolder, fileName);

                        File.SetCreationTimeUtc(destinationFile, File.GetCreationTimeUtc(sourceFile));
                        File.SetLastAccessTimeUtc(destinationFile, File.GetLastAccessTimeUtc(sourceFile));
                        File.SetLastWriteTimeUtc(destinationFile, File.GetLastWriteTimeUtc(sourceFile));

                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.WriteLine($"Copying attributes of file {fileName} completed.");
                    }
                    catch (Exception exception)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine($"Copying attributes of file {fileName} failed.\n\tError message: " + exception.Message);
                    }
                }
            }


            string GetFolder(string message)
            {
                string folderPath;

                do
                {
                    Console.Write(message + ": ");
                    folderPath = Console.ReadLine().Replace("\"", "");
                } while (string.IsNullOrWhiteSpace(folderPath) || !Directory.Exists(folderPath));

                return folderPath;
            }
        }
    }
}

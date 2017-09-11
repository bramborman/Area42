using System;
using System.IO;
using System.Reflection;

namespace FileTimeAttributesCopier
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            AssemblyName assemblyName = Assembly.GetExecutingAssembly().GetName();
            Version v = assemblyName.Version;
            Console.Title = $"{assemblyName.Name} v{v.Major}.{v.Minor}.{v.Build}";

            Console.ForegroundColor = ConsoleColor.White;
 
            string sourceFolder = GetFolder("Enter source folder path");
            string destinationFolder = GetFolder("Enter destination folder path");

            Console.ForegroundColor = ConsoleColor.Yellow;
            string confirmation;

            do
            {
                Console.Write($"\nAre you sure?" +
                    $"\nWe'll copy time attributes of all files from '{Path.GetFileName(sourceFolder)}' to '{Path.GetFileName(destinationFolder)}'? [Y/n]: ");
                confirmation = Console.ReadLine().ToLowerInvariant();
            } while (confirmation != "y" && confirmation != "n");

            Console.ForegroundColor = ConsoleColor.White;

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

            Console.ForegroundColor = ConsoleColor.White;
            Console.Write("\nPress any key to exit . . .");
            Console.ReadKey(true);
        }

        private static string GetFolder(string message)
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

using System;
using System.Diagnostics;
using System.Reflection;
using static System.Console;

namespace ಠ_ಠ
{
    public static class Program
    {
        private static readonly Random random = new Random();

        private static bool customTheme = false;
        private static int foregroundShift;
        private static int backgroundShift;

        public static void Main(string[] args)
        {
            Assembly assembly = Assembly.GetExecutingAssembly();
            AssemblyName assemblyName = assembly.GetName();
            Version v = assemblyName.Version;
            FileVersionInfo versionInfo = FileVersionInfo.GetVersionInfo(assembly.Location);

            Title = $"{assemblyName.Name} v{v.Major}.{v.Minor}.{v.Build} {versionInfo.LegalCopyright}";

            BufferWidth = WindowWidth;
            BufferHeight = WindowHeight;

            bool lastWasShift = false;

            foreach (string arg in args)
            {
                if (lastWasShift && int.TryParse(arg, out int theme))
                {
                    customTheme = true;
                    foregroundShift = theme % 16;
                    backgroundShift = (theme + 8) % 16;
                }

                lastWasShift = arg.Equals("-t", StringComparison.InvariantCultureIgnoreCase) || arg.Equals("--theme", StringComparison.InvariantCultureIgnoreCase);
            }

            WriteWithRandomColors(1);

            for (ulong i = 2; i < ulong.MaxValue; i++)
            {
                bool isPrimeNumber = true;

                for (ulong j = 2; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        isPrimeNumber = false;
                        break;
                    }
                }

                if (isPrimeNumber)
                {
                    WriteWithRandomColors(i);
                }
            }
        }

        private static void WriteWithRandomColors(ulong value)
        {
            if (customTheme)
            {
                ForegroundColor = (ConsoleColor)(((int)value + foregroundShift) % 16);
                BackgroundColor = (ConsoleColor)(((int)value + backgroundShift) % 16);

                if (BackgroundColor == ForegroundColor)
                {
                    BackgroundColor = (ConsoleColor)(((int)BackgroundColor + 1) % 16);
                }
            }
            else
            {
                ForegroundColor = (ConsoleColor)random.Next(0, 15);

                do
                {
                    BackgroundColor = (ConsoleColor)random.Next(0, 15);
                } while (BackgroundColor == ForegroundColor);
            }

            Write(value);
        }
    }
}

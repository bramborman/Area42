using System;
using System.Linq;

namespace StringCentering
{
    public static class StringCentering
    {
        public static int GetLinesCount(this string str)
        {
            return str.Count(ch => ch == '\n');
        }

        public static void WriteCentered(this string str)
        {
            Console.CursorTop = (Console.WindowHeight - str.GetLinesCount()) / 2;

            foreach (string s in str.Split('\n'))
            {
                Console.CursorLeft = (Console.WindowWidth - s.Length) / 2;
                Console.WriteLine(s);
            }
        }
    }
}

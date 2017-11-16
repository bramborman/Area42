using System;
using System.Collections.Generic;
using System.Linq;

namespace Test01
{
    public static class Program
    {
        private static readonly ConsoleColor defaultForegroundColor = ConsoleColor.White;

        public static void Main(string[] args)
        {
            Console.CursorVisible   = false;

            int iterations;
            int mostFrequentLetterCount;
            char mostFrequentLetter = Everything(out mostFrequentLetterCount, out iterations);
            
            Console.WriteLine($"\n\nCelkový počet iterací: {iterations}");
            Console.Write($"Nejčastěji generované písmeno: {mostFrequentLetter} (vygenerováno {mostFrequentLetterCount}x)");
            Console.ReadKey();
        }

        private static char Everything(out int mostFrequentLetterCount, out int iterations)
        {
            bool[] generated                    = new bool[10];
            Dictionary<char, int> letterCounts  = new Dictionary<char, int>();
            Random random                       = new Random();
            
            iterations = 0;

            while (!generated.All(g => g))
            {
                iterations++;
                Console.ForegroundColor = defaultForegroundColor;

                char ch = (char)random.Next(20, 120);

                if (char.IsLetter(ch))
                {
                    if (!letterCounts.ContainsKey(ch))
                    {
                        letterCounts.Add(ch, 0);
                    }

                    letterCounts[ch]++;
                }

                object output = ch;

                if (char.IsDigit(ch))
                {
                    generated[ch - '0'] = true;
                    Console.ForegroundColor = ConsoleColor.Yellow;
                }
                else if (char.IsLetter(ch))
                {
                    Console.ForegroundColor = char.IsUpper(ch) ? ConsoleColor.Cyan : ConsoleColor.Magenta;
                }
                else
                {
                    Console.ForegroundColor = ConsoleColor.Gray;
                    output = (int)ch;
                }

                Console.Write(output.ToString().PadLeft(3).Replace(' ', '_') + ", ");
            }

            Console.Write("\b\b ");

            Console.ForegroundColor = defaultForegroundColor;

            KeyValuePair<char, int> nejcastejsi = letterCounts.OrderByDescending(k => k.Value).First();
            mostFrequentLetterCount = nejcastejsi.Value;
            return nejcastejsi.Key;
        }
    }
}

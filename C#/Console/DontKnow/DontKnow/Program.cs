using System;
using System.Collections.Generic;

namespace DontKnow
{
    public static class Program
    {
        private static readonly Random random     = new Random();
        private static readonly List<ulong> cache = new List<ulong>();

        public static void Main(string[] args)
        {
            Console.Write("1 2 ");
            bool isPrimeNumber;

            for (ulong i = 3; i < ulong.MaxValue; i += 2)
            {
                isPrimeNumber = true;

                foreach (ulong j in cache)
                {
                    if (i % j == 0)
                    {
                        isPrimeNumber = false;
                        break;
                    }
                }

                if (isPrimeNumber)
                {
                    cache.Add(i);
                    Console.Write($"{i}");
                }

                Console.ForegroundColor = (ConsoleColor)random.Next(1, 15);

                do
                {
                    Console.BackgroundColor = (ConsoleColor)random.Next(1, 15);
                } while (Console.BackgroundColor == Console.ForegroundColor);
            }

            Console.ReadKey();
        }
    }
}

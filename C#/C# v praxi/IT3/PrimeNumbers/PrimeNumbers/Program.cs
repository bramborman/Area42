﻿#define ERATOSTHENES
//#define ERATOSTHENES_THREADING

using System;
using System.Diagnostics;
#if ERATOSTHENES || ERATOSTHENES_THREADING
using System.Collections.Generic;
#endif
#if ERATOSTHENES_THREADING
using System.Threading;
#endif

namespace PrimeNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
#if ERATOSTHENES && ERATOSTHENES_THREADING
            throw new Exception("Invalid flags defined.");
#endif
            var maxValue =
#if !ERATOSTHENES && !ERATOSTHENES_THREADING
                (ulong)100000//ulong.MaxValue
#else
                100000//int.MaxValue
#endif
                ;

            Console.Title = "Prime numbers";
            
            bool uiVisible = true;
#if ERATOSTHENES || ERATOSTHENES_THREADING
            List<int> numbers = new List<int>();
#endif

            try
            {
                Console.CursorVisible = false;
            }
            catch
            {
                uiVisible = false;
            }

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

#if !ERATOSTHENES && !ERATOSTHENES_THREADING
            bool divided;
            
            Console.Write("1 ");

            for (ulong i = 2; i < maxValue; i++)
            {
                divided = false;

                for (ulong j = 2; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        divided = true;
                        break;
                    }
                }

                if (!divided)
                {
                    Console.Write($"{i} ");
                }
            }
#elif ERATOSTHENES
            for (int i = 3; i < maxValue; i += 2)
            {
                try
                {
                    numbers.Add(i);
                }
                catch
                {
                    break;
                }
            }

            Console.Write("1 2 ");

            while (numbers.Count != 0)
            {
                int baseNumber = numbers[0];

                Console.Write($"{baseNumber} ");
                numbers.RemoveAll(number => number % baseNumber == 0);
            }
#elif ERATOSTHENES_THREADING
            int numbersCount = 0;
            ManualResetEventSlim resetEvent = new ManualResetEventSlim();

            new Thread(() =>
            {
                if (uiVisible)
                {
                    Console.Write("Loading");
                }

                while (!resetEvent.IsSet)
                {
                    if (uiVisible)
                    {
                        Console.Write(".");
                    }

                    Thread.Sleep(1000);
                }

                for (int i = 0; i < 10; i++)
                {
                    if (uiVisible)
                    {
                        Console.Write(".");
                    }

                    Thread.Sleep(1000);
                }

                if (uiVisible)
                {
                    Console.Clear();
                }

                Console.WriteLine($"Ready to display prime numbers up to {(numbersCount + 1) * 2}.");

                if (uiVisible)
                {
                    Console.WriteLine("Press any key to continue . . .");
                    Console.ReadKey();
                    Console.Clear();
                }

                Console.Write("1 2 ");

                for (int i = 0; i < numbers.Count; i++)
                {
                    Console.Write($"{numbers[i]} ");
                }
            }).Start();

            for (int i = 3; i < maxValue; i += 2)
            {
                try
                {
                    numbers.Add(i);
                }
                catch
                {
                    break;
                }
            }

            numbersCount = numbers.Count;
            resetEvent.Set();

            for (int i = 0; i < numbers.Count; i++)
            {
                int baseNumber = numbers[i];
                numbers.RemoveAll(number => number % baseNumber == 0 && number != baseNumber);
            }
#endif

            stopwatch.Stop();
            Console.Write($"\nElapsed {stopwatch.Elapsed.ToString("hh':'mm':'ss':'fff")}");
            
            if (uiVisible)
            {
                Console.ReadKey();
            }
        }
    }
}

#define CALCULATION

using System;
using System.Diagnostics;
using System.Threading;

/// <summary>
/// This is one really shitty code xD
/// </summary>
namespace Threading
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            string underline = new string('=', 66);

            Console.WriteLine("Starting threads");
            Console.WriteLine(underline);
            
            Thread[] threads = new Thread[10];

#if !CALCULATION
            Stopwatch stopwatch = Stopwatch.StartNew();

            int valuesByThread = Values.COUNT / threads.Length;
#endif

            for (int i = 0; i < threads.Length; i++)
            {
#if CALCULATION
                threads[i] = new Thread(Calculation.Calculate);
                threads[i].Start();
#else
                threads[i] = new Thread(new ParameterizedThreadStart(Values.CalculateSum));

                int min = valuesByThread * i;
                int max = i == threads.Length - 1 ? Values.COUNT - 1 : (valuesByThread * (i + 1)) - 1;

                threads[i].Start(new int[] { min, max });
#endif
            }
            
            foreach (Thread thread in threads)
            {
                thread.Join();
            }

            Console.WriteLine(underline);

#if CALCULATION
            Console.WriteLine($"Threads finished with result {Calculation.Result}");
#else
            stopwatch.Stop();
            Console.WriteLine($"{threads.Length.ToString().PadLeft(3)} threads finished with result {Values.Sum} after {stopwatch.Elapsed.Ticks.ToString().PadLeft(7)} ticks");
#endif

#if !CALCULATION
            stopwatch.Restart();
            Values.CalculateSum();
            stopwatch.Stop();

            Console.WriteLine($"One thread  finished with result {Values.Sum} after {stopwatch.Elapsed.Ticks.ToString().PadLeft(7)} ticks");
#endif

            Console.ReadLine();
        }
    }

#if CALCULATION
    public static class Calculation
    {
        private static readonly object syncRoot = new object();
        
        public static long Result { get; private set; }

        public static void Calculate()
        {
            Stopwatch stopwatch = Stopwatch.StartNew();

            long result = 0;

            for (int i = 0; i < 100; i++)
            {
                result++;
            }

            lock (syncRoot)
            {
                long newResult = Result + result;
                Thread.Sleep(10);
                Result = newResult;

                Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId.ToString().PadLeft(2)} completed execution with output {result} after {stopwatch.ElapsedTicks.ToString().PadLeft(6)} ticks");
            }
        }
    }
#else
    public static class Values
    {
        public const int COUNT = 1000000;

        private static readonly object syncRoot = new object();
        private static readonly int[] values = new int[COUNT];
        
        public static int Sum { get; private set; }

        static Values()
        {
            Random random = new Random(0);

            for (int i = 0; i < values.Length; i++)
            {
                values[i] = random.Next(0, 10);
            }
        }

        public static void CalculateSum()
        {
            int sum = 0;

            foreach (int i in values)
            {
                sum += i;
            }

            lock (syncRoot)
            {
                Sum = sum;
            }
        }

        public static void CalculateSum(object range)
        {
            Stopwatch stopwatch = Stopwatch.StartNew();
            int[] rangeArray = (int[])range;

            int sum = 0;

            for (int i = rangeArray[0]; i <= rangeArray[1]; i++)
            {
                sum += values[i];
            }

            lock (syncRoot)
            {
                Sum += sum;
            }

            Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId.ToString().PadLeft(2)} completed execution with output {sum} after {stopwatch.ElapsedTicks.ToString().PadLeft(5)} ticks");
        }
    }
#endif
}

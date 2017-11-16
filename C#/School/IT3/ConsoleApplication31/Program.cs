using System;

namespace ConsoleApplication31
{
    public sealed class Program
    {
        public int Max { get; set; }

        private Program(int max)
        {
            this.Max = max;
            WriteNumber(new Random().Next(0, Max));
        }

        private static void WriteNumber(int number)
        {
            Console.WriteLine(number);
            Console.ReadKey();
        }

        private static void Main(string[] args)
        {
            new Program(11);
        }
    }
}

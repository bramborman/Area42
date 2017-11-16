using System;

namespace ConsoleApplication28
{
    class Program
    {
        static void Main(string[] args)
        {
            Ponies ponies = new Ponies(17);
            Console.Write($"Count of ponies: {ponies.Count}");

            Console.ReadKey();
        }
    }

    class Ponies
    {
        public int Count { get; }

        public Ponies(int ponyCount)
        {
            Count = ponyCount;
        }
    }
}

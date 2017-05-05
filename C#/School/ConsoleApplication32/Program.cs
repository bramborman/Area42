using System;

namespace ConsoleApplication32
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            int[] array = { 1, 2, 3, 4, 5 };
            array.Write();

            Console.WriteLine();
            Array.ForEach(array, Console.WriteLine);

            Console.ReadKey();
        }

        private static void Write(this int[] array)
        {
            Array.ForEach(array, Console.WriteLine);
            Array.Clear(array, 0, array.Length);
        }
    }
}

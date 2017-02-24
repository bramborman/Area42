using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication14
{
    class Program
    {
        static void Main(string[] args)
        {
            int size;

            Console.Write("Zadej velikost: ");
            while (!int.TryParse(Console.ReadLine(), out size) || size < 2 || size >= Console.WindowWidth || size >= Console.WindowHeight) ;

            char[] array = new char[size * size];

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    array[(i * size) + j] = i % 2 != j % 2 ? ' ' : '#';
                }
            }

            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i]);

                if (i % size == size - 1)
                {
                    Console.WriteLine();
                }
            }

            Console.ReadKey();
        }
    }
}

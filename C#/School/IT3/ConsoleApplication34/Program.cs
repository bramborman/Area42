using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication34
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] numbers = new int[2, 5];

            for (int i = 0; i < numbers.Length / 2; i++)
            {
                numbers[0, i] = i + 1;
                numbers[1, i] = i + 6;

                Console.CursorLeft = 2 * i;
                Console.WriteLine($"{numbers[0, i]} ");

                Console.CursorLeft = 2 * i;
                Console.Write($"{numbers[1, i]} ");

                Console.CursorTop--;
            }

            Console.ReadKey();
        }
    }
}

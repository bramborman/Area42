using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication23
{
    class Yeah
    {
        public void Boii(int x, ref int min, ref int max)
        {
            if (x < min)
            {
                min = x;
            }

            if (x > max)
            {
                max = x;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int x;
            int min = 0;
            int max = 0;
            Yeah yeah = new Yeah();

            for (int i = 0; i < 4; i++)
            {
                do
                {
                    Console.Write($"Zadej {i + 1}. cislo: ");
                } while (!int.TryParse(Console.ReadLine(), out x));

                if (i == 0)
                {
                    min = x;
                    max = x;
                }

                yeah.Boii(x, ref min, ref max);
            }

            Console.Write($"\nMin: {min}, Max: {max}");
            Console.ReadKey();
        }
    }
}

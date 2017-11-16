using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication29
{
    class Program
    {
        static void Main(string[] args)
        {
            int count;
            
            do
            {
                Console.Write("Zadej pocet cisel: ");
            } while (!int.TryParse(Console.ReadLine(), out count) || count < 0);

            int maxValue;

            do
            {
                Console.Write("Zadej maximalni hodnotu: ");
            } while (!int.TryParse(Console.ReadLine(), out maxValue) || maxValue < 2);

            new Foo(count, maxValue);
        }
    }

    class Foo
    {
        public Foo(int count, int maxValue)
        {
            int max = 0;
            Random random = new Random();

            for (int i = 0; i < count; i++)
            {
                int randomValue = random.Next(1, maxValue);

                Console.Write($"{randomValue} ");

                if (randomValue > max)
                {
                    max = randomValue;
                }
            }

            Console.Write($"\nMax: {max}");
            Console.ReadKey();
        }
    }
}

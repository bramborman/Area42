using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication13
{
    class Program
    {
        static void Main(string[] args)
        {
            int maxValue;
            int[] array = new int[50];

            Console.Write("Zadej cislo: ");
            while (!int.TryParse(Console.ReadLine(), out maxValue)) ;

            for (int i = 0; i < array.Length; i++)
            {
                array[i] = i + maxValue;
                Console.Write($"{array[i]} ");
            }

            int firstIndex;
            Console.Write("\n\nZadej cislo: ");
            while (!int.TryParse(Console.ReadLine(), out firstIndex) || firstIndex < 0 || firstIndex >= array.Length) ;

            int[] rangeArray = new int[array.Length - firstIndex];
            Array.Copy(array, firstIndex, rangeArray, 0, rangeArray.Length);

            foreach (int i in rangeArray)
            {
                Console.Write($"{i} ");
            }

            Console.ReadKey();
        }
    }
}

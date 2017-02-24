using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication17
{
    class Program
    {
        static void Main(string[] args)
        {
            int system;
            Console.Write("Zadej soustavu (2, 4, 8): ");
            while (!int.TryParse(Console.ReadLine(), out system) || (system != 2 && system != 4 && system != 8)) ;
            
            Console.Write("Zadej cislo v dane soustave: ");
            string number = Console.ReadLine();

            int result = 0;

            for (int i = 0; i < number.Length; i++)
            {
                result += (number[i] - '0') * (int)Math.Pow(system, number.Length - 1 - i);
            }

            Console.Write($"{number} = {result}");
            Console.ReadKey();
        }
    }
}

using System;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            int znamka;

            Console.Write("Zadej znamku: ");
            while (!int.TryParse(Console.ReadLine(), out znamka) || znamka < 1 || znamka > 5) ;

            Console.Write($"{nameof(znamka)} = {znamka}");
            Console.ReadKey();
        }
    }
}

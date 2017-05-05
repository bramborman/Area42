using System;
using System.Diagnostics;

namespace ConsoleApplication37
{
    public static class Program
    {
        public static int Vek { get; set; }
        public static bool JePlnoleta
        {
            get
            {
                return Vek >= 18;
            }
        }

        public static void Main(string[] args)
        {
            int vek;

            do
            {
                Console.CursorVisible = true;

                do
                {
                    Console.Write("Zadej vek: ");
                } while (!int.TryParse(Console.ReadLine(), out vek) || vek < 0);

                Vek = vek;
                Console.CursorVisible = false;

                Console.WriteLine($"Osoba {(JePlnoleta ? "je" : "neni")} plnoleta.");
                Console.WriteLine("Stiskni Escape pro ukonceni programu, nebo cokoli jineho pro opakovani zadani . . .\n");
            } while (Console.ReadKey(true).Key != ConsoleKey.Escape);
        }
    }
}

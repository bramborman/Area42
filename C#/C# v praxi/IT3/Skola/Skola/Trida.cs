using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Skola
{
    class Trida
    {
        public string Nazev { get; set; }
        public string Tridni { get; set; }
        public string Mistnost { get; set; }
        public List<Zak> Zaci { get; set; }

        public Trida()
        {
            Zaci = new List<Zak>();
        }

        public void Vypis()
        {
            Console.WriteLine($"Trida {Nazev}:");
            Console.WriteLine($"Tridni ucitel: {Tridni}");
            Console.WriteLine($"Mistnosti: {Mistnost}");

            foreach (Zak zak in Zaci)
            {
                Console.WriteLine();
                zak.Vypis();
            }
        }

        public static Trida Zadani()
        {
            Trida trida = new Trida();

            Console.Write("Zadej nazev:");
            trida.Nazev = Console.ReadLine();

            Console.Write("Zadej tridniho:");
            trida.Tridni = Console.ReadLine();

            Console.Write("Zadej mistnost:");
            trida.Mistnost = Console.ReadLine();
            
            int i = 1;

            while (i == 1 || Console.ReadKey().Key != ConsoleKey.Escape)
            {
                Console.WriteLine($"\nZadani zaka {i++}");
                trida.Zaci.Add(Zak.Zadani());

                Console.WriteLine();
            }

            return trida;
        }
    }
}

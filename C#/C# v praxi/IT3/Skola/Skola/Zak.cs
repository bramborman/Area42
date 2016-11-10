using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Skola
{
    class Zak
    {
        public string Jmeno { get; set; }
        public string Prijmeni { get; set; }
        public bool JeMuz
        {
            get
            {
                return int.Parse(RodneCislo[2].ToString()) < 5;
            }
        }
        public string RodneCislo { get; set; }
        public DateTime DatumNarozeni
        {
            get
            {
                return new DateTime(int.Parse(RodneCislo.Substring(0, 2)), int.Parse(RodneCislo.Substring(2, 2)) - (!JeMuz ? 50 : 0), int.Parse(RodneCislo.Substring(4, 2)));
            }
        }

        public void Vypis()
        {
            Console.WriteLine($"Zak {Jmeno} {Prijmeni}");
            Console.WriteLine($"Pohlavi: {(JeMuz ? "muz" : "zena")}");
            Console.WriteLine($"Rodne cislo: {RodneCislo}");
            Console.WriteLine($"Datum narozeni: {DatumNarozeni:dd.MM.yy}");
        }

        public static Zak Zadani()
        {
            Zak zak = new Zak();

            Console.Write("Zadej jmeno:");
            zak.Jmeno = Console.ReadLine();

            Console.Write("Zadej prijmeni:");
            zak.Prijmeni = Console.ReadLine();

            Console.Write("Zadej rodne cislo:");
            zak.RodneCislo = Console.ReadLine();

            return zak;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Skola
{
    class Program
    {
        static Random rn = new Random();

        static void Main(string[] args)
        {
            Trida trida = new Trida();

            Console.Write("Zadej název třídy: ");
            trida.Jmeno = Console.ReadLine();
            
            Console.Write("Zadej maximální počet žáků: ");

            try
            {
                trida.MaxKapacita = Convert.ToInt32(Console.ReadLine());
            }
            catch { }

            Console.Write("Zadej umístění třídy: ");
            trida.Umisteni = Console.ReadLine();

            Console.Write("Zadej třídního učitele: ");
            trida.TridniUcitel = ZadaniUcitele();

            Console.Write("\nZadej žáky: ");
            trida.Zaci = new List<Zak>();
            Console.WriteLine();

            for (int i = 0; i < trida.MaxKapacita; i++)
            {
                Zak zak = ZadaniZaka();
                trida.Zaci.Add(zak);
            }

            VypisTridu(trida);
            
            Console.ReadKey();
        }

        private static void VypisTridu(Trida trida)
        {
            double prumer = 0;
            VypisOsobu(trida.TridniUcitel);

            Console.WriteLine("\nTřída {0} s maximálním počtem {1} žáků je ve třídě {2}.", trida.Jmeno, trida.MaxKapacita, trida.Umisteni);

            foreach (Zak zak in trida.Zaci)
            {
                VypisOsobu(zak);
                prumer += zak.Prumer;
            }

            prumer /= trida.Zaci.Count;

            Console.WriteLine("\nPrůměr třídy:{0}", prumer);

            // Nevhodný zápis
            /*for (int i = 0; i < trida.Zaci.Count; i++)
            {
                Console.WriteLine(trida.Zaci[i].Jmeno);
            }*/
        }

        static Ucitel ZadaniUcitele()
        {
            Ucitel osoba = new Ucitel();

            osoba.Jmeno = "František";
            osoba.Prijmeni = "Skalka";
            osoba.JeMuz = true;
            osoba.DatumNarozeni = new DateTime(1970, 1, 1);

            osoba.Kabinet = "Cancer";
            osoba.Titul = "Mgr";
            osoba.Plat = 0.75M;
            
            return osoba;
        }

        static Zak ZadaniZaka()
        {
           
            Zak osoba = new Zak();

            osoba.Jmeno = "Martin";
            osoba.Prijmeni = "Fiša";
            osoba.JeMuz = Convert.ToBoolean(rn.Next(0, 1));
            osoba.DatumNarozeni = new DateTime(rn.Next(1, DateTime.Today.Year - 1), rn.Next(1, DateTime.Today.Month - 1), rn.Next(1, DateTime.Today.Day - 1));

            osoba.Obor = "IT";
            osoba.Prumer = rn.Next(1, 5);
            osoba.Absence = rn.Next(0, 500);

            return osoba;
        }

        static void VypisOsobu(Osoba os)
        {
            Console.WriteLine("Jméno:{0} Příjmení:{1}, Muž:{2}, Datum narození:{3}", os.Jmeno, os.Prijmeni, os.JeMuz.ToString(), os.DatumNarozeni.ToString());

            if (os is Ucitel)
            {
                Ucitel ucitel = os as Ucitel;
                Console.WriteLine("Kabinet:{0}, Titul:{1}, Plat:{2}", ucitel.Kabinet, ucitel.Titul, ucitel.Plat);
            }

            if (os is Zak)
            {
                Zak zak = os as Zak;
                Console.WriteLine("Obor:{0}, Průměr:{1}, Absence:{2}", zak.Obor, zak.Prumer, zak.Absence);
            }
        }
    }
}

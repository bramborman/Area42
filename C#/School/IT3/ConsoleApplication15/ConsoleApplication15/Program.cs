using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication15
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] rodnaCislaStrings = new string[5];

            for (int i = 0; i < rodnaCislaStrings.Length; i++)
            {
                Console.Write("Zadej rodne cislo: ");
                rodnaCislaStrings[i] = Console.ReadLine();
            }

            RodneCislo[] rodnaCisla = new RodneCislo[rodnaCislaStrings.Length];

            for (int i = 0; i < rodnaCislaStrings.Length; i++)
            {
                Console.WriteLine($"Rodne cislo {i} je {(RodneCislo.TryParse(rodnaCislaStrings[i], out rodnaCisla[i]) ? "validni" : "spatne")}");
            }

            Console.ReadKey();
        }
    }

    public enum Pohlavi
    {
        Muz,
        Zena
    }

    public class RodneCislo
    {
        public Pohlavi Pohlavi { get; private set; }
        public DateTime DatumNarozeni { get; private set; }
        public uint KontrolniCislo { get; private set; }

        public static bool TryParse(string value, out RodneCislo rodneCislo)
        {
            rodneCislo = null;

            if (value.Length != 11 && value.Length != 10)
            {
                return false;
            }

            string[] split = value.Split('/');

            if (split.Length != 2 || !split[0].All(ch => char.IsDigit(ch)) || !split[1].All(ch => char.IsDigit(ch)))
            {
                return false;
            }

            bool isFemale = split[0][2] == '5' || split[0][2] == '6';

            if (isFemale)
            {
                char originalChar = split[0][2];
                split[0] = split[0].Remove(2, 1).Insert(2, originalChar == '5' ? "0" : "1");
            }

            DateTime datumNarozeni = new DateTime(int.Parse($"19{split[0].Substring(0, 2)}"), int.Parse(split[0].Substring(2, 2)), int.Parse(split[0].Substring(4, 2)));

            long fullNumber;
            uint kontrolniCislo;

            if (!uint.TryParse(split[1], out kontrolniCislo) || !long.TryParse($"{split[0]}{split[1]}", out fullNumber) || fullNumber % 11 != 0)
            {
                return false;
            }

            rodneCislo = new RodneCislo
            {
                DatumNarozeni   = datumNarozeni,
                KontrolniCislo  = kontrolniCislo,
                Pohlavi         = isFemale ? Pohlavi.Zena : Pohlavi.Muz
            };

            return true;
        }
    }
}

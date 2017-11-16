using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApplication30
{
    class Program
    {
        static void Main(string[] args)
        {
            const int ITERATIONS = 3;

            List<KeyValuePair<string, RodneCislo>> lide = new List<KeyValuePair<string, RodneCislo>>();

            for (int i = 0; i < ITERATIONS; i++)
            {
                string jmeno;

                do
                {
                    Console.Write("Zadej jmeno: ");
                    jmeno = Console.ReadLine();
                } while (string.IsNullOrWhiteSpace(jmeno));

                RodneCislo rodneCislo;

                do
                {
                    Console.Write("Zadej rodne cislo: ");
                } while (!RodneCislo.TryParse(Console.ReadLine(), out rodneCislo));

                lide.Add(new KeyValuePair<string, RodneCislo>(jmeno, rodneCislo));
            }

            Console.WriteLine();
            lide = lide.OrderBy(k => k.Value.DatumNarozeni).ToList();

            for (int i = 0; i < ITERATIONS; i++)
            {
                KeyValuePair<string, RodneCislo> clovek = lide[i];
                Console.WriteLine($"{(i + 1)}: {clovek.Key}\t\t{clovek.Value.DatumNarozeni:dd.MM.yyyy}");
            }

            Console.ReadKey();
        }
    }

    public enum Pohlavi
    {
        Muz,
        Zena
    }

    public sealed class RodneCislo
    {
        public Pohlavi Pohlavi { get; private set; }
        public DateTime DatumNarozeni { get; private set; }
        public uint KontrolniCislo { get; private set; }
        public string RodneCisloString { get; private set; }

        public static bool TryParse(string value, out RodneCislo rodneCislo)
        {
            rodneCislo = null;
            value = value.Trim();

            if (value.Length != 11 && value.Length != 10)
            {
                return false;
            }

            string[] split = value.Split('/');

            if (split.Length != 2 || !split.All(s => s.All(ch => char.IsDigit(ch))))
            {
                return false;
            }

            int year    = int.Parse(split[0].Substring(0, 2));
            int month   = int.Parse(split[0].Substring(2, 2));
            int day     = int.Parse(split[0].Substring(4, 2));

            if (day == 0 || day > 31)
            {
                return false;
            }

            bool isFemale = split[0][2] == '5' || split[0][2] == '6';

            if (isFemale)
            {
                month -= 50;
            }

            if (month > 12)
            {
                return false;
            }

            DateTime datumNarozeni;
            
            bool _2000 = split[1].Length == 4 && year < 54;
            year += _2000 ? 2000 : 1900;

            if (!DateTime.TryParse($"{day}/{month}/{year}", out datumNarozeni))
            {
                return false;
            }
            
            long fullNumber;
            uint kontrolniCislo;

            if ((!uint.TryParse(split[1], out kontrolniCislo) || !long.TryParse($"{split[0]}{split[1]}", out fullNumber) || fullNumber % 11 != 0) && year >= 1954)
            {
                return false;
            }

            rodneCislo = new RodneCislo
            {
                DatumNarozeni       = datumNarozeni,
                KontrolniCislo      = kontrolniCislo,
                Pohlavi             = isFemale ? Pohlavi.Zena : Pohlavi.Muz,
                RodneCisloString    = value
            };

            return true;
        }
    }
}

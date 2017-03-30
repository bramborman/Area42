using System;
using System.Collections.Generic;

namespace OOP_DopravniProstredky
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Lod lodQueenElizabeth = new Lod
            {
                Nazev       = "MS Queen Elizabeth",
                Ponor       = 8,
                RychlostKmH = 43,
                Vytlak      = 90.901f
            };
            
            Console.WriteLine($"{lodQueenElizabeth.Nazev} rekou {(lodQueenElizabeth.Propluje(15) ? "" : "ne")}propluje.\n");

            Kamion kamionMercedes = new Kamion
            {
                Nazev               = "Mercedes Actros 460",
                PocetNaprav         = 3,
                RychlostKmH         = 90,
                HmotnostKg          = 2000,
                SpotrebaNa100Km     = 20f
            };
            
            OsobniAuto autoSkoda = new OsobniAuto
            {
                Nazev                       = "Skoda Rapid",
                RychlostKmH                 = 189,
                ObjemZavazadlovehoProstoru  = 300,
                HmotnostKg                  = 110,
                SpotrebaNa100Km             = 7f
            };

            PorovnejVahu(kamionMercedes, autoSkoda);

            Zvire kun = new Zvire
            {
                Nazev       = "Kun",
                HmotnostKg  = 500,
                Bylozravec  = true,
                Zradlo      = "oves"
            };
            
            PorovnejVahu(kamionMercedes, kun);

            Console.WriteLine();
            kamionMercedes.VypisSpotrebu(150);
            autoSkoda.VypisSpotrebu(150);


            Console.ReadKey();
        }

        private static void PorovnejVahu(DopravniProstredek dp1, DopravniProstredek dp2)
        {
            DopravniProstredek tezsi = dp1.HmotnostKg > dp2.HmotnostKg ? dp1 : dp2;
            DopravniProstredek lehci = ReferenceEquals(tezsi, dp1) ? dp2 : dp1;

            Console.WriteLine($"{tezsi.Nazev} je tezsi nez {dp2.Nazev}.");
        }

        private static void VypisSpotrebu<T>(this T motoroveVozidlo, float pocetKm) where T : DopravniProstredek, IMotoroveVozidlo
        {
            Console.WriteLine($"{motoroveVozidlo.Nazev} na {pocetKm}km spotrebuje {motoroveVozidlo.VypocitejSpotrebu(pocetKm):F2} litru paliva.");
        }

        private static float VypocitejSpotrebu(this IMotoroveVozidlo motoroveVozidlo, float pocetKm)
        {
            return (pocetKm / 100f) * motoroveVozidlo.SpotrebaNa100Km;
        }
    }
}

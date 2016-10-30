using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Objekty
{
    class Auto
    {
        const float GALON_NA_LITR = 3.785f;

        public bool karburator;
        public int pocetKol;
        public string barva;
        public int pocetSedadel;
        public float spotrebaLitruNa100km;
        /*private*/ float spotrebaGalonuNa100km;
        public bool rizeniNaPraveStrane;

        public Auto(bool p_rizeniNaPraveStrane)
        {
            barva = "---";
            pocetKol = 4;
            rizeniNaPraveStrane = p_rizeniNaPraveStrane;
        }

        public float GetPocetGalonuNa100()
        {
            spotrebaGalonuNa100km = spotrebaLitruNa100km / GALON_NA_LITR;
            return spotrebaGalonuNa100km;
        }

        public float GetSpotrebaNaLidi(int pocetLidi)
        {
            return spotrebaLitruNa100km / pocetLidi;
        }

        public float GetCena(int pocetKm)
        {
            return pocetKm * 30;
        }
    }
}

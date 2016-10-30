using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Skola
{
    // Abstract - nelze vytvořit instanci abstraktní třídy
    public abstract class Osoba
    {
        public string Jmeno { get; set; }

        public string Prijmeni { get; set; }

        public bool JeMuz { get; set; }

        public DateTime DatumNarozeni { get; set; }

        // Private - přístupný jen uvnitř třídy
        private int Vek { get; set; }

        // Protected - přístupný jen z dědiců
        protected int Vyska { get; set; }


    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Skola
{
    public class Trida
    {
        public string Jmeno { get; set; }

        public int MaxKapacita { get; set; }

        public string Umisteni { get; set; }

        public Ucitel TridniUcitel { get; set; }

        //public Osoba[] Zaci { get; set; }

        public List<Zak> Zaci { get; set; }
    }
}

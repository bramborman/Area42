using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Skola
{
    public class Ucitel : Osoba
    {
        public string Kabinet { get; set; }

        public string Titul { get; set; }

        public decimal Plat { get; set; }
    }
}

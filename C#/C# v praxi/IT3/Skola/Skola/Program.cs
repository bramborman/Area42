using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Skola
{
    class Program
    {
        static void Main(string[] args)
        {
            Trida it3 = Trida.Zadani();

            Console.WriteLine();

            it3.Vypis();
            Console.ReadKey();
        }
    }
}

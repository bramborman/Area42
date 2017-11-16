using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication25
{
    class me
    {
        public void mes(ushort dec, out string hex)
        {
            hex = dec.ToString("X");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ushort dec;
            string hex;
            me me = new me();

            do
            {
                Console.Write("Zadej cislo: ");
            } while (!ushort.TryParse(Console.ReadLine(), out dec));

            me.mes(dec, out hex);
            Console.Write($"{dec}'d == {hex}'h");
            Console.ReadKey();
        }
    }
}

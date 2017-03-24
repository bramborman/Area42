using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication26
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Lol(1);
            Lol(1, 1);
            Lol(1, 1, 1);
            Lol(1, 1, 1, 1);

            Console.ReadKey();
        }

        private static void Lol(int a)
        {
            Lol(a, 0);
        }

        private static void Lol(int a, int b)
        {
            Lol(a, b, 0);
        }

        private static void Lol(int a, int b, int c)
        {
            Lol(a, b, c, 0);
        }

        private static void Lol(int a, int b, int c, int d)
        {
            Console.WriteLine($"{a} + {b} + {c} + {d} = {a + b + c + d}");
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication24
{
    class me
    {
        public void _irl(string str, ref int a, ref int e, ref int i, ref int o, ref int u, ref int y)
        {
            foreach (char ch in str.ToLower())
            {
                switch (ch)
                {
                    case 'a': a++; break;
                    case 'e': e++; break;
                    case 'i': i++; break;
                    case 'o': o++; break;
                    case 'u': u++; break;
                    case 'y': y++; break;
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int a = 0;
            int e = 0;
            int i = 0;
            int o = 0;
            int u = 0;
            int y = 0;

            me me = new me();
            me._irl(Console.ReadLine(), ref a, ref e, ref i, ref o, ref u, ref y);

            Console.Write($"a: {a}\ne: {e}\ni: {i}\no: {o}\nu: {u}\ny: {y}");
            Console.ReadKey();
        }
    }
}

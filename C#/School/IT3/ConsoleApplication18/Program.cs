using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication18
{
    class Foo
    {
        public void WriteBar(string format, params object[] args)
        {
            Console.WriteLine(format, args);
        }

        public string ReadBar()
        {
            return Console.ReadLine();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Foo foo = new Foo();
            foo.WriteBar("{0} {1} {2}", 1, 2, "Fiša");
            foo.ReadBar();
        }
    }
}

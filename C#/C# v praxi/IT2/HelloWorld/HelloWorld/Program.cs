using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
            float why = 0.5f;
            string fisa;

            System.Console.WriteLine("Dnes je {0} a je {1} hodin", System.DateTime.Now.DayOfWeek, System.DateTime.Now.TimeOfDay);
            Console.WriteLine("Dnes je " + DateTime.Now.DayOfWeek + " a je " + DateTime.Now.TimeOfDay + " hodin");
            Console.WriteLine();

            Console.Write("Zadej jméno: ");
            fisa = Console.ReadLine();
            Console.WriteLine((fisa == "fiša" || fisa == "veverková" ? "{0} není frajer" : "{0} je frajer"), fisa);

            Console.WriteLine();
            Console.Write("Zadej libovolné slovo: ");
            Console.WriteLine("{0}", Console.ReadLine());
            
            Console.WriteLine();
            Console.Write("Zadej libovolné číslo: ");
            float.TryParse(Console.ReadLine(), out why);
            Console.WriteLine("{0}", why);

            Console.ReadLine();
        }
    }
}

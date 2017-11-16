using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApplication2
{

    class Program
    {
        static string space = new string('_', (Console.WindowWidth - @"/\\\\\\\\\\\\\____/\\\\____________/\\\\__/\\\\\\\\\\\_______".Length) / 2);

        static void Main(string[] args)
        {
            Console.CursorVisible = false;
            Console.CursorTop = (Console.WindowHeight - 9) / 2;

            WriteLogo(@"/\\\\\\\\\\\\\____/\\\\____________/\\\\__/\\\\\\\\\\\_______");
            WriteLogo(@"\/\\\/////////\\\_\/\\\\\\________/\\\\\\_\/////\\\///_______");
            WriteLogo(@"_\/\\\_______\/\\\_\/\\\//\\\____/\\\//\\\_____\/\\\_________");
            WriteLogo(@"__\/\\\\\\\\\\\\\\__\/\\\\///\\\/\\\/_\/\\\_____\/\\\________");
            WriteLogo(@"___\/\\\/////////\\\_\/\\\__\///\\\/___\/\\\_____\/\\\_______");
            WriteLogo(@"____\/\\\_______\/\\\_\/\\\____\///_____\/\\\_____\/\\\______");
            WriteLogo(@"_____\/\\\_______\/\\\_\/\\\_____________\/\\\_____\/\\\_____");
            WriteLogo(@"______\/\\\\\\\\\\\\\/__\/\\\_____________\/\\\__/\\\\\\\\\\\");
            WriteLogo(@"_______\/////////////____\///______________\///__\///////////");

            Thread.Sleep(3000);
            Console.Clear();
            Console.CursorVisible = true;

            double mass, height, bmi;

            Console.Write("Zadejte svoji vahu v kg: ");
            while (!double.TryParse(Console.ReadLine(), out mass)) ;

            Console.Write("Zadejte svoji vysku v cm: ");
            while (!double.TryParse(Console.ReadLine(), out height)) ;

            height /= 100;
            bmi = mass / (height * height);

            Console.WriteLine($"Z Vaseho BMI ({bmi:F2}) vypliva, ze mate {(bmi < 20 ? "podvahu" : (bmi < 25 ? "idealni hmotnost" : (bmi < 30 ? "mirnou nadvahu" : (bmi < 40 ? "obezitu" : "tezkou obezitu"))))}.");
            Console.ReadKey();
        }

        static void WriteLogo(string line)
        {
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write(space);

            foreach (char ch in line)
            {
                Console.ForegroundColor = ch == '_' ? ConsoleColor.White : ConsoleColor.Yellow;
                Console.Write(ch);
            }

            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine(space);
            Thread.Sleep(100);
        }
    }
}

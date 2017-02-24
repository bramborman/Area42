using System;
using System.Text;

namespace ConsoleApplication20
{
    public sealed class Whyy
    {
        private char op;
        private double x, y, result;

        public void Vypocet(double x, double y, char op)
        {
            this.x  = x;
            this.y  = y;
            this.op = op;

            switch (op)
            {
                case '+':
                    result = x + y;
                    break;

                case '-':
                    result = x - y;
                    break;

                case '*':
                case '•':
                case 'x':
                    result = x * y;
                    break;

                case '/':
                case ':':
                    result = x / y;
                    break;
            }

            Vypis();
        }
        
        private void Vypis()
        {
            Console.Write($"{x} ");

            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write(op);
            Console.ForegroundColor = ConsoleColor.White;

            Console.Write($" {y} = {result:F2}");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding  = Encoding.Unicode;
            Console.InputEncoding   = Encoding.Unicode;
            Console.ForegroundColor = ConsoleColor.White;

            char op;
            double x, y;
            
            do
            {
                Console.Write("Zadej 1. cislo: ");
            } while (!double.TryParse(Console.ReadLine(), out x)) ;

            Console.ForegroundColor = ConsoleColor.Yellow;

            do
            {
                Console.Write("Zadej operator: ");
            } while (!char.TryParse(Console.ReadLine(), out op) && op != '+' && op != '-' && op != '*' && op != '•' && op != 'x' && op != '/' && op != ':');

            Console.ForegroundColor = ConsoleColor.White;

            do
            {
                Console.Write("Zadej 2. cislo: ");
            } while (!double.TryParse(Console.ReadLine(), out y) || ((op == '/' || op == ':') && y == 0));

            new Whyy().Vypocet(x, y, op);
            Console.ReadKey();
        }
    }
}

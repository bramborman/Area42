using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kalkulacka
{
    class Program
    {
        static void Main(string[] args)
        {

            bool isValid;
            double x = 0, y = 0, result = 0;
            char operation;

            while (true)
            {
                Console.Write("Zadej prvni cislo: ");
                isValid = Double.TryParse(Console.ReadLine(), out x);

                if (!isValid)
                {
                    Console.WriteLine("Nezadal jsi cislo!!!");
                    Console.Read();
                    return;
                }

                Console.Write("Zadej operaci: ");
                isValid = Char.TryParse(Console.ReadLine(), out operation);

                if (!isValid && operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != 'x' && operation != ':' && operation != '!' && operation != 'p')
                {
                    Console.WriteLine("Nezadal jsi spravnou operaci!!!");
                    Console.Read();
                    return;
                }

                if(operation != '!' && operation != 'p')
                {
                    Console.Write("Zadej druhe cislo: ");
                    isValid = Double.TryParse(Console.ReadLine(), out y);

                    if (!isValid)
                    {
                        Console.WriteLine("Nezadal jsi cislo!!!");
                        Console.Read();
                        return;
                    }
                }

                if (operation == '+') result = x + y;
                else if (operation == '-') result = x - y;
                else if (operation == '*' || operation == 'x') result = x * y;
                else if (y != 0 && (operation == '/' || operation == ':')) result = x / y;
                else if (operation == '!')
                {
                    for(int i = 1; i <= x; i++)
                    {
                        result += (double)i;
                    }

                    Console.WriteLine("{0} {1} = {2}\n", x, operation, result);
                    continue;
                }
                else if (operation == 'p')
                {
                    for (int i = 2; i <= x; i++)
                    {
                        for (int j = 1; j < i; j++)
                        {
                            if(i % j == 0 && j != 1)
                            {
                                break;
                            }

                            if(j == i - 1)
                            {
                                Console.Write("{0} ", i);
                            }
                        }
                    }

                    Console.WriteLine("\n");
                    continue;
                }

                if ((operation == '/' || operation == ':') && y == 0)
                {
                    Console.WriteLine("Nulou nelze delit!!!");
                    Console.Read();
                    return;
                }

                Console.WriteLine("{0} {1} {2} = {3}\n", x, operation, y, result);
            }
        }
    }
}

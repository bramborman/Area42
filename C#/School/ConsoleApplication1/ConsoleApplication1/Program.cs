using System;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine();
            Console.CursorLeft = Console.WindowWidth / 2 - 5;
            Console.WriteLine("CALCULATOR");

            while (true)
            {
                char op = '\0';
                double x, y;
                double? result = null;

                Console.Write("\n1st number: ");
                while (!double.TryParse(Console.ReadLine(), out x)) ;

                Console.Write("Operator: ");
                while (!char.TryParse(Console.ReadLine(), out op)) ;

                Console.Write("2nd number: ");
                while (!double.TryParse(Console.ReadLine(), out y)) ;

                switch (op)
                {
                    case '+': result = x + y; break;
                    case '-': result = x - y; break;
                    case '*':
                    case 'x': result = x * y; break;
                    case '/':
                    case ':':
                        if (y != 0)
                        {
                            result = x / y;
                        }

                        break;
                }

                Console.WriteLine(result != null ? $"{x} {op} {y} = {result:F2}" : "Cannot divide by zero!");
                Console.ReadKey();
            }
        }
    }
}

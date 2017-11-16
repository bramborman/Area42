using System;
using System.Linq;

namespace ConsoleApplication27
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Console.Write("Zadej text: ");
            string input = Console.ReadLine();

            Console.Clear();

            int number;

            if (int.TryParse(input, out number))
            {
                Write(number);
            }
            else if (input.All(ch => char.IsUpper(ch)))
            {
                int foregroundColor;

                do
                {
                    Console.Write("Zadej barvu nadpisu: ");
                } while (!int.TryParse(Console.ReadLine(), out foregroundColor) || foregroundColor < 1 || foregroundColor > 15);

                Console.Clear();

                Write(input, (ConsoleColor)foregroundColor);
            }
            else
            {
                Write(input);
            }

            Console.ReadKey();
        }

        private static void Write(int number)
        {
            string numberString = number.ToString();

            Console.ForegroundColor = ConsoleColor.Magenta;
            Console.SetCursorPosition((Console.WindowWidth - numberString.Length) / 2, Console.WindowHeight - 1);
            Console.Write(numberString);
        }

        private static void Write(string text)
        {
            Console.CursorTop = Console.WindowHeight / 2;
            Console.Write(text);
        }

        private static void Write(string text, ConsoleColor foregroundColor)
        {
            Console.ForegroundColor = foregroundColor;
            Console.SetCursorPosition((Console.WindowWidth - text.Length) / 2, Console.WindowHeight / 2);
            Console.Write(text);
        }
    }
}

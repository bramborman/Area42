using System;
using static System.Console;

namespace Faktorial
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            const string RESTART_MESSAGE = "Press Escape to quit or anything else to start again . . .";
            string messageRemover = new string(' ', RESTART_MESSAGE.Length);

            ConsoleKey? pressedKey = null;
            int number;

            while (pressedKey != ConsoleKey.Escape)
            {
                CursorVisible = true;

                do
                {
                    Write("Enter a number greater or equal 0: ");
                } while (!int.TryParse(ReadLine(), out number) || number < 0);

                CursorVisible = false;
                int result = 1;

                for (int i = number; i > 0; i--)
                {
                    result *= i;
                }

                WriteLine($"{number}! = {result}");

                Write(RESTART_MESSAGE);

                pressedKey = ReadKey(true).Key;
                Write("\r" + messageRemover + "\n");
            }
        }
    }
}

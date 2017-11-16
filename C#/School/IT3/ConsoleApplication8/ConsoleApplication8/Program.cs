using System;

namespace ConsoleApplication8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.CursorVisible = false;

            string name = LoadName();

            Console.CursorTop  = (Console.WindowHeight / 2) - 1;
            Console.CursorLeft = (Console.WindowWidth - name.Length) / 2;

            Console.Write(name);
            Console.ReadKey();
        }

        static string LoadName()
        {
            Console.Write("Say my name: ");
            return Console.ReadLine();
        }
    }
}

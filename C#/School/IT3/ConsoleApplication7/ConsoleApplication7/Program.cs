using System;

namespace ConsoleApplication7
{
    class Program
    {
        static void Main(string[] args)
        {
            string password = "";

            for (int i = 0; i < 4; i++)
            {
                password += Console.ReadKey(true).KeyChar.ToString();
                Console.Write("*");
            }

            Console.Write($"\n{password}");
            Console.ReadKey();
        }
    }
}

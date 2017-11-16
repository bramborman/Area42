using System;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Zadej text: ");
            string text = Console.ReadLine().ToLower();

            foreach (char ch in text)
            {
                int encrypted = ch + 2;

                if (encrypted > 'z')
                {
                    encrypted -= 'z' - 'a' + 1;
                }

                Console.Write((char)encrypted);
            }

            Console.ReadKey();
        }
    }
}

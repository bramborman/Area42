using System;

namespace ConsoleApplication6
{
    class Program
    {
        static void Main(string[] args)
        {
            const string WORD = "ahoj";

            bool right;
            char ch;
            string encrypted = new string('?', WORD.Length);
            int attempts = 3;

            Console.CursorVisible = false;

            while (encrypted != WORD && attempts > 0)
            {
                Console.Clear();
                Console.WriteLine(encrypted);
                Console.Write("Hadej pismeno: ");
                
                while (!char.TryParse(Console.ReadLine(), out ch)) ;
                ch = char.ToLower(ch);

                right = false;

                for (int i = 0; i < encrypted.Length; i++)
                {
                    if (ch == WORD[i])
                    {
                        encrypted = encrypted.Insert(i, ch.ToString()).Remove(i + 1, 1);
                        right = true;
                    }
                }

                if (!right)
                {
                    attempts--;
                }
            }

            Console.Clear();

            if (encrypted == WORD)
            {
                Console.WriteLine("Vyhral jsi!!!");
            }
            else
            {
                Console.WriteLine("Prohral jsi!!!");
            }

            Console.Write($"\nHadane slovo bylo {WORD}");

            Console.ReadKey();
        }
    }
}

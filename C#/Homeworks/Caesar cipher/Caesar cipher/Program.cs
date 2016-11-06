using System;

namespace CaesarCipher
{
    class Program
    {
        static void Main(string[] args)
        {
            const int ALPHABET_COUNT = 'z' - 'a' + 1;
            const int DIGITS_COUNT   = '9' - '0' + 1;

            Console.Title = "Caesar cipher";

            while (true)
            {
                int offset;

                Console.Write("Enter any text: ");
                string text = Console.ReadLine();

                Console.Write("Enter an offset: ");
                while (!int.TryParse(Console.ReadLine(), out offset)) ;

                foreach (char ch in text)
                {
                    int encrypted = ch;

                    if (char.IsLetter(ch))
                    {
                        encrypted = ch + (offset % ALPHABET_COUNT);

                        if (char.IsLower(ch))
                        {
                            if (encrypted < 'a')
                            {
                                encrypted += ALPHABET_COUNT;
                            }
                            else if (encrypted > 'z')
                            {
                                encrypted -= ALPHABET_COUNT;
                            }
                        }
                        else
                        {
                            if (encrypted < 'A')
                            {
                                encrypted += ALPHABET_COUNT;
                            }
                            else if (encrypted > 'Z')
                            {
                                encrypted -= ALPHABET_COUNT;
                            }
                        }
                    }
                    else if (char.IsDigit(ch))
                    {
                        encrypted = ch + (offset % DIGITS_COUNT);

                        if (encrypted < '0')
                        {
                            encrypted += DIGITS_COUNT;
                        }
                        else if (encrypted > '9')
                        {
                            encrypted -= DIGITS_COUNT;
                        }
                    }

                    Console.Write((char)encrypted);
                }

                Console.Write("\n\n");
            }
        }
    }
}

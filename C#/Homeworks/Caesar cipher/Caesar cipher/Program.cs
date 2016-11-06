using System;

namespace CaesarCipher
{
    class Program
    {
        static void Main(string[] args)
        {
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
                    int encrypted;

                    if (ch == ' ')
                    {
                        encrypted = ch;
                    }
                    else
                    {
                        encrypted = ch + (offset % ('z' - 'a' + 1));

                        if (!char.IsUpper((char)encrypted))
                        {
                            if (encrypted < 'a')
                            {
                                encrypted += 'z' - 'a' + 1;
                            }
                            else if (encrypted > 'z')
                            {
                                encrypted -= 'z' - 'a' + 1;
                            }
                        }
                        else
                        {
                            if (encrypted < 'A')
                            {
                                encrypted += 'Z' - 'A' + 1;
                            }
                            else if (encrypted > 'Z')
                            {
                                encrypted -= 'Z' - 'A' + 1;
                            }
                        }
                    }

                    Console.Write((char)encrypted);
                }

                Console.Write("\n\n");
            }
        }
    }
}

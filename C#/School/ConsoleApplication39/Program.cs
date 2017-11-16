using System;
using System.Linq;

namespace ConsoleApplication39
{
    public static class Program
    {
        private static string _binaryNumber;

        public static string BinaryNumber
        {
            get { return _binaryNumber; }
            set
            {
                if (_binaryNumber != value)
                {
                    if (string.IsNullOrWhiteSpace(value) || !value.All(ch => ch == '0' || ch == '1') || value.Length > 8)
                    {
                        throw new ArgumentException(nameof(BinaryNumber));
                    }

                    _binaryNumber = value;
                }
            }
        }

        public static void Main(string[] args)
        {
            while (true)
            {
                try
                {
                    Console.Write("Zadej binarni cislo, max 1B: ");
                    BinaryNumber = Console.ReadLine();
                    break;
                }
                catch (ArgumentException)
                {
                    continue;
                }
            }

            Console.Write(Convert.ToInt32(BinaryNumber, 2));
            Console.ReadKey();
        }
    }
}

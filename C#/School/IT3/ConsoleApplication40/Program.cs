using static System.Console;

namespace ConsoleApplication40
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            PasswordProgram.Run();
        }
    }

    public static class PasswordProgram
    {
        private static bool firstPasswordLength;
        private static string _firstPassword;
        private static string _secondPassword;

        private static string FirstPassword
        {
            get { return _firstPassword; }
            set
            {
                if (value.Length < 6)
                {
                    firstPasswordLength = false;
                }
                else if (value.Length > 12)
                {
                    firstPasswordLength = true;
                }
                else
                {
                    _firstPassword = value;
                }
            }
        }
        private static string SecondPassword
        {
            get { return _secondPassword; }
            set
            {
                if (value == FirstPassword)
                {
                    _secondPassword = value;
                }
            }
        }

        public static void Run()
        {
            while (true)
            {
                Write("Zadej heslo <6-12>: ");
                FirstPassword = ReadLine();

                if (FirstPassword == null)
                {
                    WriteLine($"Heslo je prilis {(firstPasswordLength ? "dlouhe" : "kratke")}!");
                }
                else
                {
                    break;
                }
            }

            do
            {
                Write("Potvrd heslo: ");
                SecondPassword = ReadLine();
            } while (SecondPassword == null);

            Write("!!! PRISTUP POVOLEN !!!");
            ReadKey();
        }
    }
}

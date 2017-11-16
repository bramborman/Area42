using System;

namespace ConsoleApplication19
{
    class MlgDrawer
    {
        public void Draw()
        {
            Console.Write('*');
            Useless();
        }

        private void Useless()
        {
            Console.Write("**");
        }

        public static explicit operator string(MlgDrawer m)
        {
            return "***";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int x, y;
            
            do
            {
                Console.Write("Zadej x: ");
            } while (!int.TryParse(Console.ReadLine(), out x) || x < 0 || x > Console.WindowWidth - 3) ;
            
            do
            {
                Console.Write("Zadej y: ");
            } while (!int.TryParse(Console.ReadLine(), out y) || y < 0 || y > Console.WindowHeight - 3) ;

            Console.Clear();
            MlgDrawer mlgDrawer = new MlgDrawer();

            for (int i = 0; i < 3; i++)
            {
                Console.SetCursorPosition(x, y + i);
                mlgDrawer.Draw();
            }

            Console.ReadKey();
        }
    }
}

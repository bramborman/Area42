using System;
using System.Threading;

namespace ConsoleApplication22
{
    public struct Pony
    {
        public int X { get; set; }
        public int Y { get; set; }

        public void Add()
        {
            Console.SetCursorPosition(X, Y);
            Console.Write('#');
        }

        public void Remove()
        {
            Console.SetCursorPosition(X, Y);
            Console.Write(' ');
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int count;

            Console.Write("Zadej cislo 1 - 100: ");
            while (!int.TryParse(Console.ReadLine(), out count) || count < 1 || count > 100) ;
            Console.Clear();

            bool deleting = false;
            int index = 0;
            Pony[] ponies = new Pony[count + 1];

            Console.CursorVisible = false;
            
            Random random = new Random();

            while (!Console.KeyAvailable || Console.ReadKey(true).Key != ConsoleKey.Escape)
            {
                ponies[index].X = random.Next(0, Console.WindowWidth - 1);
                ponies[index].Y = random.Next(0, Console.WindowHeight - 1);

                ponies[index].Add();
                
                if (index == ponies.Length - 1)
                {
                    deleting = true;
                }

                if (deleting)
                {
                    int customIndex = index == ponies.Length - 1 ? 0 : index + 1;
                    ponies[customIndex].Remove();
                }

                if (++index == ponies.Length)
                {
                    index = 0;
                }

                Thread.Sleep(10);
            }
        }
    }
}

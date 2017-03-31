using System;
using System.Collections.Generic;
using System.Threading;

namespace ConsoleApplication22
{
    public struct Pony
    {
        public int X { get; set; }
        public int Y { get; set; }

        public void Draw()
        {
            Console.SetCursorPosition(X, Y);
            Console.Write('#');
        }

        public void Clear()
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

            do
            {
                Console.Write("Zadej cislo 10 - 100: ");
            } while (!int.TryParse(Console.ReadLine(), out count) || count < 10 || count > 100);

            Console.Clear();
            
            Random random      = new Random();
            Queue<Pony> ponies = new Queue<Pony>(count);

            Console.CursorVisible = false;
            
            while (!Console.KeyAvailable || Console.ReadKey(true).Key != ConsoleKey.Escape)
            {
                Pony pony = new Pony
                {
                    X = random.Next(0, Console.WindowWidth - 1),
                    Y = random.Next(0, Console.WindowHeight - 1)
                };

                pony.Draw();
                ponies.Enqueue(pony);
                
                if (ponies.Count == count)
                {
                    ponies.Dequeue().Clear();
                }

                Thread.Sleep(10);
            }
        }
    }
}

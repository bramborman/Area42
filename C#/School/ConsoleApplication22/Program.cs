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
                Console.Write("Zadej cislo 1 - 100: ");
            } while (!int.TryParse(Console.ReadLine(), out count) || count < 1 || count > 100);

            Console.Clear();
            
            int poniesCapacity = count + 1;
            Random random      = new Random();
            Queue<Pony> ponies = new Queue<Pony>(poniesCapacity);

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
                
                if (ponies.Count == poniesCapacity - 1)
                {
                    ponies.Dequeue().Clear();
                }

                Thread.Sleep(10);
            }
        }
    }
}

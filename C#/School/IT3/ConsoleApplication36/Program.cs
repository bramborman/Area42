using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace ConsoleApplication36
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            FontHelper.SetFont("Terminal", 8, 8);

            Console.Title           = "Random game";
            Console.CursorVisible   = false;
            Console.SetWindowSize(18, 36);
            Console.SetBufferSize(18, 36);
            
            bool isAlive            = true;
            int meters              = 0;
            int sleep               = 100;
            List<DangerLol> dangers = new List<DangerLol>();
            Player player           = new Player(dangers);

            while (isAlive)
            {
                if (meters++ >= Console.WindowHeight - 15 && meters <= Console.WindowHeight - 10)
                {
                    sleep += 80;
                }

                dangers.Add(new DangerLol());
                isAlive = player.Render();

                foreach (DangerLol danger in dangers.ToList())
                {
                    if (!danger.Render())
                    {
                        dangers.Remove(danger);
                    }
                }

                Console.SetCursorPosition(0, Console.WindowHeight - 1);
                Console.ForegroundColor = ConsoleColor.Gray;
                Console.Write($"YOU DROVE {meters}m");

                Thread.Sleep(sleep);
            }

            Console.Clear();

            Console.ForegroundColor = ConsoleColor.Cyan;

            string[] messages = { $"THE END :-(", $"U drove {meters}m" };

            for (int i = 0; i < messages.Length; i++)
            {
                Console.SetCursorPosition((Console.WindowWidth - messages[i].Length) / 2, (Console.WindowHeight - (messages.Length / 2) - i) / 2);
                Console.WriteLine(messages[i]);
            }

            Console.ReadKey();
        }
    }

    public abstract class Whatever
    {
        private const char CHAR = 'O';

        protected static readonly Random random = new Random();

        public char Char { get; }
        public ConsoleColor Color { get; protected set; }
        public int X { get; protected set; }
        public int Y { get; protected set; }

        protected Whatever(char @char, ConsoleColor color)
        {
            Char    = @char;
            Color   = color;
        }

        public virtual bool Render()
        {
            Console.SetCursorPosition(X, Y);
            Console.ForegroundColor = Color;
            Console.Write(Char);

            return true;
        }

        protected void Delete()
        {
            Console.SetCursorPosition(X, Y);
            Console.Write(' ');
        }
    }

    public sealed class DangerLol : Whatever
    {
        public DangerLol() : base('O', ConsoleColor.Red)
        {
            X = random.Next(0, Console.WindowWidth - 1);
        }

        public override bool Render()
        {
            Delete();

            if (++Y == Console.WindowHeight - 1)
            {
                return false;
            }

            return base.Render();
        }
    }

    public sealed class Player : Whatever
    {
        public bool GoRight { get; private set; }
        public IEnumerable<DangerLol> Dangers { get; }

        public Player(IEnumerable<DangerLol> dangers) : base('^', ConsoleColor.Yellow)
        {
            X       = Console.WindowWidth / 2;
            Y       = Console.WindowHeight - 2;
            Dangers = dangers;
        }

        public override bool Render()
        {
            Delete();

            if (Console.KeyAvailable)
            {
                ConsoleKey pressedKey = Console.ReadKey(true).Key;

                if (pressedKey == ConsoleKey.LeftArrow)
                {
                    X--;
                    GoRight = false;
                }
                else if (pressedKey == ConsoleKey.RightArrow)
                {
                    X++;
                    GoRight = true;
                }
            }

            // if (GoRight)
            // {
            //     X++;
            // }
            // else
            // {
            //     X--;
            // }

            if (Dangers.Any(d => d.X == X && d.Y == Y) || X < 1 || X > Console.WindowWidth - 2)
            {
                return false;
            }

            return base.Render();
        }
    }
}

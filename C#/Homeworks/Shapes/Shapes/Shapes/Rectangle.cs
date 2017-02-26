using System;

namespace Shapes.Shapes
{
    public sealed class Rectangle : ShapeBase
    {
        public bool IsSquare { get; }

        public Rectangle(bool isSquare) : base(new Side("a", 2, isSquare ? Math.Min(MaxWidth, MaxHeight) : MaxWidth), isSquare ? null : new Side("b", 2, MaxHeight))
        {
            IsSquare = isSquare;
        }

        protected override void Draw()
        {
            int sideA   = Sides[0].Size;
            int sideB   = IsSquare ? sideA : Sides[1].Size;
            int left    = (Console.WindowWidth - Sides[0].Size) / 2;
            string line = new string(CHAR, sideA);

            Console.SetCursorPosition(left - 1, ((Console.WindowHeight - sideB) / 2) - 1);
            Console.Write('D');

            Console.CursorLeft += sideA;
            Console.Write('C');

            Console.CursorTop = (Console.WindowHeight - sideB) / 2;

            for (int i = 0; i < sideB; i++)
            {
                Console.CursorLeft = left;
                Console.WriteLine(line);
            }

            Console.CursorLeft = left - 1;
            Console.Write('A');

            Console.CursorLeft += sideA;
            Console.Write('B');
        }
    }
}

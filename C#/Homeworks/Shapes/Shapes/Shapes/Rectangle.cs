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
            int a       = Sides[0].Size;
            int b       = IsSquare ? a : Sides[1].Size;
            int left    = (Console.WindowWidth - a) / 2;
            string line = GetLineString(a);
            
            Console.CursorTop = (Console.WindowHeight - b) / 2;

            for (int i = 0; i < b; i++)
            {
                Console.CursorLeft = left;
                Console.WriteLine(line);
            }
        }
    }
}

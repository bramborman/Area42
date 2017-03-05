using System;

namespace Shapes.Shapes
{
    public sealed class Rectangle : ShapeBase
    {
#pragma warning disable IDE1006 // Naming Styles
        public int a
        {
            get { return Sides[0].Size; }
        }
        public int b
        {
            get { return IsSquare ? a : Sides[1].Size; }
        }
#pragma warning restore IDE1006 // Naming Styles
        public bool IsSquare { get; }

        public Rectangle(bool isSquare) : base(new Side("a", 2, isSquare ? Math.Min(MaxWidth, MaxHeight) : MaxWidth), isSquare ? null : new Side("b", 2, MaxHeight))
        {
            IsSquare = isSquare;
        }

        protected override void Draw()
        {
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

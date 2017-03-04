using System;

namespace Shapes.Shapes
{
    public sealed class Trapezoid : ShapeBase
    {
        public Trapezoid() : base(new Side("a", 2, MaxWidth), new Side("c", 2, MaxWidth), new Side("v", 2, MaxHeight))
        {

        }

        protected override void Draw()
        {
            int a               = Sides[0].Size;
            int c               = Sides[1].Size;
            int v               = Sides[2].Size;
            int minWidth        = Math.Min(a, c);
            int maxWidth        = Math.Max(a, c);
            int triangleWidth   = (maxWidth - minWidth) / 2;
            
            int left    = (Console.WindowWidth - maxWidth) / 2;
            int top     = (Console.WindowHeight - v) / 2;
            string line = GetLineString(c);

            Console.CursorTop = top;
            Triangle.DrawRightTriangle(true, false, left, triangleWidth, v);

            Console.CursorTop = top;
            int rectangleLeft = left + triangleWidth;

            for (int i = 0; i < v; i++)
            {
                Console.CursorLeft = rectangleLeft;
                Console.WriteLine(line);
            }

            Console.CursorTop = top;
            Triangle.DrawRightTriangle(false, false, rectangleLeft + minWidth, triangleWidth, v);
        }
    }
}

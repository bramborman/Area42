using System;

namespace Shapes.Shapes
{
    public sealed class Trapezoid : ShapeBase
    {
#pragma warning disable IDE1006 // Naming Styles
        public int a
        {
            get { return Sides[0].Size; }
        }
        public int c
        {
            get { return Sides[1].Size; }
        }
        public int v
        {
            get { return Sides[2].Size; }
        }
#pragma warning restore IDE1006 // Naming Styles
        public bool IsUpsideDown
        {
            get
            {
                return c > a;
            }
        }

        public Trapezoid() : base(new Side("a", 2, MaxWidth), new Side("c", 2, MaxWidth), new Side("v", 2, MaxHeight))
        {

        }

        protected override void Draw()
        {
            int minWidth        = Math.Min(a, c);
            int maxWidth        = Math.Max(a, c);
            int triangleWidth   = (maxWidth - minWidth) / 2;
            
            int left    = (Console.WindowWidth - maxWidth) / 2;
            int top     = (Console.WindowHeight - v) / 2;
            string line = GetLineString(minWidth);

            Console.CursorTop = top;
            DrawRightTriangle(true, left, triangleWidth, v);

            Console.CursorTop = top;
            int rectangleLeft = left + triangleWidth;

            for (int i = 0; i < v; i++)
            {
                Console.CursorLeft = rectangleLeft;
                Console.WriteLine(line);
            }

            Console.CursorTop = top;
            DrawRightTriangle(false, rectangleLeft + minWidth, triangleWidth, v);
        }

        private void DrawRightTriangle(bool leftFacing, int cursorLeft, int width, int height)
        {
            double ratio = (double)width / height;

            int i   = IsUpsideDown ? height : 0;
            int max = IsUpsideDown ? 0 : height;
            Action action;

            if (IsUpsideDown)
            {
                action = () => i--;
            }
            else
            {
                action = () => i++;
            }

            while (i != max)
            {
                int lineLength = (int)Math.Round(i * ratio);
                Console.CursorLeft = cursorLeft;

                if (leftFacing)
                {
                    Console.CursorLeft += width - lineLength;
                }

                Console.WriteLine(GetLineString(lineLength));

                action();
            }
        }
    }
}

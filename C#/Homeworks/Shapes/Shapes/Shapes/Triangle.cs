using System;

namespace Shapes.Shapes
{
    public sealed class Triangle : ShapeBase
    {
        private const string THIRD_SIDE_NAME = "CA";

        public Triangle() : base(new Side("AB", 2, MaxWidth), new Side("BC", 2, MaxHeight), new Side(THIRD_SIDE_NAME, 2, 2))
        {

        }

        protected override void LoadSide(Side side)
        {
            if (side.Name == THIRD_SIDE_NAME)
            {
                int minSide = Math.Min(Sides[0].Size, Sides[1].Size);
                int maxSide = Math.Max(Sides[0].Size, Sides[1].Size);

                side.MinSize = maxSide - minSide + 1;
                side.MaxSize = Math.Min(Sides[0].Size + Sides[1].Size - 1, MaxWidth);
            }

            base.LoadSide(side);
        }

        protected override void Draw()
        {
            int a = Sides[1].Size;
            int b = Sides[2].Size;
            int c = Sides[0].Size;
            
            double cosAngleA = (Math.Pow(b, 2) + Math.Pow(c, 2) - Math.Pow(a, 2)) / (2*b*c);
            double angleA    = Math.Acos(cosAngleA);

            double vCD = Math.Sin(angleA) * b;
            int vC     = (int)Math.Round(vCD);

            int leftPartOfC  = (int)Math.Round(vCD / Math.Tan(angleA));
            int rightPartOfC = c - leftPartOfC;


            int left = (Console.WindowWidth - c) / 2;
            int top  = (Console.WindowHeight - vC) / 2;

            Console.CursorTop = top;
            DrawRightTriangle(true, left, vC, b, leftPartOfC);

            Console.CursorTop = top;
            DrawRightTriangle(false, left + leftPartOfC, vC, a, rightPartOfC);
        }

        private void DrawRightTriangle(bool leftFacing, int cursorLeft, int a, int b, int c)
        {
            double ratio = (double)c / a;

            for (int i = 1; i <= a; i++)
            {
                int lineLength = (int)Math.Round(i * ratio);
                Console.CursorLeft = cursorLeft;

                if (leftFacing)
                {
                    Console.CursorLeft += c - lineLength;
                }

                Console.WriteLine(GetLineString(lineLength));
            }
        }
    }
}

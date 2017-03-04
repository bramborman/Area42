using System;

namespace Shapes.Shapes
{
    public sealed class Triangle : ShapeBase
    {
        private const string THIRD_SIDE_NAME     = "CA";
        private const double RIGHT_ANGLE_RADIANS = Math.PI / 2;

        public Triangle() : base(new Side("AB", 2, Math.Min((MaxHeight * 2) - 1, MaxWidth)), new Side("BC", 2, MaxHeight), new Side(THIRD_SIDE_NAME, 2, MaxHeight))
        {

        }

        protected override void LoadSide(ref int index)
        {
            Side side = Sides[index];

            if (side.Name == THIRD_SIDE_NAME)
            {
                int minSide = Math.Min(Sides[0].Size, Sides[1].Size);
                int maxSide = Math.Max(Sides[0].Size, Sides[1].Size);

                int newMinSize = Math.Max(side.MinSize, maxSide - minSide + 1);
                int newMaxSize = Math.Min(side.MaxSize, Sides[0].Size + Sides[1].Size - 1);
                
                if (newMinSize > newMaxSize)
                {
                    index--;
                    //TODO: Calculate this before first user input to the second side
                    Sides[index].MinSize = (newMinSize + Sides[index].MinSize) - newMaxSize;
                }
                else
                {
                    side.MinSize = newMinSize;
                    side.MaxSize = newMaxSize;
                }
            }

            base.LoadSide(ref index);
        }

        protected override void Draw()
        {
            int a = Sides[1].Size;
            int b = Sides[2].Size;
            int c = Sides[0].Size;
            
            double cosAlpha = (Math.Pow(b, 2) + Math.Pow(c, 2) - Math.Pow(a, 2)) / (2*b*c);
            double alpha    = Math.Acos(cosAlpha);
            
            double vCDouble = Math.Sin(alpha) * b;
            int vC          = (int)Math.Round(vCDouble);
            
            int leftPartOfC  = (int)Math.Round(vCDouble / Math.Tan(alpha));
            int rightPartOfC = c - leftPartOfC;
            
            int top  = (Console.WindowHeight - vC) / 2;

            if (alpha > RIGHT_ANGLE_RADIANS)
            {
                int longC   = (int)Math.Round(Math.Sqrt(Math.Pow(a, 2) - Math.Pow(vCDouble, 2)));
                int shortC  = longC - c;
                int left    = (Console.WindowWidth - longC) / 2;

                Console.CursorTop = top;
                DrawRightTriangle(false, false, left, longC, vC);

                Console.CursorTop = top;
                DrawRightTriangle(false, true, left, shortC, vC);
            }
            else
            {
                double cosBeta  = (Math.Pow(a, 2) + Math.Pow(c, 2) - Math.Pow(b, 2)) / (2 * a * c);
                double beta     = Math.Acos(cosBeta);

                if (beta > RIGHT_ANGLE_RADIANS)
                {
                    int longC   = (int)Math.Round(Math.Sqrt(Math.Pow(b, 2) - Math.Pow(vCDouble, 2)));
                    int shortC  = longC - c;
                    int left    = (Console.WindowWidth - longC) / 2;

                    Console.CursorTop = top;
                    DrawRightTriangle(true, false, left, longC, vC);

                    Console.CursorTop = top;
                    DrawRightTriangle(true, true, left + c, shortC, vC);
                }
                else
                {
                    int left = (Console.WindowWidth - c) / 2;

                    Console.CursorTop = top;
                    DrawRightTriangle(true, false, left, leftPartOfC, vC);

                    Console.CursorTop = top;
                    DrawRightTriangle(false, false, left + leftPartOfC, rightPartOfC, vC);
                }
            }
        }
        
        private void DrawRightTriangle(bool leftFacing, bool erase, int cursorLeft, int width, int height)
        {
            double ratio = (double)width / height;

            for (int i = 1; i <= height; i++)
            {
                int lineLength = (int)Math.Round(i * ratio);
                Console.CursorLeft = cursorLeft;

                if (leftFacing)
                {
                    Console.CursorLeft += width - lineLength;
                }

                Console.WriteLine(erase ? new string(' ', lineLength) : GetLineString(lineLength));
            }
        }
    }
}

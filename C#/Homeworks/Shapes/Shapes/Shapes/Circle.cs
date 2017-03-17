using System;

namespace Shapes.Shapes
{
    public sealed class Circle : ShapeBase
    {
        private const double ANGLE_90 = Math.PI / 2;

#pragma warning disable IDE1006 // Naming Styles
        public int r
        {
            get
            {
                return (int)Math.Round(d / 2.0);
            }
        }
        public int d
        {
            get { return Sides[0].Size; }
        }
#pragma warning restore IDE1006 // Naming Styles

        public Circle() : base(new Side("d", 3, Math.Min(MaxWidth, MaxHeight)))
        {

        }

        protected override void Draw()
        {
            int left = (Console.WindowWidth - d) / 2;
            int top  = (Console.WindowHeight - d) / 2;

            Console.CursorTop = top;
            
            for (int i = 0; i < r; i++)
            {
                double alpha = Math.Atan(i);
                int lineLength = (int)Math.Round(Math.Cos(alpha) * r);
            
                Console.CursorLeft = left + lineLength;
                Console.WriteLine(GetLineString(r - lineLength));
            }

            Console.CursorTop = top;

            for (int i = 0; i < r; i++)
            {
                double alpha = Math.Atan(i);
                int lineLength = (int)Math.Round(Math.Cos(alpha) * r);

                Console.CursorLeft = left + r;
                Console.WriteLine(GetLineString(r - lineLength));
            }

            Console.CursorTop = top + r;
            
            for (int i = r; i > 0; i--)
            {
                double alpha = Math.Atan(i);
                int lineLength = (int)Math.Round(Math.Cos(alpha) * r);
            
                Console.CursorLeft = left + lineLength;
                Console.WriteLine(GetLineString(r - lineLength));
            }
            
            Console.SetCursorPosition(left + r, top + r);
            
            for (int i = r; i > 0; i--)
            {
                double alpha = Math.Atan(i);
                int lineLength = (int)Math.Round(Math.Cos(alpha) * r);

                Console.CursorLeft = left + r;
                Console.WriteLine(GetLineString(r - lineLength));
            }
        }
    }
}

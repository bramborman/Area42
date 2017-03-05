using System;

namespace Shapes.Shapes
{
    public sealed class Line : ShapeBase
    {
        public int Length
        {
            get { return Sides[0].Size; }
        }

        public Line() : base(new Side("AB", 2, MaxWidth))
        {

        }

        protected override void Draw()
        {
            int left = (Console.WindowWidth - Length) / 2;

            Console.SetCursorPosition(left, Console.WindowHeight / 2);
            Console.Write(GetLineString(Length));
        }
    }
}

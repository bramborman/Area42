using System;

namespace Shapes.Shapes
{
    public sealed class Line : ShapeBase
    {
        public Line() : base(new Side("AB", 2, MaxWidth))
        {

        }

        protected override void Draw()
        {
            int size = Sides[0].Size;
            int left = (Console.WindowWidth - size) / 2;

            Console.SetCursorPosition(left, Console.WindowHeight / 2);
            Console.Write(GetLineString(size));
        }
    }
}

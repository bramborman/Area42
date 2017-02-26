using System;

namespace Shapes.Shapes
{
    public sealed class Line : ShapeBase
    {
        public Line() : base("Čára", new Side("|AB|", 2, Console.WindowWidth - 2))
        {

        }

        protected override void Draw()
        {
            int left = (Console.WindowWidth - Sides[0].Size) / 2;

            Console.SetCursorPosition(left, Console.WindowHeight / 2);
            Console.WriteLine(LINE_CROSS_VERTICAL_RIGHT + new string(LINE_HORIZONTAL, Sides[0].Size - 2) + LINE_CROSS_VERTICAL_LEFT);

            Console.CursorLeft = left;
            Console.Write('A');

            Console.CursorLeft += Sides[0].Size - 2;
            Console.Write('B');
        }
    }
}

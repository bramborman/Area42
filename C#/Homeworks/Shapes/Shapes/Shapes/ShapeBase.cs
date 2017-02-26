using System;
using System.Collections.Generic;

namespace Shapes.Shapes
{
    public abstract class ShapeBase
    {
        protected const char LINE_HORIZONTAL            = '\u2500';
        protected const char LINE_VERTICAL              = '\u2502';
        protected const char LINE_EDGE_TOP_LEFT         = '\u250c';
        protected const char LINE_EDGE_TOP_RIGHT        = '\u2510';
        protected const char LINE_EDGE_BOTTOM_LEFT      = '\u2514';
        protected const char LINE_EDGE_BOTTOM_RIGHT     = '\u2518';
        protected const char LINE_CROSS_VERTICAL_RIGHT  = '\u251c';
        protected const char LINE_CROSS_VERTICAL_LEFT   = '\u2524';
        protected const char LINE_CROSS_HORIZONTAL_DOWN = '\u252c';
        protected const char LINE_CROSS_HORIZONTAL_UP   = '\u2534';
        protected const char LINE_CROSS_FULL            = '\u253c';

        protected List<Side> Sides { get; }

        public string Name { get; }

        protected ShapeBase(string name, params Side[] sides)
        {
            Name  = name;
            Sides = new List<Side>(sides);
        }

        public void LoadNDraw()
        {
            Console.Clear();

            foreach (Side side in Sides)
            {
                side.Load();
            }

            Console.Clear();
            Console.SetCursorPosition((Console.WindowWidth - Name.Length) / 2, 3);
            Console.Write(Name.ToUpper());

            Draw();

            Console.ReadKey();
            Console.Clear();
        }

        protected abstract void Draw();
    }
}

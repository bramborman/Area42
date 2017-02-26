using System;
using System.Collections.Generic;

namespace Shapes.Shapes
{
    public abstract class ShapeBase
    {
        protected const char CHAR = '#';

        protected static int MaxWidth
        {
            get
            {
                return Console.WindowWidth - 6;
            }
        }
        protected static int MaxHeight
        {
            get
            {
                return (Console.WindowHeight * FontHelper.FONT_DIFFERENCE) - 6;
            }
        }

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
                side?.Load();
            }

            Console.Clear();
            FontHelper.SetSmallFont();

            // Console.SetCursorPosition((Console.WindowWidth - Name.Length) / 2, 3);
            // Console.Write(Name.ToUpper());

            Draw();

            Console.ReadKey();
            FontHelper.SetNormalFont();
            Console.Clear();
        }

        protected abstract void Draw();
    }
}

using System;
using System.Collections.Generic;

namespace Shapes.Shapes
{
    public abstract class ShapeBase
    {
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
        
        protected ShapeBase(params Side[] sides)
        {
            Sides = new List<Side>(sides);
        }

        public void LoadNDraw()
        {
            Console.Clear();
            Console.CursorVisible = true;

            foreach (Side side in Sides)
            {
                LoadSide(side);
            }

            Console.CursorVisible = false;
            Console.Clear();
            FontHelper.SetSmallFont();
            
            Draw();

            Console.ReadKey();
            FontHelper.SetNormalFont();
            Console.Clear();
        }

        protected virtual void LoadSide(Side side)
        {
            side?.Load();
        }

        protected abstract void Draw();

        protected string GetLineString(int length)
        {
            return new string('#', length);
        }
    }
}

using System;

namespace Shapes.Shapes
{
    public sealed class Triangle : ShapeBase
    {
        public Triangle() : base(new Side("a", 2, MaxWidth), new Side("b", 2, MaxHeight), new Side("c", 2, 2))
        {

        }

        protected override void LoadSide(Side side)
        {
            if (side.Name == "c")
            {
                side.MaxSize = Math.Min(Sides[0].Size + Sides[1].Size - 1, MaxWidth);
            }

            base.LoadSide(side);
        }

        protected override void Draw()
        {

        }
    }
}

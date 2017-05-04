using System;

namespace UnitTesting
{
    public sealed class Calculator
    {
        public int Calculate(int x, int y, Operation operation)
        {
            switch (operation)
            {
                case Operation.Addition:    return x + y;
                case Operation.Subtraction: return x - y;
                case Operation.Multiplying: return x * y;
                case Operation.Dividing:    return x / y;
                default: throw new ArgumentOutOfRangeException(nameof(operation));
            }
        }

        public int CalculateSurface(int x)
        {
            return x * x;
        }

        public float[] CalculateQuadraticEquation(float a, float b, float c)
        {
            float topRight  = (float)Math.Sqrt(CalculateQuadraticEquationDiscriminant(a, b, c));
            float bottom    = 2 * a;

            float? x1 = (-b + topRight) / bottom;
            float? x2 = (-b - topRight) / bottom;

            if (float.IsNaN(x1.Value))
            {
                x1 = null;
            }

            if (float.IsNaN(x2.Value))
            {
                x2 = null;
            }

            if (x1 == x2 && x1 != null)
            {
                return new float[] { x1.Value };
            }
            else if (x1 != null && x2 != null)
            {
                return new float[] { x1.Value, x2.Value };
            }

            throw new Exception();
        }

        public float CalculateQuadraticEquationDiscriminant(float a, float b, float c)
        {
            float output = (b * b) - (4 * a * c);

            if (output < 0)
            {
                throw new ArgumentException();
            }

            return output;
        }

        public enum Operation
        {
            Addition,
            Subtraction,
            Multiplying,
            Dividing
        }
    }
}

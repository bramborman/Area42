using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using UnitTesting;

namespace UnitTestProject
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void CalculatorTest()
        {
            Calculator calculator = new Calculator();

            int x = 5;
            int y = 7;

            int result = calculator.Calculate(x, y, Calculator.Operation.Addition);
            Assert.IsTrue(result == x + y);

            result = calculator.Calculate(x, y, Calculator.Operation.Subtraction);
            Assert.IsTrue(result == x - y);

            result = calculator.Calculate(x, y, Calculator.Operation.Multiplying);
            Assert.IsTrue(result == x * y);

            result = calculator.Calculate(x, y, Calculator.Operation.Dividing);
            Assert.IsTrue(result == x / y);

            Assert.ThrowsException<DivideByZeroException>(() => calculator.Calculate(x, 0, Calculator.Operation.Dividing));

            Assert.IsTrue(calculator.CalculateSurface(3) == 9);

            Assert.ThrowsException<ArgumentOutOfRangeException>(() => calculator.Calculate(0, 0, (Calculator.Operation)69));
        }

        [TestMethod]
        public void CalculateQuadraticEquationDiscriminantTest()
        {
            float a = 2;
            float b = 3;
            float c = 1;
            Calculator calculator = new Calculator();

            Assert.IsTrue(calculator.CalculateQuadraticEquationDiscriminant(a, b, c) == (b * b) - (4 * a * c));
            Assert.ThrowsException<ArgumentException>(() => calculator.CalculateQuadraticEquationDiscriminant(1, 0, 1));
        }

        [TestMethod]
        public void CalculateQuadraticEquationTest()
        {
            Calculator calculator = new Calculator();

            float[] quadraticEquationResults = calculator.CalculateQuadraticEquation(1, 4, 4);
            Assert.IsTrue(quadraticEquationResults.Length == 1);
            Assert.IsTrue(quadraticEquationResults[0] == -2f);

            quadraticEquationResults = calculator.CalculateQuadraticEquation(2, 3, 1);
            Assert.IsTrue(quadraticEquationResults.Length == 2);
            Assert.IsTrue(quadraticEquationResults[0] == -0.5f && quadraticEquationResults[1] == -1f);
        }
    }
}

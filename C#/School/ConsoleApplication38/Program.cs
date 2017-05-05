using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication38
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            int iterations  = 0;
            int sum         = 0;

            while (true)
            {
                Grade grade     = new Grade();
                bool isGrade    = false;

                do
                {
                    Console.Write($"Zadej {iterations + 1}. znamku: ");
                    string input = Console.ReadLine();

                    if (input == "0")
                    {
                        break;
                    }

                    isGrade = Grade.TryParse(input, out grade);
                } while (!isGrade);

                if (!isGrade)
                {
                    break;
                }

                sum += grade;
                iterations++;
            }

            if (iterations == 0)
            {
                Console.WriteLine("Nebyly zadany zadne znamky.");
            }
            else
            {
                Console.WriteLine($"Prumer vsech znamek je {sum / (float)iterations:F2}.");
            }

            Console.ReadKey(true);
        }
    }

    public struct Grade
    {
        private int value;

        public Grade(int grade)
        {
            ValidateIsGrade(grade, nameof(grade));
            value = grade;
        }

        public static implicit operator int(Grade g)
        {
            if (g.value == 0)
            {
                g.value = 1;
            }

            return g.value;
        }

        public static explicit operator Grade(int i)
        {
            ValidateIsGrade(i, nameof(i));

            Grade output;
            output.value = i;

            return output;
        }

        public static bool TryParse(string str, out Grade grade)
        {
            int numericValue;

            if (!int.TryParse(str, out numericValue) || !IsValidGrade(numericValue))
            {
                grade = default(Grade);
                return false;
            }

            grade.value = numericValue;
            return true;
        }

        public static Grade Parse(string str)
        {
            int numericValue = int.Parse(str);
            ValidateIsGrade(numericValue, nameof(str));

            Grade output;
            output.value = numericValue;

            return output;
        }

        private static bool IsValidGrade(int i)
        {
            return i >= 1 && i <= 5;
        }

        private static void ValidateIsGrade(int i, string parameterName)
        {
            if (!IsValidGrade(i))
            {
                throw new ArgumentOutOfRangeException(parameterName);
            }
        }
    }
}

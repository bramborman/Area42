using System;
using System.Linq;

namespace Challenges
{
    public sealed class Challenge001 : IChallenge
    {
        public string Description
        {
            get
            {
                return "Create a function that accepts three arguments - number a, number n, and number b." +
                    "\nThe function should return an array of numbers where each second number is 'b' and the others" +
                    "\nare multiples of the number 'a' lower than 'n' e.g. for 7, 17, -99 it should return 0, -99, 7, -99, 14, -99." +
                    "\nThe function should have as few chars as possible.";
            }
        }

        public void Run()
        {
            Console.WriteLine("INPUT: ");
            Console.WriteLine("7, 17, -99");

            int[] collection = S(7, 17, -99);

            foreach (int i in collection)
            {
                Console.Write(i + ", ");
            }

            Console.ReadLine();
        }

        int[]S(int a,int n,int b)=>Enumerable.Range(0,n/a+1).SelectMany(x=>new[]{a*x,b}).ToArray();
    }
}

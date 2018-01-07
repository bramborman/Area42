using System;
using System.Collections.Generic;
using System.Linq;

namespace Challenges
{
    public sealed class Challenge002 : IChallenge
    {
        public string Description
        {
            get
            {
                return "Create a function that accepts variable number of arrays of numbers where all arrays are of the same length." +
                    "\nThe function should return an array of average values of items on the same index in each array" +
                    "\ne.g. on the first index will be average value of items on the first indexes in the input arrays." +
                    "\nThe function should have as few chars as possible.";
            }
        }

        public void Run()
        {
            V1();
            V2();

            Console.ReadLine();
        }

        private void V1()
        {
            List<int[]> list = new List<int[]>()
            {
                new [] {1, 2, 3, 4, 5},
                new [] {1, 2, 3, 4, 5},
                new [] {1, 2, 3, 4, 5}
            };

            Console.WriteLine("V1:");
            Console.WriteLine("INPUT: ");

            foreach (int[] array in list)
            {
                foreach (int i in array)
                {
                    Console.Write(i + ", ");
                }

                Console.WriteLine();
            }

            float[] averages = A(list);

            Console.WriteLine("OUTPUT: ");
            foreach (float average in averages)
            {
                Console.Write(average + ", ");
            }

            Console.WriteLine();
        }

        private void V2()
        {
            int[][] arrays = new int[][]
            {
                new [] {1, 2, 3, 4, 5},
                new [] {1, 2, 3, 4, 5},
                new [] {1, 2, 3, 4, 5}
            };

            Console.WriteLine();
            Console.WriteLine("V2:");
            Console.WriteLine("INPUT: ");

            foreach (int[] array in arrays)
            {
                foreach (int i in array)
                {
                    Console.Write(i + ", ");
                }

                Console.WriteLine();
            }

            float[] averages = B(arrays);

            Console.WriteLine("OUTPUT: ");
            foreach (float average in averages)
            {
                Console.Write(average + ", ");
            }
        }

        float[]A(List<int[]>l)=>Enumerable.Range(0,l[0].Length).Select(i=>{float r=0;l.ForEach(a=>r+=a[i]/(float)l.Count);return r;}).ToArray();
        float[]B(int[][]l)=>Enumerable.Range(0,l[0].Length).Select(i=>l.Select(a=>a[i]).Sum()/(float)l.Length).ToArray();
        // Waiting for C# 7.3:
        //float[]C(int[][]l)=>(0..l[0].Length).Select(i=>l.Select(a=>a[i]).Sum()/(float)l.Length).ToArray();
    }
}

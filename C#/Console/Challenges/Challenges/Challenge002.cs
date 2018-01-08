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
            int[][] arrays = new int[][]
            {
                new [] {1, 2, 3, 4, 5},
                new [] {1, 2, 3, 4, 5},
                new [] {1, 2, 3, 4, 5}
            };
            
            Console.WriteLine("INPUT: ");

            foreach (int[] array in arrays)
            {
                foreach (int i in array)
                {
                    Console.Write(i + ", ");
                }

                Console.WriteLine();
            }

            double[] averages = G(arrays);

            Console.WriteLine("OUTPUT: ");
            foreach (float average in averages)
            {
                Console.Write(average + ", ");
            }

            Console.ReadLine();
        }

        float[]A(List<int[]>l)=>Enumerable.Range(0,l[0].Length).Select(i=>{float r=0;l.ForEach(a=>r+=a[i]/(float)l.Count);return r;}).ToArray();
        float[]B(int[][]l)=>Enumerable.Range(0,l[0].Length).Select(i=>l.Select(a=>a[i]).Sum()/(float)l.Length).ToArray();
        float[]C(int[][]l)=>Enumerable.Range(0,l[0].Length).Select(i=>l.Select(a=>a[i]).Sum()*1f/l.Length).ToArray();
        double[]D(int[][]l)=>Enumerable.Range(0,l[0].Length).Select(i=>l.Select(a=>a[i]).Average()).ToArray();
        double[]E(int[][]l)=>l[0].Select((a,i)=>i).Select(i=>l.Select(a=>a[i]).Average()).ToArray();
        double[]F(int[][]l)=>l[0].Select((_,i)=>l.Select(a=>a[i]).Average()).ToArray();
        double[]G(int[][]l)=>l[0].Select((_,i)=>l.Average(a=>a[i])).ToArray();
        // Waiting for C# 7.3:
        //float[]C(int[][]l)=>(0..l[0].Length).Select(i=>l.Select(a=>a[i]).Sum()/(float)l.Length).ToArray();
    }
}

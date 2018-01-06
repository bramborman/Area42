using System;
using System.Collections.Generic;
using System.Linq;

namespace Challenge001
{
    public sealed class Program
    {
        public static void Main(string[] args)
        {
            List<int[]> list = new List<int[]>()
            {
                new [] {1, 2, 3, 4, 5},
                new [] {1, 2, 3, 4, 5},
                new [] {1, 2, 3, 4, 5}
            };

            float[] avgs = new Program().A(list);

            foreach (float f in avgs)
            {
                Console.Write(f + ", ");
            }

            Console.ReadLine();
        }
        
        float[]A(List<int[]>l)=>Enumerable.Range(0,l[0].Length).Select(i=>{float r=0;l.ForEach(a=>r+=a[i]/(float)l.Count);return r;}).ToArray();
    }
}

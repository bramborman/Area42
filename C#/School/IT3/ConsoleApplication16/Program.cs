using System;
using System.Threading;

namespace ConsoleApplication16
{
    class Program
    {
        static void Main(string[] args)
        {
            const char BODY = '#';
            const int SLEEP = 0;
            
            int width  = Console.WindowWidth;
            int height = Console.WindowHeight;

            for (int iteration = 0; iteration < Math.Sqrt(width); iteration += 2)
            {
                for (int x = iteration; x < width - iteration; x++)
                {
                    Console.SetCursorPosition(x, iteration);
                    Console.Write(BODY);
                    Thread.Sleep(SLEEP);
                }
                
                for (int y = iteration; y < height - iteration; y++)
                {
                    Console.SetCursorPosition(width - iteration - 1, y);
                    Console.Write(BODY);
                    Thread.Sleep(SLEEP);
                }
            }

            Console.ReadKey();
        }
    }
}

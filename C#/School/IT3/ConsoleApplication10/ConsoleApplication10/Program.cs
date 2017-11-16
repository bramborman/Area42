using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication10
{
    class Program
    {
        static void Main(string[] args)
        {
            Draw(Input());
        }

        static int Input()
        {
            int size;

            Console.Write("Zadej hodnotu 2-25: ");
            while (!int.TryParse(Console.ReadLine(), out size) || size < 2 || size > 25) ;

            return size;
        }

        static void Draw(int size)
        {
            Console.CursorVisible = false;
            Console.CursorTop = (Console.WindowHeight - size) / 2;

            int cursorLeft = (Console.WindowWidth - size) / 2;
            int wat = 1;

            for (int i = 1; i <= size; i++)
            {
                Console.CursorLeft = cursorLeft + ((size - wat) / 2);
                Console.WriteLine(new string('#', wat));
                wat += 2;
            }

            Console.ReadKey();
        }
    }
}

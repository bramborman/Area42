using System;

namespace ConsoleApplication21
{
    class Foo
    {
        public void Bar()
        {
            int[] array = new int[10];
            Random random = new Random();

            for (int i = 0; i < array.Length; i++)
            {
                array[i] = random.Next(1, 20);
            }

            Write(array);
            Sort(array);
            Console.WriteLine();

            Write(array);
            Console.ReadKey();
        }

        private void Sort(int[] array)
        {
            for (int i = 0; i < array.Length - 1; i++)
            {
                int min = i;

                for (int j = i + 1; j < array.Length; j++)
                {
                    if (array[j] < array[min])
                    {
                        min = j;
                    }
                }

                if (min != i)
                {
                    int temp    = array[min];
                    array[min]  = array[i];
                    array[i]    = temp;
                }
            }
        }

        private void Write(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]} ");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            new Foo().Bar();
        }
    }
}

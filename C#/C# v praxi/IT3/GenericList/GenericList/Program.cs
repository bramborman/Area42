using System;

namespace GenericList
{
    class Program
    {
        static void Main(string[] args)
        {
            GenericList<int> genericList = new GenericList<int>();
            Console.WriteLine($"Count: {genericList.Count}");

            for (int i = 0; i < 10; i++)
            {
                genericList.Add(i);
            }

            Console.WriteLine($"Count: {genericList.Count}");

            for (int i = 0; i < genericList.Count; i++)
            {
                Console.Write($"{genericList[i]} ");
            }

            Console.Write("\n\n");
            foreach (int value in genericList)
            {
                Console.Write($"{value} ");
            }

            genericList.Remove(4);

            Console.WriteLine();
            foreach (int value in genericList)
            {
                Console.Write($"{value} ");
            }

            Console.WriteLine($"\nIndexOf(3): {genericList.IndexOf(3)}");

            genericList.RemoveAt(genericList.Count - 1);
            foreach (int value in genericList)
            {
                Console.Write($"{value} ");
            }

            Console.WriteLine();
            genericList.RemoveAt(0);
            foreach (int value in genericList)
            {
                Console.Write($"{value} ");
            }

            Console.WriteLine();
            genericList.Insert(0, 9);
            foreach (int value in genericList)
            {
                Console.Write($"{value} ");
            }

            Console.WriteLine($"\n\n[3]: {genericList[3]}");
            genericList[3] = 0;
            Console.WriteLine($"[3]: {genericList[3]}");

            Console.WriteLine($"\nContains(5): {genericList.Contains(5)}");
            genericList.Clear();
            Console.WriteLine($"Contains(5): {genericList.Contains(5)}");

            Console.ReadKey();
        }
    }
}

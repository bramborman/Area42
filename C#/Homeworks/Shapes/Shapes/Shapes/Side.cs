using System;

namespace Shapes.Shapes
{
    public sealed class Side
    {
        public string Name { get; }
        public int MinSize { get; set; }
        public int MaxSize { get; set; }
        public int Size { get; private set; }

        public Side(string name, int minSize, int maxSize)
        {
            Name    = name;
            MinSize = minSize;
            MaxSize = maxSize;
        }

        public void Load()
        {
#pragma warning disable IDE0018 // Inline variable declaration
            int size;
#pragma warning restore IDE0018 // Inline variable declaration

            do
            {
                Console.Write($"Zadej velikost strany {Name} <{MinSize}-{MaxSize}>: ");
            } while (!int.TryParse(Console.ReadLine(), out size) || size < MinSize || size > MaxSize);

            Size = size;
        }
    }
}

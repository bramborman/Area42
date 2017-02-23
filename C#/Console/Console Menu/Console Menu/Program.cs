using System;
using System.Linq;

namespace ConsoleMenu
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Console.CursorVisible = false;

            int selectedIndex = 0;
            string[] menuItems = { "Start", "About", "Exit" };

            while (true)
            {
                selectedIndex = Menu(selectedIndex, menuItems);
                Console.Clear();

                Console.WriteLine(menuItems[selectedIndex] + " selected");

                Console.ReadKey();
                Console.Clear();
            }
        }

        private static int Menu(params string[] menuItems)
        {
            return Menu(0, menuItems);
        }

        private static int Menu(int initialSelectedIndex, params string[] menuItems)
        {
            bool handled;
            int horizontalPosition  = (Console.WindowWidth - menuItems.OrderByDescending(s => s.Length).ToList()[0].Length) / 2;
            int verticalPosition    = (Console.WindowHeight - menuItems.Length) / 2;
            int selectedIndex       = initialSelectedIndex;

            Console.CursorTop = verticalPosition;

            foreach (string menuItem in menuItems)
            {
                Console.CursorLeft = horizontalPosition;
                Console.WriteLine(menuItem);
            }

            while (true)
            {
                handled = false;

                Console.SetCursorPosition(horizontalPosition - 2, verticalPosition + selectedIndex);
                Console.Write(">");

                switch (Console.ReadKey(true).Key)
                {
                    case ConsoleKey.UpArrow:
                        if (selectedIndex != 0)
                        {
                            handled = true;
                            selectedIndex--;
                        }

                        break;

                    case ConsoleKey.DownArrow:
                        if (selectedIndex != menuItems.Length - 1)
                        {
                            handled = true;
                            selectedIndex++;
                        }

                        break;

                    case ConsoleKey.Enter:

                        handled = true;
                        return selectedIndex;
                }
                
                if (handled)
                {
                    // Remove the '>' char
                    Console.Write("\b ");
                }
            }
        }
    }
}

using System;
using System.Linq;

namespace Shapes
{
    public static class Menu
    {
        public static string Draw(params string[] menuItems)
        {
            bool handled;
            int horizontalPosition  = (Console.WindowWidth - menuItems.OrderByDescending(s => s.Length).ToList()[0].Length) / 2;
            int verticalPosition    = (Console.WindowHeight - menuItems.Length) / 2;
            int selectedIndex       = 0;

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
                        return menuItems[selectedIndex];
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

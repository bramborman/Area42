using System;
using System.Collections.Generic;

namespace StorageTools.Helpers
{
    public sealed class Menu
    {
        private const int PAGE_ITEMS_LIMIT = 9;

        public List<MenuItem> Items { get; } = new List<MenuItem>();
        public string Title { get; }

        public Menu(string title)
        {
            Title = title;
        }

        public void Show()
        {
            bool hasMorePages = Items.Count > PAGE_ITEMS_LIMIT;
            int page = 0;

            while (true)
            {
                Console.WriteLine(Title + (hasMorePages ? $" (page {page + 1})" : ""));

                int number = 1;
                int currentIndexStart = page * PAGE_ITEMS_LIMIT;
                int currentIndexLimit = Math.Min(currentIndexStart + PAGE_ITEMS_LIMIT, Items.Count);
                bool isLastPage = currentIndexLimit == Items.Count;

                for (int i = currentIndexStart; i < currentIndexLimit; i++)
                {
                    Console.WriteLine($" [{number++}] {Items[i].Text}");
                }

                if (hasMorePages)
                {
                    Console.WriteLine($" [0] {(isLastPage ? "First" : "Next")} page");
                }

                Console.Write("Enter your choice: ");

                if (int.TryParse(Console.ReadLine(), out int selection))
                {
                    if (hasMorePages && selection == 0)
                    {
                        page = isLastPage ? 0 : page + 1;
                        continue;
                    }
                    else
                    {
                        // Menu is numbered from 1 not from 0 as index
                        selection--;

                        if (selection >= 0 && selection < Math.Min(PAGE_ITEMS_LIMIT, Items.Count - currentIndexStart))
                        {
                            Items[currentIndexStart + selection].Action();
                            break;
                        }
                    }
                }

                Console.WriteLine("Invalid input!");
            }
        }
    }
}

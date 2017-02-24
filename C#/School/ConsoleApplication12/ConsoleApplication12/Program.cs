using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication12
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[6];

            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"Zadej {i + 1}. cislo: ");
                while (!int.TryParse(Console.ReadLine(), out array[i])) ;
            }

            //array = array.OrderBy(i => i).ToArray();
            
            for (int i = 0; i < array.Length; i++)
            {
                int min = i;

                for (int j = i + 1; j < array.Length; j++)
                {
                    if (array[j] < array[min])
                    {
                        min = j;
                    }
                }

                int temp   = array[i];
                array[i]   = array[min];
                array[min] = temp;
            }

            foreach (int i in array)
            {
                Console.WriteLine(i);
            }

            //StorageFileHelper.LoadObjectAsyncResult<ObservableCollection<MetronomeConfiguration>> loadObjectAsyncResult = await StorageFileHelper.LoadObjectAsync<ObservableCollection<MetronomeConfiguration>>(FILE_NAME, ApplicationStorage.RoamingFolder);
            //var loadObjectAsyncResult = await StorageFileHelper.LoadObjectAsync<ObservableCollection<MetronomeConfiguration>>(FILE_NAME, ApplicationStorage.RoamingFolder);

            Console.ReadKey();
        }
    }
}

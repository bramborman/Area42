using System;
using WS_Client.WS_Skola;

namespace WS_Client
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            WS_SkolaSoapClient client = new WS_SkolaSoapClient();
            
            foreach (TridaModel item in client.GetTridaModels())
            {
                Console.WriteLine($"{item.Nazev.PadRight(25)}     {item.Tridni?.PadRight(30)}");
            }

            Console.WriteLine();

            int x = 3;
            int y = 5;
            Console.WriteLine($"Addition of {x} and {y} equals {client.Addition(x, y)}");

            Console.ReadKey();
        }
    }
}

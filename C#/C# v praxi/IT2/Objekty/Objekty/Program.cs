using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Objekty
{
    class Program
    {
        static void Main(string[] args)
        {
            Auto autoRidicPepa = new Auto(true);

            autoRidicPepa.barva = "modra";
            autoRidicPepa.karburator = true;
            autoRidicPepa.spotrebaLitruNa100km = 12;


            Auto autoRidicFranta = new Auto(false);

            autoRidicFranta.barva = "cervena";
            autoRidicFranta.karburator = false;
            autoRidicFranta.spotrebaLitruNa100km = 8;


            Auto autoRidicKdokoli = new Auto(true);
            
            Console.WriteLine("Spotřeba Pepova auta v galonech: {0}", autoRidicPepa.GetPocetGalonuNa100());

            Console.WriteLine();
            Console.Write("Zadej počet kilometrů ujetých v Pepově autě: ");
            int kilometry = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Pepa zaplatí {0} Kč.", autoRidicPepa.GetCena(kilometry));

            Console.WriteLine();
            Console.Write("Zadej počet lidí v Pepově autě: ");
            int pocetLidivAute = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Spotřeba Pepova auta je {0} l na člověka.", autoRidicPepa.GetSpotrebaNaLidi(pocetLidivAute));

            Console.WriteLine();
            Console.Write("Zadej barvu auta: ");
            autoRidicKdokoli.barva = Console.ReadLine();
            Console.Write("Zadej spotřebu auta: ");
            float.TryParse(Console.ReadLine(), out autoRidicKdokoli.spotrebaLitruNa100km);

            Console.WriteLine();
            Console.WriteLine("barva:\t\tPepa: {0}\tFranta: {1}\t\tVy: {2}", autoRidicPepa.barva, autoRidicFranta.barva, autoRidicKdokoli.barva);
            Console.WriteLine("spotřeba:\tPepa: {0}\tFranta: {1}\t\tVy: {2}", autoRidicPepa.spotrebaLitruNa100km, autoRidicFranta.spotrebaLitruNa100km, autoRidicKdokoli.spotrebaLitruNa100km);

            Console.Read();
        }
    }
}

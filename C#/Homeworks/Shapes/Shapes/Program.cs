using Shapes.Shapes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Shapes
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Console.Title = "TVARY - Marian Dolinský";
            FontHelper.SetNormalFont();

            Console.InputEncoding  = Encoding.Unicode;
            Console.OutputEncoding = Encoding.Unicode;

            Dictionary<string, Func<ShapeBase>> shapes = new Dictionary<string, Func<ShapeBase>>
            {
                { "Úsečka",         () => new Line()            },
                //{ "Kruh",           () => new Circle()          },
                { "Trojúhelník",    () => new Triangle()        },
                { "Čtverec",        () => new Rectangle(true)   },
                { "Obdélník",       () => new Rectangle(false)  },
                { "Lichoběžník",    () => new Trapezoid()       },
                { "Konec",          () => null                  }
            };

            ShapeBase shape = null;

            do
            {
                shape?.LoadNDraw();

                Console.CursorVisible = false;
                shape = shapes[Menu.Draw(shapes.Keys.ToArray())]();
            } while (shape != null);
        }
    }
}

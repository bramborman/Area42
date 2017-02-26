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
            Console.CursorVisible = false;

            Console.InputEncoding  = Encoding.Unicode;
            Console.OutputEncoding = Encoding.Unicode;

            Dictionary<string, Func<ShapeBase>> shapes = new Dictionary<string, Func<ShapeBase>>
            {
                { "Čára",           () => new Line()        },
                { "Kruh",           () => new Circle()      },
                { "Trojúhelník",    () => new Triangle()    },
                { "Čtverec",        () => new Square()      },
                { "Obdélník",       () => new Rectangle()   },
                { "Lichoběžník",    () => new Trapezoid()   },
                { "Konec",          () => null              }
            };

            ShapeBase shape = null;

            do
            {
                shape?.LoadNDraw();
                shape = shapes[Menu.Draw(shapes.Keys.ToArray())]();
            } while (shape != null);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Popups;

namespace Kalkulačka
{
    class Universal
    {
        public static bool menuhold = false, error = false;
        public static String memory = "";
        public static String[] message = { "Internal error.", "Wrong input entered or input is too long.", "Dividing by zero.", "Second side not selected.", "The value saved in memory is hexadecimal, so it can not be inserted in this box."};

        public async static void Error(int p)
        {
            error = true;
            MessageDialog dialog = new MessageDialog(message[p], "ERROR " + p );
            await dialog.ShowAsync();
        }
    }
}

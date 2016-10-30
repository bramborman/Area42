using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Popups;

namespace Modern_Calculator
{
    class Universal
    {
        public static Boolean error = false, menuhold = false;
        public static String conv = "";
        public static String[] memory = {"", ""},
                               errormess = {
                                    /* 0 */ "Internal error.",
                                    /* 1 */ "Wrong input entered or input is too long.\nPlease do not convert decimal.",
                                    /* 2 */ "Dividing by zero.",
                                    /* 3 */ "Second side not selected.",
                                    /* 4 */ "System of value saved in memory is not the same as the selected system.",
                                    /* 5 */ "Can not root negative number."};

        public async static void Error(int errnum)
        {
            error = true;
            MessageDialog errordiag = new MessageDialog(errormess[errnum], "ERROR " + errnum);
            await errordiag.ShowAsync();
        }
    }
}
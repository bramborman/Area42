using System;
using System.Runtime.InteropServices;

namespace ConsoleApplication36
{
    // Original from https://raw.githubusercontent.com/bramborman/Area42/master/C%23/Homeworks/Shapes/Shapes/FontHelper.cs
    public static class FontHelper
    {
        private const int STD_OUTPUT_HANDLE = -11;
        private const int FONT_SIZE         = 8;

        public const int FONT_DIFFERENCE = 2;

        private static readonly IntPtr invalidHandle = new IntPtr(-1);
        
        private static int originalWindowHeight = Console.WindowHeight;

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern IntPtr GetStdHandle(int nStdHandle);
        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern bool SetCurrentConsoleFontEx(IntPtr consoleOutput, bool maximumWindow, ref CONSOLE_FONT_INFO_EX consoleCurrentFontEx);
        
        public static unsafe void SetFont(string fontName, short x, short y)
        {
            IntPtr stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

            if (stdHandle != invalidHandle)
            {
                CONSOLE_FONT_INFO_EX info = new CONSOLE_FONT_INFO_EX
                {
                    FontFamily = 0,
                    dwFontSize = new COORD(x, y)
                };

                info.cbSize = (uint)Marshal.SizeOf(info);

                Marshal.Copy(fontName.ToCharArray(), 0, new IntPtr(info.FaceName), fontName.Length);
                SetCurrentConsoleFontEx(stdHandle, false, ref info);
            }
        }

        [StructLayout(LayoutKind.Sequential)]
        private struct COORD
        {
            internal short X;
            internal short Y;

            internal COORD(short x, short y)
            {
                X = x;
                Y = y;
            }
        }

        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
        private unsafe struct CONSOLE_FONT_INFO_EX
        {
            internal uint cbSize;
            internal uint nFont;
            internal COORD dwFontSize;
            internal int FontFamily;
            internal int FontWeight;
            internal fixed char FaceName[32];
        }
    }
}

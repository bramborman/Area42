/*
	Name: cnslsz.hpp (Console size) v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 12:51
	Description: Functions for working with console size in Windows console.
*/

#ifndef CNSLSZ_HPP
#define CNSLSZ_HPP

#include "superior.hpp"

COORD getconsolesize()
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
    
	COORD consoleSize =
	{
		bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1,
		bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1
	};
	
	return consoleSize;
}

#endif

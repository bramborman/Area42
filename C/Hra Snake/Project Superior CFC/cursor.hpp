/*
	Name: cursor.hpp v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 16:40
	Description: Functions for controlling cursor in Windows console.
*/

#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "superior.hpp"

void setcursor(bool isVisible, int size)
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = isVisible;
	cursor.dwSize = size;
	
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void setcursor(bool isVisible)
{
	setcursor(isVisible, DCURSOR_SIZE);
}

COORD getcursorposition()
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
	
	return bufferInfo.dwCursorPosition;
}

void movecursor(COORD position)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void movecursor(int x, int y)
{
	COORD position = { x, y };
	movecursor(position);
}

#endif

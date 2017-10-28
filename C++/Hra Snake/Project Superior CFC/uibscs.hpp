/*
	Name: uibscs.hpp (UI basics) v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 16:43
	Description: Basic function, enumerations and structures for creating UI in Windows console.
*/

#ifndef UIBSCS_HPP
#define UIBSCS_HPP

#include "superior.hpp"

char line(LINETYPE type, LINESHAPE shape)
{
	switch (type)
	{
		case SingleLine:
			switch (shape)
			{
				case Horizontal:		return 196;
				case Vertical:			return 179;
				case Edge_Top_Left:		return 218;
				case Edge_Top_Right:	return 191;
				case Edge_Bottom_Left:	return 192;
				case Edge_Bottom_Right:	return 217;
				case T_Horizontal_Up:	return 193;
				case T_Horizontal_Down:	return 194;
				case T_Vertical_Left:	return 180;
				case T_Vertical_Right:	return 195;
				case Cross:				return 197;
				default:				return LINE_ERROR;
			}
		
		case DoubleLine:
			switch (shape)
			{
				case Horizontal:		return 205;
				case Vertical:			return 186;
				case Edge_Top_Left:		return 201;
				case Edge_Top_Right:	return 187;
				case Edge_Bottom_Left:	return 200;
				case Edge_Bottom_Right:	return 188;
				case T_Horizontal_Up:	return 202;
				case T_Horizontal_Down:	return 203;
				case T_Vertical_Left:	return 185;
				case T_Vertical_Right:	return 204;
				case Cross:				return 206;
				default:				return LINE_ERROR;
			}
		
		case Block:	return BLOCK_NORMAL;
		case None:	return ' ';
		default:	return LINE_ERROR;
	}
}

// These two variables shouldn't be visible from another files
// But in Dev-C++ 'static' it most likely doesn't work as it is supposed to
// Maybe because of this files are compiled by C++ compiler instead of C conpiler
static COLOR foregroundColor = White;
static COLOR backgroundColor = Black;

COLOR getforeground()
{
	return foregroundColor;
}

COLOR getbackground()
{
	return backgroundColor;
}

void fillforeground(COLOR foreground, COORD startPosition, int count)
{
    foregroundColor = foreground;
    
	DWORD written;
	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foregroundColor + (backgroundColor << 4), count, startPosition, &written);
}

void fillforeground(COLOR foreground, int startPositionX, int startPositionY, int count)
{
    COORD startPosition = { startPositionX, startPositionY };
    fillforeground(foreground, startPosition, count);
}

void fillbackground(COLOR background, COORD startPosition, int count)
{
    backgroundColor = background;
    
	DWORD written;
	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foregroundColor + (backgroundColor << 4), count, startPosition, &written);
}

void fillbackground(COLOR background, int startPositionX, int startPositionY, int count)
{
    COORD startPosition = { startPositionX, startPositionY };
    fillbackground(background, startPosition, count);
}

void setforeground(COLOR foreground)
{
    foregroundColor = foreground;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foregroundColor + (backgroundColor << 4));
}

void setbackground(COLOR background)
{
    backgroundColor = background;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foregroundColor + (backgroundColor << 4));
}

void draw(const VISUAL &v)
{
	COLOR foregroundBackup = getforeground();
	
	setforeground(v.Color);
	putchar(v.Char);
	
	setforeground(foregroundBackup);
}

SMALL_RECT measure(int left, int right, int width, int top, int bottom, int height, COORD margin, HORIZONTALALIGNMENT horizontalAlignment, VERTICALALIGNMENT verticalAlignment)
{
	SMALL_RECT output;
	COORD consoleSize = getconsolesize();
	
	switch (horizontalAlignment)
	{
		case HLeft:		output.Left = left + margin.X;									break;
		case HCenter:	output.Left = ((right - left - width) / 2) + left + margin.X;	break;
		case HRight:	output.Left = right - width + margin.X;							break;
		default: 		return RECT_ERROR;
	}
	
	switch (verticalAlignment)
	{
		case VTop:		output.Top = top + margin.Y;									break;
		case VCenter:	output.Top = ((bottom - top - height) / 2) + top + margin.Y;	break;
		case VBottom:	output.Top = bottom - height + margin.Y;						break;
		default:		return RECT_ERROR;
	}
	
	output.Right = output.Left + (width - 1);
	output.Bottom = output.Top + (height - 1);
	
	return output;
}

SMALL_RECT measure(int width, int height, COORD margin, HORIZONTALALIGNMENT horizontalAlignment, VERTICALALIGNMENT verticalAlignment)
{
	COORD consoleSize = getconsolesize();
	return measure(0, consoleSize.X, width, 0, consoleSize.Y, height, margin, horizontalAlignment, verticalAlignment);
}

#endif

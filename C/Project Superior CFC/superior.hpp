/*
	Name: superior.hpp (Project Superior Core for C) v1.0 beta 1
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 23:44
	Description: Lots of usefull functions, enumerations and structures for creating simple UI in Windows console.
	
	TODO:
		more rows in button, textblock, textbox text, in centers
		listbox
		combobox
		textbox
		fontwriter - 3d array for fonts
		popups, notifications
*/

#ifndef SUPERIOR_HPP
#define SUPERIOR_HPP

#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include <conio.h>

typedef enum
{
	Backspace	= 8,
	Enter		= 13,
	Esc			= 27,
	Space		= 32,
	Up			= 72, // *
	Left		= 75, // **
	Right		= 77, // *** sending -32 || (unsigned)224 before these values
	Down		= 80, // **
	Delete 		= 127 // *
} KEY;

typedef enum
{
	SingleLine,
	DoubleLine,
	Block,
	None
} LINETYPE;

typedef enum
{
	Horizontal,
	Vertical,
	Edge_Top_Left,
	Edge_Top_Right,
	Edge_Bottom_Left,
	Edge_Bottom_Right,
	T_Horizontal_Up,
	T_Horizontal_Down,
	T_Vertical_Left,
	T_Vertical_Right,
	Cross
} LINESHAPE;

typedef enum
{
	HLeft,
	HCenter,
	HRight
} HORIZONTALALIGNMENT;

typedef enum
{
	VTop,
	VCenter,
	VBottom
} VERTICALALIGNMENT;

typedef enum
{
	Visible,
	Collapsed
} VISIBILITY;

typedef enum
{
    Black,
    DarkBlue,
    DarkGreen,
    DarkCyan,
    DarkRed,
    DarkMagenta,
    DarkYellow,
    Gray,
    DarkGray,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Yellow,
    White
} COLOR;

typedef struct
{
	char Char;
	COLOR Color;
} VISUAL;

typedef struct
{
	LINETYPE BorderType;
	VISIBILITY Visibility;
	
	bool BackgroundUnderBorder;
	COLOR BorderColor;
	COLOR Background;
	
	int Width;
	int Height;
	
	HORIZONTALALIGNMENT HorizontalAlignment;
	VERTICALALIGNMENT VerticalAlignment;
	COORD Margin;
} BORDER;

typedef struct
{
	char *Text;
	
	VISIBILITY Visibility;
	
	COLOR Foreground;
	COLOR Background;
	
	int Width;
	int Height;
	
	HORIZONTALALIGNMENT HorizontalAlignment;
	VERTICALALIGNMENT VerticalAlignment;
	COORD Margin;
} TEXTBLOCK;

typedef struct
{
	char *Text;
	HORIZONTALALIGNMENT HorizontalTextAlignment;
	VERTICALALIGNMENT VerticalTextAlignment;
	
	bool BackgroundUnderBorder;
	bool IsEnabled;
	bool IsFocused;
	
	LINETYPE BorderType;
	VISIBILITY Visibility;
	
	COLOR Foreground;
	COLOR UnfocusedForeground;
	COLOR DisabledForeground;
	
	COLOR Background;
	COLOR UnfocusedBackground;
	COLOR DisabledBackground;
	
	COLOR BorderColor;
	COLOR UnfocusedBorderColor;
	COLOR DisabledBorderColor;
	
	int Width;
	int Height;
	
	HORIZONTALALIGNMENT HorizontalAlignment;
	VERTICALALIGNMENT VerticalAlignment;
	COORD Margin;
} BUTTON;

/* advio.hpp */
void cls();
char getkey(char key);
char getkey();
char *createline(char start, char middle, char end, int countOfMiddle);
char *createline(char ch, int count);
void drawline(char ch, int count);
COORD hcenter(int left, int right, int width);
COORD hcenter(int left, int right, int width, const char *format, ...);
COORD hcenter(int left, int right, const char *format, ...);
COORD hcenter(int width);
COORD hcenter(int width, const char *format, ...);
COORD hcenter(const char *format, ...);
COORD vcenter(int top, int bottom, int height);
COORD vcenter(int height);
COORD center(int left, int right, int width, int top, int bottom, int height);
COORD center(int left, int right, int width, int top, int bottom, int height, const char *format, ...);
COORD center(int left, int right, int top, int bottom, const char *format, ...);
COORD center(int width, int height);
COORD center(int width, int height, const char *format, ...);
COORD center(const char *format, ...);
COORD vhcenter(int left, int right, const char *format, va_list args);

/* border.hpp */
BORDER newBORDER();
void draw(const BORDER &b);
void erase(const BORDER &b);

/* button.hpp */
BUTTON newBUTTON();
void draw(const BUTTON &b);
void erase(const BUTTON &b);

/* cnslsz.hpp */
COORD getconsolesize();

/* cursor.hpp */
void setcursor(bool isVisible, int size);
void setcursor(bool isVisible);
COORD getcursorposition();
void movecursor(COORD position);
void movecursor(int x, int y);

/* operators.hpp */
bool operator ==(COORD c1, COORD c2);
bool operator !=(COORD c1, COORD c2);
bool operator <(COORD c1, COORD c2);
bool operator >(COORD c1, COORD c2);
bool operator <=(COORD c1, COORD c2);
bool operator >=(COORD c1, COORD c2);
bool operator ==(SMALL_RECT r1, SMALL_RECT r2);
bool operator !=(SMALL_RECT r1, SMALL_RECT r2);

/* strext.hpp */
char *stradd(char *str, char ch, int index);
char *strrem(char *str, int index);
char *strndup(const char *source, int count);
char *strcat(char *dest, int sourcesCount, const char *source, ...);

/* textblock.hpp */
TEXTBLOCK newTEXTBLOCK();
void draw(const TEXTBLOCK &t);
void erase(const TEXTBLOCK &t);

/* uibscs.hpp */
char line(LINETYPE type, LINESHAPE shape);
COLOR getforeground();
COLOR getbackground();
void fillforeground(COLOR foreground, COORD startPosition, int count);
void fillforeground(COLOR foreground, int startPositionX, int startPositionY, int count);
void fillbackground(COLOR background, COORD startPosition, int count);
void fillbackground(COLOR background, int startPositionX, int startPositionY, int count);
void setforeground(COLOR foreground);
void setbackground(COLOR background);
void draw(const VISUAL &v);
SMALL_RECT measure(int left, int right, int width, int top, int bottom, int height, COORD margin, HORIZONTALALIGNMENT horizontalAlignment, VERTICALALIGNMENT verticalAlignment);
SMALL_RECT measure(int width, int height, COORD margin, HORIZONTALALIGNMENT horizontalAlignment, VERTICALALIGNMENT verticalAlignment);

// Returned from measure functions when arguments are out of enums ranges
const SMALL_RECT RECT_ERROR = { -1, -1, -1, -1 };
// Returned from line function when arguments are out of íenums ranges
const char LINE_ERROR = 'X';

const COORD COORD_ORIGIN = { 0, 0 };

/* Drawing chars */
const char DOT_SMALL	= 250;
const char DOT_BIG		= 249;

const char BLOCK_HALF_TOP		= 223;
const char BLOCK_HALF_BOTTOM	= 220;
const char BLOCK_HALF_LEFT		= 221;
const char BLOCK_HALF_RIGHT		= 222;
const char BLOCK_HALF_CENTER	= 254;

const char BLOCK_PERFORATED_MUCH	= 176;
const char BLOCK_PERFORATED_NORMAL	= 177;
const char BLOCK_PERFORATED_FEW		= 178;
const char BLOCK_NORMAL				= 219;

/* Defaults for UI elements */
const int DCURSOR_SIZE = 20;

const COLOR DCOLOR_FORE_FOCUSED		= White;
const COLOR DCOLOR_FORE_UNFOCUSED	= Gray;
const COLOR DCOLOR_FORE_DISABLED	= DarkGray;

const bool DBACKGROUND_UNDER_BORDER	= true;
const COLOR DCOLOR_BACK_FOCUSED		= Black;
const COLOR DCOLOR_BACK_UNFOCUSED	= Black;
const COLOR DCOLOR_BACK_DISABLED	= Black;

const int DWIDTH  = 10;
const int DHEIGHT = 3;

const LINETYPE DBORDER_TYPE = SingleLine;

#include "advio.hpp"
#include "border.hpp"
#include "button.hpp"
#include "cnslsz.hpp"
#include "cursor.hpp"
#include "operators.hpp"
#include "strext.hpp"
#include "textblock.hpp"
#include "textbox.hpp"
#include "uibscs.hpp"

#endif

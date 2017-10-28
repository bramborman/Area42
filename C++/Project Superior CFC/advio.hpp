/*
	Name: advio.hpp (Advanced I/O) v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 23:28
	Description: Advanced I/O functions for Windows console.
*/

#ifndef ADVIO_HPP
#define ADVIO_HPP

#include "superior.hpp"

void cls()
{
	DWORD attribsWritten;
	COORD consoleSize = getconsolesize();
	
	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), getbackground() + (getbackground() << 4), consoleSize.X * consoleSize.Y, COORD_ORIGIN, &attribsWritten);
	system("cls");
}

char getkey(char key)
{
	if (key == -32 || key == 224)
	{
		return getch();
	}
	
	return key;
}

char getkey()
{
	return getkey(getch());
}

char *createline(char start, char middle, char end, int countOfMiddle)
{
	if (countOfMiddle < 0)
	{
		return NULL;
	}
	
	char *output = (char *)malloc(countOfMiddle + 3);
	
	if (output == NULL)
	{
		return NULL;
	}
	
	output = ((char *)memset(output + 1, middle, countOfMiddle)) - 1;
	
	*output = start;
	*(output + countOfMiddle + 1) = end;
	*(output + countOfMiddle + 2) = 0;
	
	return output;
}

char *createline(char ch, int count)
{
	if (count < 0)
	{
		return NULL;
	}
	
	char *output = (char *)malloc(count + 1);
	
	if (output == NULL)
	{
		return NULL;
	}
	
	output = (char *)memset(output, ch, count);
	*(output + count) = 0;
	
	return output;
}

void drawline(char ch, int count)
{
	if (count <= 0)
	{
		return;
	}
	
	while(count-- > 0)
	{
		putchar(ch);
	}
}

COORD hcenter(int left, int right, int width)
{
	COORD position = getcursorposition();
	position.X = (right - left - width) / 2 + left;
	
	movecursor(position);
	return position;
}

COORD hcenter(int left, int right, int width, const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	
	COORD position = hcenter(left, right, width);
	vprintf(format, ap);
	
	va_end(ap);
	return position;
}

COORD hcenter(int left, int right, const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	
	COORD position = vhcenter(left, right, format, ap);
	
	va_end(ap);
	return position;
}

COORD hcenter(int width)
{
	return hcenter(0, getconsolesize().X, width);
}

COORD hcenter(int width, const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	
	COORD position = hcenter(width);
	vprintf(format, ap);
	
	va_end(ap);
	return position;
}

COORD hcenter(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	
	COORD position = vhcenter(0, getconsolesize().X, format, ap);
	
	va_end(ap);
	return position;
}

COORD vcenter(int top, int bottom, int height)
{
	COORD position = getcursorposition();
	position.Y = (bottom - top - height) / 2 + top;
	
	movecursor(position);
	return position;
}

COORD vcenter(int height)
{
	return vcenter(0, getconsolesize().Y, height);
}

COORD center(int left, int right, int width, int top, int bottom, int height)
{
	COORD position =
	{
		hcenter(left, right, width).X,
		vcenter(top, bottom, height).Y
	};
	
	return position;
}

COORD center(int left, int right, int width, int top, int bottom, int height, const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	
	COORD position = center(left, right, width, top, bottom, height);
	vprintf(format, ap);
	
	va_end(ap);
	return position;
}

COORD center(int left, int right, int top, int bottom, const char *format, ...)
{
	COORD position;
	position.Y = vcenter(top, bottom, 1).Y;
	
	va_list ap;
	va_start(ap, format);
	
	position.X = vhcenter(left, right, format, ap).X;
	
	va_end(ap);
	return position;
}

COORD center(int width, int height)
{
	COORD consoleSize = getconsolesize();
	return center(0, consoleSize.X, width, 0, consoleSize.Y, height);
}

COORD center(int width, int height, const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	
	COORD consoleSize = getconsolesize();
	COORD position = center(0, consoleSize.X, width, 0, consoleSize.Y, height);
	
	vprintf(format, ap);
	
	va_end(ap);
	return position;
}

COORD center(const char *format, ...)
{
	COORD position;
	position.Y = vcenter(1).Y;
	
	va_list ap;
	va_start(ap, format);
	
	position.X = vhcenter(0, getconsolesize().X, format, ap).X;
	
	va_end(ap);
	return position;
}

COORD vhcenter(int left, int right, const char *format, va_list args)
{
	size_t length = (size_t)(strlen(format) * 1.5);
	char *output = (char *)malloc(length);
	
	if (output == NULL)
	{
		return COORD_ORIGIN;
	}
	
	while (vsprintf(output, format, args) < 0)
	{
		length = (size_t)(length * 1.5);
		
		if ((output = (char *)realloc(output, length)) == NULL)
		{
			return COORD_ORIGIN;
		}
	}
	
	COORD position = hcenter(left, right, strlen(output));
	
	if (position != COORD_ORIGIN)
	{
		fputs(output, stdout);
	}
	
	va_end(args);
	free(output);
	
	return position;
}

#endif

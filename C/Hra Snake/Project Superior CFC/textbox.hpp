/*
	Name: textbox.hpp v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 23:44
	Description: Basic UI element for Windows console.
*/

#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "superior.hpp"
/*
TEXTBOX newTEXTBOX()
{
	TEXTBOX t;
	
	return t;
}

void draw(const TEXTBOX &t)
{
	/*
	const char LINE_HORIZONTAL = 196;
	const char LINE_VERTICAL = 179;
	const char LINE_EDGE_LEFT_TOP = 218;
	const char LINE_EDGE_LEFT_BOTTOM = 192;
	const char LINE_EDGE_RIGHT_TOP = 191;
	const char LINE_EDGE_RIGHT_BOTTOM = 217;
	const int CENTERING = 6;
	
	bool renderMain = true, renderSelection = true;
	bool checkKey = false;
	char playersNames[2][NAME_LENGTH_MAX] = {0};
	int selection = 0, player = 0, horizontalCursorPosition = 0;
	COORD cursorPosition, textCursorPosition;
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
			
			vcenter(5);
			hcenter("SELECT YOUR NAME");
			fputs("\n\n\n", stdout);
			
			// Get coordinates for TextBox
			hcenter(NAME_LENGTH_MAX);
			textCursorPosition = commonCursorPosition;
			
			// Print TextBox
			movecursor(textCursorPosition.X - 1, textCursorPosition.Y - 1);
			putchar(LINE_EDGE_LEFT_TOP);
			
			for (int i = 0; i < NAME_LENGTH_MAX; i++)
			{
				putchar(LINE_HORIZONTAL);
			}
			
			putchar(LINE_EDGE_RIGHT_TOP);
			
			movecursor(textCursorPosition.X - 1, textCursorPosition.Y);
			putchar(LINE_VERTICAL);
			
			movecursor(textCursorPosition.X + NAME_LENGTH_MAX, textCursorPosition.Y);
			putchar(LINE_VERTICAL);
			
			movecursor(textCursorPosition.X - 1, textCursorPosition.Y + 1);
			putchar(LINE_EDGE_LEFT_BOTTOM);
			
			for (int i = 0; i < NAME_LENGTH_MAX; i++)
			{
				putchar(LINE_HORIZONTAL);
			}
			
			putchar(LINE_EDGE_RIGHT_BOTTOM);
			
			fputs("\n\n\n\n\n", stdout);
			hcenter(CENTERING, "Confirm\n");
			
			cursorPosition = commonCursorPosition;
			cursorPosition.X -= 2;
			
			hcenter(CENTERING, "Back");
			
			consoleSizeChanged = false;
			renderMain = false;
			renderSelection = true;
		}
		
#ifdef DEBUG
		DEBUG_MAIN;
		printf("\ntextCursorPosition: %*d %*d", consoleSizeXPrecision, textCursorPosition.X, consoleSizeXPrecision, textCursorPosition.Y);
		printf("\nstrlen(playersNames[%d]): %2d | ", player, strlen(playersNames[player]));
		printf("horizontalCursorPosition: %2d | ", horizontalCursorPosition);
		printf("\nplayersNames[0]: %-*s", NAME_LENGTH_MAX, playersNames[0]);
		printf("\nplayersNames[1]: %-*s", NAME_LENGTH_MAX, playersNames[1]);
#endif
			
		if (renderSelection)
		{
			// Print player name
			movecursor(textCursorPosition);
			printf("%-*s", NAME_LENGTH_MAX, playersNames[player]);
			
			movecursor(cursorPosition.X, cursorPosition.Y + (selection - 1 == 0 ? 1 : 0));
			putchar(' ');
			
			if (selection != 0)
			{
				movecursor(cursorPosition.X, cursorPosition.Y + selection - 1);
				putchar('>');
			}
			
			renderSelection = false;
		}
		
		if (selection == 0)
		{
			movecursor(textCursorPosition.X + (horizontalCursorPosition == NAME_LENGTH_MAX ? horizontalCursorPosition - 1 : horizontalCursorPosition), textCursorPosition.Y);
			setcursor(true);////////////////////////////////////// Repair flashing
			
			if (kbhit())
			{
				key = getarrow(getch());
				checkKey = true;
			}
		}
		else
		{
			setcursor(false);
			
			if (kbhit())
			{
				key = getkey(getcheat(getch()));
				checkKey = true;
			}
		}
		
		setforeground(White);
		
		if (checkKey)
		{
			checkKey = false;
			
			if ((key == Enter && selection == 2) || key == Esc)
			{
				return false;
			}
			else if (key == Enter)
			{
				if (snakecreator(sleep, hotseat, borders, (const char **)playersNames))
				{
					return true;
				}
				
				renderMain = true;
			}
			else if (key == Up && selection != 0)
			{
				selection--;
				renderSelection = true;
			}
			else if (key == Down && selection != 2)
			{
				selection++;
				renderSelection = true;
			}
			else if (key == Left && horizontalCursorPosition != 0)
			{
				if (horizontalCursorPosition == NAME_LENGTH_MAX)
				{
					// If TextBox is full, cursor's X coordinate is decreased by one so skip this one
					horizontalCursorPosition--;
				}
				
				horizontalCursorPosition--;
			}
			else if (key == Right && horizontalCursorPosition != strlen(playersNames[player]))
			{
				if (strlen(playersNames[player]) == NAME_LENGTH_MAX && horizontalCursorPosition == strlen(playersNames[player]) - 2)
				{
					horizontalCursorPosition++;
				}
				
				horizontalCursorPosition++;
			}
			else if (key == Backspace)
			{
				if (horizontalCursorPosition != 0)
				{
					if (horizontalCursorPosition == strlen(playersNames[player]))
					{
						// Remove last char
						playersNames[player][horizontalCursorPosition - 1] = '\0';
					}
					else
					{
						// Remove char inside string
						strrem(playersNames[player], horizontalCursorPosition);
					}
					
					horizontalCursorPosition--;
				}///////////////////////////////////// horizontalCursorPosition max NAME_LENGTH_MAX - 1 ?
				
				renderSelection = true;
			}
			else if (key == DELETE)
			{
				if (horizontalCursorPosition != strlen(playersNames[player]))
				{
					strrem(playersNames[player], horizontalCursorPosition + 1);
				}
				
				renderSelection = true;
			}
			else if (selection == 0 && horizontalCursorPosition != NAME_LENGTH_MAX && !IF_ARROW(key))
			{
				// Add char to string
				playersNames[player][horizontalCursorPosition] = key;
				horizontalCursorPosition++;
				
				renderSelection = true;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

void erase(const TEXTBOX &t)
{
	
}
*/
#endif

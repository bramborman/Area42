//
//
//	(c) Marian Dolinský 2015
//
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

const int COUNT = 100;
int CONSOLEWIDTH, CONSOLEHEIGHT;
int i, j, k, min, temp;

void checkconsolesize(bool change);
void center(const int SPACE, const char TEXT[]);
void repeat(const char CHAR, const int COUNT);
int verticalcenter(const int ROWS);
void difficulty(const bool HOTSEAT);
void controls();
void about();
void changelog();
void pausemenu(const bool HOTSEAT);
void quitmessage(const int ACTION, const bool PLAYING, const bool HOTSEAT);
void snake(const int WAIT);
void hotseat(const int WAIT);

int main()
{
	// Hides the cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &info);
	
	// Get console sizes and assign CONSOLEWIDTH and CONSOLEHEIGHT
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    CONSOLEWIDTH = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    CONSOLEHEIGHT = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    
	checkconsolesize(false);
	
	const int CENTER = 14;
	int VERTICALCENTER = verticalcenter(13);
	int selection = 1;
	
	// Must be set to Czech because of 'ý'
	setlocale(LC_ALL, "Czech");
	srand(time(0));
	system("color 0F");
	
	while("snake")
	{
		system("cls");
		
		repeat('\n', VERTICALCENTER);
		center(0, "    ///////  //    //  ////////  //   //  ///////\n");
		center(0, "   //       ///   //  //    //  // //    //      \n");
		center(0, "  ///////  // // //  ////////  ///      /////    \n");
		center(0, "      //  //  ////  //    //  // //    //        \n");
		center(0, "///////  //    //  //    //  //   //  ///////    \n");
		printf("\n\n\n");
		
		center(CENTER, selection == 1 ? "> Start game\n" : "  Start game\n");
		center(CENTER, selection == 2 ? "> Hotseat\n" : "  Hotseat\n");
		center(CENTER, selection == 3 ? "> Controls\n" : "  Controls\n");
		center(CENTER, selection == 4 ? "> About\n" : "  About\n");
		printf("\n");
		center(CENTER, selection == 5 ? "> Quit game" : "  Quit game");
		
		temp = getch();
		
		if(temp >= 97 && temp <= 122)
		{
			temp -= 32;
		}
		
		// 13 - carriage return (ENTER) 27 - ESC
		if((temp == 13 && selection == 5) || temp == 27)
		{
			quitmessage(5, false, false);
		}
		else if(temp == 13)
		{
			if(selection == 1)
			{
				difficulty(false);
			}
			else if(selection == 2)
			{
				difficulty(true);
			}
			else if(selection == 3)
			{
				controls();
			}
			else if(selection == 4)
			{
				about();
				VERTICALCENTER = verticalcenter(13);
			}
		}
		else if(temp == 'W' && selection != 1)
		{
			selection--;
		}
		else if(temp == 'S' && selection != 5)
		{
			selection++;
		}
	}
}

void checkconsolesize(bool change)
{
    while(change == true || CONSOLEWIDTH < 65 || CONSOLEHEIGHT < 25)
    {
    	system("cls");
    	
    	repeat('\n', verticalcenter(2));
    	center(26, "Your console size is ");
    	printf("%dx%d\n", CONSOLEWIDTH, CONSOLEHEIGHT);
    	center(0, "Minimal required size is 65x25\n");
    	center(0, "Change the size and press any key to continue . . .");
    	getch();
    	
		CONSOLE_SCREEN_BUFFER_INFO csbi;
	    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	    CONSOLEWIDTH = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	    CONSOLEHEIGHT = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	    
	    change = false;
	}
}

void center(const int SPACE, const char TEXT[])
{
	// WARNING!!! Don't use more than one '\n' at the end of the TEXT[] string
	for(int i = 0; i < (CONSOLEWIDTH - (SPACE == 0 ? strlen(TEXT) : SPACE)) / 2; i++)
	{
		printf(" ");
	}
	
	printf("%s", TEXT);
}

void repeat(const char CHAR, const int REPEAT)
{
	for(int i = 0; i < REPEAT; i++)
	{
		printf("%c", CHAR);
	}
}

int verticalcenter(const int ROWS)
{
	if(CONSOLEHEIGHT % 2 != ROWS % 2)
	{
		return ((float)(CONSOLEHEIGHT - ROWS) / 2) + 0.5;
	}
	
	// Calculate space between top concole edge and first used line
	return (CONSOLEHEIGHT - ROWS) / 2;
}

void difficulty(const bool HOTSEAT)
{
	const int CENTER = 10;
	const int VERTICALCENTER = verticalcenter(7);
	int selection = 2;
	
	while("snake")
	{
		system("cls");
		
		repeat('\n', VERTICALCENTER);
		center(0, "CHOOSE DIFFICULTY:");
		printf("\n\n");
		
		center(CENTER, selection == 1 ? "> Easy\n" : "  Easy\n");
		center(CENTER, selection == 2 ? "> Medium\n" : "  Medium\n");
		center(CENTER, selection == 3 ? "> Hard\n" : "  Hard\n");
		printf("\n");
		center(CENTER, selection == 4 ? "> Back" : "  Back");
		
		temp = getch();
		
		if(temp >= 97 && temp <= 122)
		{
			temp -= 32;
		}
		
		// 13 - carriage return (ENTER) 27 - ESC
		if((temp == 13 && selection == 4) || temp == 27)
		{
			return;
		}
		else if(temp == 13)
		{
			if(HOTSEAT == false)
			{
				snake(selection == 1 ? 200 : (selection == 2 ? 120 : 70));
			}
			else
			{
				hotseat(selection == 1 ? 200 : (selection == 2 ? 120 : 70));
			}
			
			return;
		}
		else if(temp == 'W' && selection != 1)
		{
			selection--;
		}
		else if(temp == 'S' && selection != 4)
		{
			selection++;
		}
	}
}

void controls()
{
	const int CENTER = 35;
	
	system("cls");
	
	repeat('\n', verticalcenter(8));
	center(0, "CONTROLS:");
	printf("\n\n");
	
	center(CENTER, "Player 1:          WASD\n");
	center(CENTER, "Player 2:          8456\n");
	center(CENTER, "Pause game:        ESC\n");
	center(CENTER, "Menu navigation:   WASD, ENTER, ESC\n");
	printf("\n");
	
	center(0, "> Back  ");

	while("snake")
	{	
		temp = getch();
		
		// 13 - carriage return (ENTER) 27 - ESC
		if(temp == 13 || temp == 27)
		{
			return;
		}
	}
}

void about()
{
	const int CENTER = 24;
	int VERTICALCENTER = verticalcenter(10);
	int selection = 3;
	
	while("snake")
	{
		system("cls");
		
		repeat('\n', VERTICALCENTER);
		center(0, "ABOUT:");
		printf("\n\n");
		
		center(CENTER, "Snake v1.4 'It grows'\n");
		center(CENTER, "Current branch: stable\n");
		center(CENTER, "(c) Marian Dolinský 2015\n");
		printf("\n");
    	center(CENTER, "Console size: ");
    	printf("%dx%d\n\n", CONSOLEWIDTH, CONSOLEHEIGHT);
		
		center(17, selection == 1 ? "> Change console size\n" : "  Change console size\n");
		center(17, selection == 2 ? "> Changelog\n" : "  Changelog\n");
		center(17, selection == 3 ? "> Back" : "  Back");
	
		temp = getch();
		
		if(temp >= 97 && temp <= 122)
		{
			temp -= 32;
		}
		
		// 13 - carriage return (ENTER) 27 - ESC
		if((temp == 13 && selection == 3) || temp == 27)
		{
			return;
		}
		else if(temp == 13)
		{
			if(selection == 1)
			{
				checkconsolesize(true);
				VERTICALCENTER = verticalcenter(10);
			}
			else
			{
				changelog();
			}
			
			selection = 3;
		}
		else if(temp == 'W' && selection != 1)
		{
			selection--;
		}
		else if(temp == 'S' && selection != 3)
		{
			selection++;
		}
	}
}

void changelog()
{
	const int CENTER = 37;
	
	system("cls");
	
	repeat('\n', verticalcenter(21));
	center(0, "CHANGELOG:");
	printf("\n\n");
	
	center(CENTER + 5, "1.4 'It grows':\n");
	center(CENTER, "- Game is now responsive designed\n");
	center(CENTER, "- Code were optimised\n");
	center(CENTER + 5, "1.3 'Let me continue':\n");
	center(CENTER, "- Hotseat continue if one player dies\n");
	center(CENTER, "- Added changelog\n");
	center(CENTER, "- Some bugs were fixed\n");
	center(CENTER + 5, "1.2 'Do it twice':\n");
	center(CENTER, "- Added multiplayer\n");
	center(CENTER, "- Code is more effective\n");
	center(CENTER, "- Some bugs were fixed\n");
	center(CENTER + 5, "1.1 'When meowside flies':\n");
	center(CENTER, "- Added menus\n");
	center(CENTER, "- Some bugs were fixed\n");
	center(CENTER + 5, "1.0 'First release':\n");
	center(CENTER, "- Only singleplayer\n");
	center(CENTER, "- Without menus\n");
	printf("\n");
	
	center(0, "> Back  ");

	while("snake")
	{	
		temp = getch();
		
		// 13 - carriage return (ENTER) 27 - ESC
		if(temp == 13 || temp == 27)
		{
			return;
		}
	}
}

void pausemenu(const bool HOTSEAT)
{
	const int CENTER = 12;
	const int VERTICALCENTER = verticalcenter(7);
	int selection = 1;
	
	while("snake")
	{
		system("cls");
		
		repeat('\n', VERTICALCENTER);
		center(0, "PAUSE MENU:");
		printf("\n\n");
		
		center(CENTER, selection == 1 ? "> Resume\n" : "  Resume\n");
		center(CENTER, selection == 2 ? "> Restart\n" : "  Restart\n");
		center(CENTER, selection == 3 ? "> Controls\n" : "  Controls\n");
		center(CENTER, selection == 4 ? "> Go to main menu\n" : "  Go to main menu\n");
		center(CENTER, selection == 5 ? "> Quit game" : "  Quit game");
		
		temp = getch();
		
		if(temp >= 97 && temp <= 122)
		{
			temp -= 32;
		}
		
		// 13 - carriage return (ENTER) 27 - ESC
		if((temp == 13 && selection == 1) || temp == 27)
		{
			system("cls");
			return;
		}
		if(temp == 13)
		{
			if(selection == 3)
			{
				controls();
			}
			else if(selection == 2 ||selection == 4 || selection == 5)
			{
				quitmessage(selection, true, HOTSEAT);
			}
		}
		else if(temp == 'W' && selection != 1)
		{
			selection--;
		}
		else if(temp == 'S' && selection != 5)
		{
			selection++;
		}
	}
}

void quitmessage(const int ACTION, const bool PLAYING, const bool HOTSEAT)
{
	// ACTION 2 - restart game
	// ACTION 4 - go to main menu
	// ACTION 5 - quit game
	
	const int VERTICALCENTER = verticalcenter(4);
	int selection = 2;
	
	while("snake")
	{
		system("cls");
		
		repeat('\n', VERTICALCENTER);
		center(0, ACTION == 2 ? "Are you sure you want to restart the game?" : (ACTION == 4 ?  "Are you sure you want to go to main menu?" : "Are you sure you want to quit the game?"));
		
		if(PLAYING == true)
		{
			printf("\n");
			center(0, "Your game progress will be lost!");
		}
		
		printf("\n\n");
		center(20, selection == 1 ? "> Yes" : "  Yes");
		
		repeat(' ', 9);
		printf(selection == 2 ? "> No" : "  No");
		
		temp = getch();
		
		if(temp >= 97 && temp <= 122)
		{
			temp -= 32;
		}
		
		// 13 - carriage return (ENTER) 27 - ESC
		if((temp == 13 && selection == 2) || temp == 27)
		{
			return;
		}
		else if(temp == 13)
		{
			if(ACTION == 2)
			{
				difficulty(HOTSEAT);
			}
			else if(ACTION == 4)
			{
				main();
			}
			else
			{
				exit(0);
			}
			
			return;
		}
		else if(temp == 'A' && selection != 1)
		{
			selection--;
		}
		else if(temp == 'D' && selection != 2)
		{
			selection++;
		}
	}
}

void snake(const int WAIT)
{
	bool setNewBerry, collision;
	int yRelative, overflow, inRow, active;
	int x[COUNT + 1], y[COUNT + 1], xRelative[COUNT + 1], order[COUNT + 1];
	char course[COUNT], histCourse[COUNT];	
	
	// First-run reset
	system("cls");
	
	setNewBerry = true;
	collision = false;
	active = 3;
	
	for(i = 0; i < COUNT + 1; i++)
	{
		x[i] = y[i] = CONSOLEWIDTH + 1;
		order[i] = i;
		
		if(i != COUNT)
		{
			course[i] = 'X';
			histCourse[i] = 'X';
		}
	}
	
	for(i = 0; i < active; i++)
	{
		x[i] = (CONSOLEWIDTH / 2) - 1;
		y[i] = i + ((CONSOLEHEIGHT - active) / 2);
		course[i] = 'W';
	}
	
	while("snake")
	{
		// Generate new x and y for berry
		if(setNewBerry == true)
		{
			do
			{
				x[COUNT] = rand() % CONSOLEWIDTH;
				
				// Determine if there is collision with some body
				for(i = 0; i < active; i++)
				{
					if(x[COUNT] == x[i])
					{
						break;
					}
				}
			// Generate new X for berry if there is collision with some body or when berry is in right bottom corner
			} while(i != active);
			
			do
			{
				y[COUNT] = rand() % CONSOLEHEIGHT;
				
				// Determine if there is collision with some body
				for(i = 0; i < active; i++)
				{
					if(y[COUNT] == y[i])
					{
						break;
					}
				}
			// Generate new Y for berry if there is collision with some body or when berry is in right bottom corner
			// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
			} while(i != active || (x[COUNT] == CONSOLEWIDTH - 1 && y[COUNT] == CONSOLEHEIGHT - 1));
			
			setNewBerry = false;
		}
		
		// Arrange by Y
		for(i = 0; i < COUNT + 1; i++)
		{
			min = i;
			
			// Find smallest Y and write its index to min
			for(j = i + 1; j < COUNT + 1; j++)
			{
				if(y[j] < y[min])
				{
					min = j;
				}
			}
			
			if(min != i)
			{
				temp = y[i];
				y[i] = y[min];
				y[min] = temp;
				
				temp = x[i];
				x[i] = x[min];
				x[min] = temp;
				
				temp = course[i];
				course[i] = course[min];
				course[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Print snake
		for(i = 0; i < active + 1; i++)
		{
			// Continue if there were more bodies in previous row
			if((y[i] == y[i - 1]) && !(y[0] == 0 && i == 0))
			{
				continue;
			}
			
			// Reset values
			inRow = 0;
			
			for(j = 0; j < COUNT + 1; j++)
			{
				xRelative[j] = CONSOLEWIDTH + 1;
			}
			
			// Assign relative positions
			yRelative = (i == 0 ? y[i] : (y[i] - y[i - 1]));
			
			for(j = 0; j < active + 1; j++)
			{
				if(y[i] == y[j])
				{
					xRelative[j] = x[j];
					inRow++;
				}
			}
			
			// Arrange xRelative
			for(j = 0; j < COUNT + 1; j++)
			{
				min = j;
				
				// Find smallest xRelative and write its index to min
				for(k = j + 1; k < COUNT + 1; k++)
				{				
					if(xRelative[k] < xRelative[min])
					{
						min = k;
					}
				}
				
				if(min != j)
				{
					temp = xRelative[j];
					xRelative[j] = xRelative[min];
					xRelative[min] = temp;
				}
			}
			
			// Get to yRelative row
			repeat('\n', yRelative - (overflow == CONSOLEWIDTH && i != 0 ? 1 : 0));
			
			// Print body
			overflow = 0;
			
			for(j = 0; j < inRow; j++)
			{
				repeat(' ', (j == 0 ? xRelative[j] : (xRelative[j] - xRelative[j - 1] - 1)));
				printf("O");
				
				overflow += (j == 0 ? xRelative[j] : (xRelative[j] - xRelative[j - 1] - 1)) + 1;
			}
		}
		
		Sleep(WAIT);
		system("cls");
		
		// Arrange by order
		for(i = 0; i < COUNT + 1; i++)
		{
			min = i;
			
			// Find smallest order and write its index to min
			for(j = i + 1; j < COUNT + 1; j++)
			{
				if(order[j] < order[min])
				{
					min = j;
				}
			}
			
			if(min != i)
			{
				temp = y[i];
				y[i] = y[min];
				y[min] = temp;
				
				temp = x[i];
				x[i] = x[min];
				x[min] = temp;
				
				temp = course[i];
				course[i] = course[min];
				course[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Copy course to histCourse before new assign of course[leader]
		for(i = 0; i < active; i++)
		{
			histCourse[i] = course[i];
		}
		
		// Get new course for head
		if(kbhit() == true)
		{
			temp = getch();
			
			if(temp >= 97 && temp <= 122)
			{
				temp -= 32;
			}
			
			if((temp == 'W' || temp == 'A' || temp == 'S' || temp == 'D') && temp != (course[0] == 'W' ? 'S' : (course[0] == 'S' ? 'W' : (course[0] == 'A' ? 'D' : 'A'))))
			{
				course[0] = temp;
			}
			else if(temp == 27)
			{
				pausemenu(false);
			}
		}
		
		// Asign courses
		x[0] += (course[0] == 'A' ? -1 : (course[0] == 'D' ? 1 : 0));
		y[0] += (course[0] == 'W' ? -1 : (course[0] == 'S' ? 1 : 0));
		
		for(i = 1; i < active; i++)
		{
			course[i] = histCourse[i - 1];
			
			x[i] += (course[i] == 'A' ? -1 : (course[i] == 'D' ? 1 : 0));
			y[i] += (course[i] == 'W' ? -1 : (course[i] == 'S' ? 1 : 0));
		}
		
		// Eating berry
		if(x[0] == x[COUNT] && y[0] == y[COUNT])
		{
			// Create new body
			x[active] = x[active - 1] + (course[active - 1] == 'A' ? 1 : (course[active - 1] == 'D' ? -1 : 0));
			y[active] = y[active - 1] + (course[active - 1] == 'W' ? 1 : (course[active - 1] == 'S' ? -1 : 0));
			
			// Course does't have to be assigned here. It will be assigned from histCourse in next cycle
			
			active++;
			setNewBerry = true;
		}
		
		// Collision between head and bodies
		for(i = 1; i < active; i++)
		{
			if(x[0] == x[i] && y[0] == y[i])
			{
				collision = true;
				break;
			}
		}
		
		// Collision between head and edge and game end
		// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
		if(x[0] < 0 || x[0] > CONSOLEWIDTH - 1 || y[0] < 0 || y[0] > CONSOLEHEIGHT - 1 || collision == true || active == COUNT)
		{
			repeat('\n', verticalcenter(10));
			
			if(active == COUNT)
			{
				center(0, " //    //  ///////  //   //     //    //  ///////  //    //  //\n");
				center(0, " //  //   //   //  //   //     // // //  //   //  ///   //  // \n");
				center(0, "  //     //   //  //   //     // // //  //   //  // // //  //  \n");
				center(0, " //     //   //  //   //     // // //  //   //  //   ///       \n");
				center(0, "//     ///////  ///////      //  //   ///////  //    //  //    \n");
			}
			else
			{
				center(0, " //    //  ///////  //   //     /////    //  ///////  /////    //\n");
				center(0, " //  //   //   //  //   //     //   //  //  //       //   //  // \n");
				center(0, "  //     //   //  //   //     //   //  //  /////    //   //  //  \n");
				center(0, " //     //   //  //   //     //   //  //  //       //   //       \n");
				center(0, "//     ///////  ///////     /////    //  ///////  /////    //    \n");
			}
			
			printf("\n\n\n");
			center(16, active < 10 ? "Your score:    " : "Your score:   ");
			printf("%d\n\n", active);
			
			center(0, "> Back  ");
		
			while("snake")
			{	
				temp = getch();
				
				// 13 - carriage return (ENTER) 27 - ESC
				if(temp == 13 || temp == 27)
				{
					main();
				}
			}
		}
	}
}

void hotseat(const int WAIT)
{
	bool setNewBerry[2], collision[2], gotNewCourse[2];
	int yRelative, overflow, inRow, actualBerry;
	int x[COUNT + 2], y[COUNT + 2], xRelative[COUNT + 2], order[COUNT + 2], active[2], score[2];
	char course[COUNT], histCourse[COUNT];	
	
	// First-run reset
	system("cls");
	
	setNewBerry[0] = setNewBerry[1] = true;
	collision[0] = collision[1] = false;
	active[0] = active[1] = 3;
	score[0] = score[1] = 0;
	
	for(i = 0; i < COUNT + 2; i++)
	{
		x[i] = y[i] = CONSOLEWIDTH + 1;
		order[i] = i;
		
		if(i < COUNT)
		{
			course[i] = 'X';
			histCourse[i] = 'X';
		}
	}
	
	for(i = 0; i < active[0]; i++)
	{
		x[i] = CONSOLEWIDTH / 4;
		y[i] = i + ((CONSOLEHEIGHT - active[0]) / 2);
		course[i] = 'W';
	}
	
	for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
	{
		x[i] = ((CONSOLEWIDTH / 4) * 3) - 1;
		y[i] = i + ((CONSOLEHEIGHT - active[1]) / 2) - (COUNT / 2);
		course[i] = '8';
	}
	
	while("snake")
	{
		// Generate new x and y for berry
		for(actualBerry = 0; actualBerry <= 1; actualBerry++)
		{
			if(setNewBerry[actualBerry] == true)
			{
				do
				{
					x[COUNT + actualBerry] = rand() % CONSOLEWIDTH;
					
					// Determine if there is collision with some body
					for(i = 0; i < (COUNT / 2) + active[1]; i++)
					{
						if(x[COUNT + actualBerry] == x[i])
						{
							break;
						}
						
						// Skip some cells to get to second snake
						if(i == active[0] - 1)
						{
							// Must be (COUNT / 2) - 1 instead of (COUNT / 2) because i++ at the end of this cycle
							i = (COUNT / 2) - 1;
						}
					}
				// Generate new X for berry if there is collision with some body or another berry
				} while(i != (COUNT / 2) + active[1] || x[COUNT + actualBerry] == x[COUNT + (actualBerry == 0 ? 1 : 0)]);
				
				do
				{
					y[COUNT + actualBerry] = rand() % CONSOLEHEIGHT;
					
					// Determine if there is collision with some body
					for(i = 0; i < (COUNT / 2) + active[1]; i++)
					{
						if(y[COUNT + actualBerry] == y[i])
						{
							break;
						}
						
						// Skip some cells to get to second snake
						if(i == active[0] - 1)
						{
							// Must be (COUNT / 2) - 1 instead of (COUNT / 2) because i++ at the end of this cycle
							i = (COUNT / 2) - 1;
						}
					}
				// Generate new Y for berry if there is collision with some body or another berry or when berry is in bottom right corner
				// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
				} while(i != (COUNT / 2) + active[1] || (x[COUNT + actualBerry] == CONSOLEWIDTH - 1 && y[COUNT + actualBerry] == CONSOLEHEIGHT - 1) || y[COUNT + actualBerry] == y[COUNT + (actualBerry == 0 ? 1 : 0)]);
				
				setNewBerry[actualBerry] = false;
			}
		}
		
		// Arrange by Y
		for(i = 0; i < COUNT + 2; i++)
		{
			min = i;
			
			// Find smallest Y and write its index to min
			for(j = i + 1; j < COUNT + 2; j++)
			{
				if(y[j] < y[min])
				{
					min = j;
				}
			}
			
			if(min != i)
			{
				temp = y[i];
				y[i] = y[min];
				y[min] = temp;
				
				temp = x[i];
				x[i] = x[min];
				x[min] = temp;
				
				temp = course[i];
				course[i] = course[min];
				course[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Print snake
		for(i = 0; i < active[0] + active[1] + 2; i++)
		{
			// Continue if there were more bodies in previous row
			if((y[i] == y[i - 1]) && !(y[0] == 0 && i == 0))
			{
				continue;
			}
			
			// Reset values
			inRow = 0;
			
			for(j = 0; j < COUNT + 2; j++)
			{
				xRelative[j] = CONSOLEWIDTH + 1;
			}
			
			// Assign relative positions
			yRelative = (i == 0 ? y[i] : (y[i] - y[i - 1]));
			
			for(j = 0; j < active[0] + active[1] + 2; j++)
			{
				if(y[i] == y[j])
				{
					xRelative[j] = x[j];
					inRow++;
				}
			}
			
			// Arrange xRelative
			for(j = 0; j < COUNT + 2; j++)
			{
				min = j;
				
				// Find smallest xRelative and write its index to min
				for(k = j + 1; k < COUNT + 2; k++)
				{				
					if(xRelative[k] < xRelative[min])
					{
						min = k;
					}
				}
				
				if(min != j)
				{
					temp = xRelative[j];
					xRelative[j] = xRelative[min];
					xRelative[min] = temp;
				}
			}
			
			// Get to yRelative row
			repeat('\n', yRelative - (overflow == CONSOLEWIDTH && i != 0 ? 1 : 0));
			
			// Print body
			overflow = 0;
			
			for(j = 0; j < inRow; j++)
			{
				repeat(' ', (j == 0 ? xRelative[j] : (xRelative[j] - xRelative[j - 1] - 1)));
				printf("O");
				
				overflow += (j == 0 ? xRelative[j] : (xRelative[j] - xRelative[j - 1] - 1)) + 1;
			}
		}
		
		Sleep(WAIT);
		system("cls");
		
		// Arrange by order
		for(i = 0; i < COUNT + 2; i++)
		{
			min = i;
			
			// Find smallest order and write its index to min
			for(j = i + 1; j < COUNT + 2; j++)
			{
				if(order[j] < order[min])
				{
					min = j;
				}
			}
			
			if(min != i)
			{
				temp = y[i];
				y[i] = y[min];
				y[min] = temp;
				
				temp = x[i];
				x[i] = x[min];
				x[min] = temp;
				
				temp = course[i];
				course[i] = course[min];
				course[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Copy course to histCourse before new assign of course[head]
		if(collision[0] == false)
		{
			for(i = 0; i < active[0]; i++)
			{
				histCourse[i] = course[i];
			}
		}
		
		if(collision[1] == false)
		{
			for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
			{
				histCourse[i] = course[i];
			}
		}
		
		// Get new course for heads
		gotNewCourse[0] = gotNewCourse[1] = false;
		
		if(kbhit() == true)
		{
			temp = getch();
			
			if(temp >= 97 && temp <= 122)
			{
				temp -= 32;
			}
			
			if(collision[0] == false && ((temp == 'W' || temp == 'A' || temp == 'S' || temp == 'D')
				&& temp != (course[0] == 'W' ? 'S' : (course[0] == 'S' ? 'W' : (course[0] == 'A' ? 'D' : 'A')))
				))
			{
				course[0] = temp;
				gotNewCourse[0] = true;
			}
			else if(collision[1] == false && ((temp == '8' || temp == '4' || temp == '5' || temp == '6')
				&& temp != (course[COUNT / 2] == '8' ? '5' : (course[COUNT / 2] == '5' ? '8' : (course[COUNT / 2] == '4' ? '6' : '4')))
				))
			{
				course[COUNT / 2] = temp;
				gotNewCourse[1] = true;
			}
			else if(temp == 27)
			{
				pausemenu(true);
			}
		}
		
		if(collision[0] == false && collision[1] == false && kbhit() == true)
		{
			temp = getch();
			
			if(temp >= 97 && temp <= 122)
			{
				temp -= 32;
			}
			
			if(gotNewCourse[0] == false && collision[0] == false && ((temp == 'W' || temp == 'A' || temp == 'S' || temp == 'D')
				&& temp != (course[0] == 'W' ? 'S' : (course[0] == 'S' ? 'W' : (course[0] == 'A' ? 'D' : 'A')))
				))
			{
				course[0] = temp;
				gotNewCourse[0] = true;
			}
			else if(gotNewCourse[1] == false && collision[1] == false && ((temp == '8' || temp == '4' || temp == '5' || temp == '6')
				&& temp != (course[COUNT / 2] == '8' ? '5' : (course[COUNT / 2] == '5' ? '8' : (course[COUNT / 2] == '4' ? '6' : '4')))
				))
			{
				course[COUNT / 2] = temp;
				gotNewCourse[1] = true;
			}
			else if(temp == 27)
			{
				pausemenu(true);
			}
		}
		
		// Asign courses
		if(collision[0] == false)
		{
			x[0] += (course[0] == 'A' ? -1 : (course[0] == 'D' ? 1 : 0));
			y[0] += (course[0] == 'W' ? -1 : (course[0] == 'S' ? 1 : 0));
			
			for(i = 1; i < active[0]; i++)
			{
				course[i] = histCourse[i - 1];
				
				x[i] += (course[i] == 'A' ? -1 : (course[i] == 'D' ? 1 : 0));
				y[i] += (course[i] == 'W' ? -1 : (course[i] == 'S' ? 1 : 0));
			}
		}
		
		if(collision[1] == false)
		{
			x[COUNT / 2] += (course[COUNT / 2] == '4' ? -1 : (course[COUNT / 2] == '6' ? 1 : 0));
			y[COUNT / 2] += (course[COUNT / 2] == '8' ? -1 : (course[COUNT / 2] == '5' ? 1 : 0));
			
			for(i = (COUNT / 2) + 1; i < (COUNT / 2) + active[1]; i++)
			{
				course[i] = histCourse[i - 1];
				
				x[i] += (course[i] == '4' ? -1 : (course[i] == '6' ? 1 : 0));
				y[i] += (course[i] == '8' ? -1 : (course[i] == '5' ? 1 : 0));
			}
		}
		
		// Eating berry
		if(collision[0] == false)
		{
			for(actualBerry = 0; actualBerry <= 1; actualBerry++)
			{
				if(x[0] == x[COUNT + actualBerry] && y[0] == y[COUNT + actualBerry])
				{
					// Create new body
					x[active[0]] = x[active[0] - 1] + (course[active[0] - 1] == 'A' ? 1 : (course[active[0] - 1] == 'D' ? -1 : 0));
					y[active[0]] = y[active[0] - 1] + (course[active[0] - 1] == 'W' ? 1 : (course[active[0] - 1] == 'S' ? -1 : 0));
					
					// Course does't have to be assigned here. It will be assigned from histCourse in next cycle
					
					active[0]++;
					setNewBerry[actualBerry] = true;
				}
			}
		}
		
		if(collision[1] == false)
		{
			for(actualBerry = 0; actualBerry <= 1; actualBerry++)
			{
				if(x[COUNT / 2] == x[COUNT + actualBerry] && y[COUNT / 2] == y[COUNT + actualBerry])
				{
					// Create new body
					x[(COUNT / 2) + active[1]] = x[(COUNT / 2) + active[1] - 1] + (course[(COUNT / 2) + active[1] - 1] == '4' ? 1 : (course[(COUNT / 2) + active[1] - 1] == '6' ? -1 : 0));
					y[(COUNT / 2) + active[1]] = y[(COUNT / 2) + active[1] - 1] + (course[(COUNT / 2) + active[1] - 1] == '8' ? 1 : (course[(COUNT / 2) + active[1] - 1] == '5' ? -1 : 0));
					
					// Course does't have to be assigned here. It will be assigned from histCourse in next cycle
					
					active[1]++;
					setNewBerry[actualBerry] = true;
				}
			}
		}
		
		// Collision between first snake head and all bodies
		if(collision[0] == false)
		{
			// Collision with first snake bodies
			for(i = 1; i < active[0]; i++)
			{
				if(x[0] == x[i] && y[0] == y[i])
				{
					collision[0] = true;
					break;
				}
			}
			
			// Collision with second snake
			if(collision[1] == false)
			{
				for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
				{
					if(x[0] == x[i] && y[0] == y[i])
					{
						collision[0] = collision[1] = true;
						break;
					}
				}
			}
		}
		
		// Collision between second snake head and all bodies
		if(collision[1] == false)
		{
			// Collision with second snake bodies
			for(i = (COUNT / 2) + 1; i < (COUNT / 2) + active[1]; i++)
			{
				if(x[COUNT / 2] == x[i] && y[COUNT / 2] == y[i])
				{
					collision[1] = true;
					break;
				}
			}
			
			// Collision with first snake bodies
			if(collision[0] == false)
			{
				for(i = 0; i < active[0]; i++)
				{
					if(x[COUNT / 2] == x[i] && y[COUNT / 2] == y[i])
					{
						collision[0] = collision[1] = true;
						break;
					}
				}
			}
		}
		
		// Collision with edges
		// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
		if(collision[0] == false && (x[0] < 0 || x[0] > CONSOLEWIDTH - 1 || y[0] < 0 || y[0] > CONSOLEHEIGHT - 1))
		{
			collision[0] = true;
		}
		
		// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
		if(collision[1] == false && (x[COUNT / 2] < 0 || x[COUNT / 2] > CONSOLEWIDTH - 1 || y[COUNT / 2] < 0 || y[COUNT / 2] > CONSOLEHEIGHT - 1))
		{
			collision[1] = true;
		}
		
		// Reset dead snakes
		// When only one snake is dead to save some time and not reset both snakes when both are dead
		if(collision[0] == true && collision[1] == false && active[0] != 0)
		{
			for(i = 0; i < active[0]; i++)
			{
				x[i] = y[i] = 100;
				course[i] = 'X';
			}
			
			score[0] = active[0];
			active[0] = 0;
		}
		
		if(collision[1] == true && collision[0] == false && active[1] != 0)
		{
			for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
			{
				x[i] = y[i] = 100;
				course[i] = 'X';
			}
			
			score[1] = active[1];
			active[1] = 0;
		}
		
		// Game end
		if((collision[0] == true && collision[1] == true) || active[0] == COUNT / 2 || active[1] == COUNT / 2)
		{
			if(score[0] == 0)
			{
				score[0] = active[0];
			}
			
			if(score[1] == 0)
			{
				score[1] = active[1];
			}
			
			
			repeat('\n', verticalcenter(11));
			center(0, " ////////  //    //  ///////     ///////  //    //  //////    //\n");
			center(0, "   //     //    //  //          //       ///   //  //    //  // \n");
			center(0, "  //     ////////  /////       /////    // // //  //    //  //  \n");
			center(0, " //     //    //  //          //       //   ///  //    //       \n");
			center(0, "//     //    //  ///////     ///////  //    //  //////    //    \n");
			printf("\n\n\n");
			
			center(collision[0] == false ? 33 : 29, collision[0] == false ? "Player 1 survived" : "Player 1 died");
			printf(score[0] < 10 ? " with  %d points!\n" : " with %d points!\n", score[0]);
			
			center(collision[0] == false ? 33 : 29,collision[1] == false ? "Player 2 survived" : "Player 2 died");
			printf(score[1] < 10 ? " with  %d points!" : " with %d points!", score[1]);
			
			printf("\n\n");
			center(0, "> Back  ");
		
			while("snake")
			{	
				temp = getch();
				
				// 13 - carriage return (ENTER) 27 - ESC
				if(temp == 13 || temp == 27)
				{
					main();
				}
			}
		}
	}
}

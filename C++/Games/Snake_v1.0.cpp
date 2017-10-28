//
//
//	(c) Marian Dolinský 2015
//
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void center(const char strg[]);

int main()
{
	const int COUNT = 50;
	
	bool setNewBerry, collision, firstRun;
	int i, j, k, temp, yTemp, overflow, inRow, active, leader;
	int x[COUNT + 1], y[COUNT + 1], xTemp[COUNT + 1], order[COUNT];
	char course[COUNT], histCourse[COUNT], repeat[1] = {0};
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
	
	srand(time(0));
	system("color 0F");
	
	for(i = 0; i < 7; i++)
	{
		printf("\n");
	}
	
	center("    ///////  //    //  ////////  //   //  ///////\n");
	center("   //       ///   //  //    //  // //    //      \n");
	center("  ///////  // // //  ////////  ///      /////    \n");
	center("      //  //  ////  //    //  // //    //        \n");
	center("///////  //    //  //    //  //   //  ///////    \n");
	
	Sleep(500);
	
	do
	{
		
		if(repeat[0] != 0)
		{
			for(i = 0; i < 9; i++) printf("\n");
		}
		printf("\n\n\n");
		
		center("Press any key to start the game . . .");
		
		if(repeat[0] == 0)
		{
			for(i = 0; i < 9; i++) printf("\n");
			printf("Snake 1.0 (c) Marian Dolinsk\xEC 2015");
		}
		
		getch();
		system("cls");
		
		// First run reset
		setNewBerry = true;
		collision = false;
		active = 3;
		leader = 0;
		repeat[0] = 0;
		
		x[0] = 39;
		x[1] = 39;
		x[2] = 39;
		
		y[0] = 11;
		y[1] = 12;
		y[2] = 13;
		
		for(i = 0; i < COUNT; i++)
		{
			order[i] = i;
			histCourse[i] = 'X';
		}
		
		for(i = 0; i < active; i++)
		{
			course[i] = 'W';
		}
		
		for(i = active; i < COUNT; i++)
		{
			x[i] = y[i] = 100;
			course[i] = 'X';
		}
		
		while("for")
		{
			// Generate new x and y for berry
			if(setNewBerry == true)
			{
				do
				{
					x[COUNT] = rand() % 80;
					
					for(i = 0; i < active; i++)
					{
						if(x[COUNT] == x[i])
						{
							break;
						}
					}
				} while(i != active);
				
				do
				{
					y[COUNT] = rand() % 25;
					
					for(i = 0; i < active; i++)
					{
						if(y[COUNT] == y[i])
						{
							break;
						}
					}
				} while(i != active);
				
				setNewBerry = false;
			}
			
			// Arrange by Y
			for(i = 0; i < COUNT + 1; i++)
			{
				for(j = i + 1; j < COUNT + 1; j++)
				{
					if(y[i] > y[j])
					{
						if(i == leader)
						{
							leader = j;
						}
						else if(j == leader)
						{
							leader = i;
						}
						
						temp = y[i];
						y[i] = y[j];
						y[j] = temp;
						
						temp = x[i];
						x[i] = x[j];
						x[j] = temp;
						
						temp = course[i];
						course[i] = course[j];
						course[j] = temp;
						
						temp = order[i];
						order[i] = order[j];
						order[j] = temp;
					}
				}
			}
			
			// Print body
			for(i = 0; i < active + 1; i++)
			{
				if((y[i] == y[i - 1]) && !(y[0] == 0 && i == 0))
				{
					continue;
				}
				
				// Reset values
				inRow = 0;
				yTemp = (i == 0 ? y[i] : (y[i] - y[i - 1]));
				
				for(j = 0; j < COUNT; j++)
				{
					xTemp[j] = 100;
				}
				
				
				// Get to Y row
				for(j = (overflow == 80 && i != 0 ? 1 : 0); j < yTemp; j++)
				{
					printf("\n");
				}
				
				
				// Assign xTemp
				for(j = 0; j < active + 1; j++)
				{
					if(y[i] == y[j])
					{
						xTemp[j] = x[j];
						inRow++;
					}
				}
				
				// Arrange xTemp
				for(j = 0; j < COUNT; j++)
				{
					for(k = j + 1; k < COUNT; k++)
					{				
						if(xTemp[j] > xTemp[k])
						{
							temp = xTemp[j];
							xTemp[j] = xTemp[k];
							xTemp[k] = temp;
						}
					}
				}
				
				// Print body
				overflow = 0;
				
				for(j = 0; j < inRow; j++)
				{
					for(k = 0; k < (j == 0 ? xTemp[j] : (xTemp[j] - xTemp[j - 1] - 1)); k++)
					{
						printf(" ");
					}
					
					printf("O");
					overflow += k + 1;
				}
			}
			
			Sleep(100 - (20 * (active / 10)));
			system("cls");
			
			// Arrange by order
			for(i = 0; i < COUNT + 1; i++)
			{
				for(j = i + 1; j < COUNT + 1; j++)
				{
					if(order[i] > order[j])
					{
						if(i == leader)
						{
							leader = j;
						}
						else if(j == leader)
						{
							leader = i;
						}
						
						temp = y[i];
						y[i] = y[j];
						y[j] = temp;
						
						temp = x[i];
						x[i] = x[j];
						x[j] = temp;
						
						temp = course[i];
						course[i] = course[j];
						course[j] = temp;
						
						temp = order[i];
						order[i] = order[j];
						order[j] = temp;
					}
				}
			}
			
			// Copy course to histCourse before new assign to course[leader]
			for(i = 0; i < active; i++)
			{
				histCourse[i] = course[i];
			}
			
			// Get new course for leader
			if(kbhit() == true)
			{
				temp = getch();
				
				if(temp > 90)
				{
					temp -= 32;
				}
				
				if((temp == 'W' || temp == 'A' || temp == 'S' || temp == 'D') && temp != (course[leader] == 'W' ? 'S' : (course[leader] == 'S' ? 'W' : (course[leader] == 'A' ? 'D' : 'A'))))
				{
					course[leader] = temp;
				}
			}
			
			// Asign courses
			for(i = 0; i < active; i++)
			{
				if(i != leader)
				{
					course[i] = histCourse[i - 1];
				}
				
				x[i] += (course[i] == 'A' ? -1 : (course[i] == 'D' ? 1 : 0));
				y[i] += (course[i] == 'W' ? -1 : (course[i] == 'S' ? 1 : 0));
			}
			
			// Collision
			for(i = 0; i < active; i++)
			{
				for(j = i + 1; j < active; j++)
				{
					if(x[i] == x[j] && y[i] == y[j])
					{
						collision = true;
						break;
					}
				}
				
				if(collision == true)
				{
					break;
				}
			}
			
			// Collision - leader with berry
			if(x[leader] == x[COUNT] && y[leader] == y[COUNT])
			{
				x[active] = x[active - 1] + (course[active - 1] == 'A' ? 1 : (course[active - 1] == 'D' ? -1 : 0));
				y[active] = y[active - 1] + (course[active - 1] == 'W' ? 1 : (course[active - 1] == 'S' ? -1 : 0));
				course[active] = histCourse[active - 1];
				
				active++;
				setNewBerry = true;
			}
			
			//							80-1 (body)							25-1 (first line)
			//								\/									\/
			if(x[leader] < 0 || x[leader] > 79 || y[leader] < 0 || y[leader] > 24 || collision == true || active == COUNT)
			{
				break;
			}
		}
		
		// Show score
		if(x[leader] < 0 || x[leader] > 79 || y[leader] < 0 || y[leader] > 24 || collision == true)
		{
			for(i = 0; i < 7; i++) printf("\n");
			
			center(" //    // ///////  //    //     /////    //  ///////  /////    //\n");
			center(" //  //  //   //  //    //     //   //  //  //       //   //  // \n");
			center("  //    //   //  //    //     //   //  //  /////    //   //  //  \n");
			center(" //    //   //  //    //     //   //  //  //       //   //       \n");
			center("//    ///////  ////////     /////    //  ///////  /////    //    \n");
		}
		else if(active == COUNT)
		{
			for(i = 0; i < 7; i++) printf("\n");
			
			center(" //    // ///////  //    //     //    //   ///////  //    //  //\n");
			center(" //  //  //   //  //    //     // // //   //   //  ///   //  // \n");
			center("  //    //   //  //    //     // // //   //   //  // // //  //  \n");
			center(" //    //   //  //    //     // // //   //   //  //   ///       \n");
			center("//    ///////  ////////      //  //    ///////  //    //  //    \n");
		}
		
		do
		{
			printf("\n\n\n");
			
			center("Do you want to play again? (Y/n): ");
			gets(repeat);
			
			if(repeat[0] > 90)
			{
				repeat[0] -= 32;
			}
		} while((repeat[0] != 'Y' && repeat[0] != 'N') || strlen(repeat) != 1);
		
		system("cls");
	} while(repeat[0] == 'Y');
	
	for(i = 0; i < 12; i++) printf("\n");
	center("Thanks for playing :)");
	
	Sleep(5000);
	
	return 0;
}

void center(const char strg[])
{
	for(int i = 0; i < (80 - strlen(strg)) / 2; i++)
	{
		printf(" ");
	}
	
	printf("%s", strg);
}

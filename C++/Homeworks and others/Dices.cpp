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

void center(int space, const char text[]);
void repeat(int count, const char strg[]);

int main()
{
	srand(time(0));
	system("color 0F");
	
	bool rolling = true, end = false;
	int n[3] = {0}, p[2] = {0}, i, f, cl, playing = 0, notplaying = 1, laps = 1, moves = 1;
	char again;
	
	repeat(11, "\n");
	center(0, "Lap: 1\n");
	center(0, "Player 1 is now playing.\n");
	center(0, "Press any key to start the game . . .");
	getch();
	system("cls");
	
	while("fiša")
	{
		//printf("rolling %d\nend %d\nn %d %d %d\np %d %d\ncl %d\nplaying %d %d\nlaps %d\nmoves %d\nagain %c", rolling, end, n[0], n[1], n[2], p[0], p[1], cl, playing, notplaying, laps, moves, again);
		
		notplaying = (playing == 0 ? 1 : 0);
		if(rolling == true)
		{
			n[0] = rand()%6 + 1;
			n[1] = rand()%6 + 1;
			n[2] = rand()%6 + 1;
			
			cl = p[notplaying] - p[playing] + 1;
		}
		else cl = (n[0] == 1 ? 100 : (n[0] == 6 ? 60 : n[0])) + (n[1] == 1 ? 100 : (n[1] == 6 ? 60 : n[1])) + (n[2] == 1 ? 100 : (n[2] == 6 ? 60 : n[2]));
		
		// Score 1. row
		center(51, "");
		printf(end == false ? "\xBA       You: " : "\xBA    Player 1: ");
		
		if(p[playing] < 1000) printf(" ");
		if(p[playing] < 100) printf(" ");
		if(p[playing] < 10) printf(" ");
		
		printf((end == false ? "%dp       \xBA     Player %d: " : "%dp     \xBA     Player %d: "), p[playing], notplaying + 1);
		
		if(p[notplaying] < 1000) printf(" ");
		if(p[notplaying] < 100) printf(" ");
		if(p[notplaying] < 10) printf(" ");
		
		printf("%dp    \xBA\n", p[notplaying]);
		
		if(end == false)
		{
			// Score 2. row
			center(51, "");
			printf("\xCC");
			repeat(24, "\xCD");
			printf("\xCA");
			repeat(24, "\xCD");
			printf("\xB9\n");
			
			// Score 3. row
			center(51, "");
			printf("\xBA ");
			repeat((rolling == true ? (cl > 1 ? 3 : 0) : 9), " ");
			printf((rolling == true ? (cl > 1 ? "To be better you must score at least: " : "You'll be better than Player %d after your turn.") : "In this turn you scored: "), (playing == 0 ? 1 : 0) + 1);
			
			if(cl > 1 || rolling == false)
			{
				if(cl < 100) printf(" ");
				if(cl < 10) printf(" ");
				printf("%dp", cl);
				
				repeat((rolling == true ? 2 : 9), " ");
			}
			printf(" \xBA\n");
		}
		
		// Score 4. row
		center(51, "");
		printf("\xC8");
		
		if(end == false) repeat(49, "\xCD");
		else
		{
			repeat(24, "\xCD");
			printf("\xCA");
			repeat(24, "\xCD");
		}
		printf("\xBC\n");
		
		
		
		// Dices
		if(end == false)
		{
			repeat(4, "\n");
			for(f = 0; f < 5; f++)
			{
				printf("\n");
				center(27, "");
				
				if(f == 0) repeat(3, "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
				else if(f == 4) repeat(3, "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
				else
				{
					for(i = 0; i <= 2; i++)
					{
						printf("\xBA ");
						printf(f == 2 ? (n[i] == 6 ? "o " : "  ") : (n[i] > ((f == 1 ? 3 : 1)) ? "o" : " "));
						printf(f == 2 ? (n[i]%2 == 1 ? "o " : "  ") : "   ");
						printf(f == 2 ? (n[i] == 6 ? "o" : " ") : (n[i] > ((f == 1 ? 1 : 3)) ? "o" : " "));
						printf(" \xBA");
					}
				}
			}
		}
		printf("\n");
		
		if(rolling == true)
		{
			printf("\n");
			center(0, "Press any key to stop rolling . . .");
			Sleep(20);
		}
		else if(rolling == false)
		{
			if(end == true) break;
			
			printf("\n");
			
			if(moves == 3)
			{
				center(0, "You can't play again, current points will be added to your score.\n");
				center(0, "Press any key to continue . . .");
				getch();
			}
			else
			{
				do
				{
					center(0, "Do you want to play again? (Y/n): ");
					scanf("%c", &again);
					getchar();
				} while(again != 'y' && again != 'Y' && again != 'n' && again != 'N');
			}
			
			if(laps == 3 && playing == 1 && (moves == 3 || again == 'n' || again == 'N'))
			{
				p[playing] += cl;
				playing = notplaying;
				
				rolling = false;
				end = true;
			}
			else if((again == 'y' || again == 'Y') && moves != 3)
			{
				moves++;
			}
			else
			{
				moves = 1;
				
				if(playing == 1) laps++;
				
				p[playing] += cl;
				playing = notplaying;
				
				system("cls");
				
				repeat(11, "\n");
				repeat(37, " ");
				printf("Lap: %d\n", laps);
				repeat(28, " ");
				printf("Player %d is now playing.\n", playing + 1);
				center(0, "Press any key to continue . . .");
				getch();
			}
			if(end == false) rolling = true;
		}
		system("cls");
		
		if(kbhit() == true)
		{
			getch();
			rolling = false;
		}
	}
	
	repeat(8, "\n");
	center(0, (p[0] == p[1] ? "It's unbelievable, but it's a draw!!!\n" : (p[0] > p[1] ? "Player 1 wins!!!\n" : "Player 2 wins!!!\n")));
	center(0, "Press any key to exit . . .");
	getch();
}

void center(int space, const char text[])
{
	for(int i = 0; i < (80-(space == 0 ? strlen(text) : space)) / 2; i++) printf(" ");
	if(text != "") printf("%s", text);
}

void repeat(int count, const char strg[])
{
	for(int i = 0; i < count; i++) printf("%s", strg);
}

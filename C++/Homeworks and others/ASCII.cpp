/*
	Name: ASCII chart v1.3
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 06/05/16 22:36
	Description: Shows full ASCII chart in console.
*/

#include <stdio.h>
#include <windows.h>

int main()
{
	int codePageCode;
	
	system("color 0F");
	
	fputs("Enter custom Code Page (0 = default): ", stdout);
	scanf("%d", &codePageCode);
	
	if(codePageCode != 0)
	{
		char codePage[10];
		
		sprintf(codePage, "chcp %d", codePageCode);
		system(codePage);
	}
	
	putchar('\n');
	
    for(int i = 0; i < 256; i++)
	{
        printf("%3d: %c ", i, i); 
		
        if(i % 10 == 9)
		{
			putchar('\n');
		}
    }
    
    getchar();
	getchar();
}

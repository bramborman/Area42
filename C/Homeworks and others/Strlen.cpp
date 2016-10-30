/*
	Name: Strlen v1.1
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 27/05/16 22:06
	Description: Shows lenght of entered string.
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>

int main()
{
	char str[100] = {0};
	
	system("color 0F");
	
	while (true)
	{
		printf("Enter any text: ");
		gets(str);
		
		printf("Text is %d %s long.\n\n", strlen(str), (strlen(str) == 1 ? "char" : "chars"));
	}
}

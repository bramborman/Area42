#include <stdio.h>
#include <windows.h>

int main()
{
	char source[] = "ahoj";
	char dest[strlen(source) + 1];
	
	printf("%s", strcpy(dest, source));
}

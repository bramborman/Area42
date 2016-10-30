#include <stdio.h>
#include <windows.h>

void dectohex(int dec)
{
	char hex[3];
	hex[2] = '\0';
	
	hex[1] = dec % 16;
	hex[0] = dec / 16 % 16;
	
	hex[0] = hex[0] + (hex[0] >= 10 ? 'a' - 10 : '0');
	hex[1] = hex[1] + (hex[1] >= 10 ? 'a' - 10 : '0');
	
	printf(hex);
}

int main()
{
	int dec = 256;
	
	while (dec < 0 || dec > 255)
	{
		printf("Zadej cislo 0-255: ");
		scanf("%d", &dec);
	}
	
	printf("%d = ", dec);
	dectohex(dec);
	
	printf("\n");
	system("pause");
}

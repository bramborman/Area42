#include <stdio.h>
#include <windows.h>

#define COUNT 3

bool viceciferne(const int X)
{
	return X <= -10 || X >= 10;
}

int main()
{
	int numbers[COUNT];
	float prumer = 0;
	
	for(int i = 0; i < COUNT; i++)
	{
		printf("Zadej %d. cislo: ", i + 1);
		scanf("%d", &numbers[i]);
		
		prumer += (float)numbers[i];
	}
	
	prumer /= (float)COUNT;
	printf("Prumer %.2f je %s\n\n", prumer, viceciferne(prumer) ? "viceciferny" : "jednociferny");
	
	system("pause");
}

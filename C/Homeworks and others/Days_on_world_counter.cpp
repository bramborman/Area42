//
//
//	(c) Marian Dolinský 2015
//
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main()
{
	const int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, tday = 26, tmonth = 10, tyear = 2015;
	int day, month, year, count = 0;
	
	do
	{
		system("cls");
		
		printf("Enter your birth date (day): ");
		scanf("%d", &day);
		
		printf("Enter your birth date (month): ");
		scanf("%d", &month);
	
		printf("Enter your birth date (year): ");
		scanf("%d", &year);
		printf("\n");
	} while
	  (
	  		year > tyear ||
			(year == tyear && month > tmonth) ||
			(year == tyear && month == tmonth && day > tday) ||
			
			year < 1900 ||
			month < 1 || month > 12 ||
			day < 1 ||
			(year % 4 == 0 && ((month == 2 && day > 29) || (month != 2 && day > monthdays[month - 1]))) ||
			(year % 4 != 0 && day > monthdays[month - 1])
	  );
	
	for(; year < tyear; year++)
	{
		count += 365;
		
		if(year % 4 == 0 && year != 1900)
		{
			count++;
		}
	}
	
	if(month < tmonth)
	{
		for(; month < tmonth; month++)
		{
			count += monthdays[month - 1];
			
			if(tyear % 4 == 0 && month - 1 == 2)
			{
				count++;
			}
		}
	}
	else if(month > tmonth)
	{
		for(; month > tmonth; month--)
		{
			count -= monthdays[month - 1];
			
			if(tyear % 4 == 0 && month - 1 == 2)
			{
				count--;
			}
		}
	}
	
	if(day < tday)
	{
		for(; day < tday; day++)
		{
			count++;
		}
	}
	else if(day > tday)
	{
		for(; day > tday; day--)
		{
			count--;
		}
	}
	
	printf("You are %d days alive.", count);
}

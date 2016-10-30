#include "superior.hpp"
#include <conio.h>

int main()
{
	BUTTON b = newBUTTON();
	b.IsFocused = true;
	b.Background = Red;
	b.Foreground = Blue;
	b.BorderColor = Yellow;
	draw(b);
	getchar();
	erase(b);
	getchar();
}

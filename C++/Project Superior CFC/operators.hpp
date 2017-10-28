/*
	Name: operators.hpp v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 12:54
	Description: Operators used for comparing structures.
*/

#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include "superior.hpp"

bool operator ==(COORD c1, COORD c2)
{
	return c1.X == c2.X && c1.Y == c2.Y;
}

bool operator !=(COORD c1, COORD c2)
{
	return !(c1 == c2);
}

bool operator <(COORD c1, COORD c2)
{
	return c1.X < c2.X && c1.Y < c2.Y;
}

bool operator >(COORD c1, COORD c2)
{
	return c1.X > c2.X && c1.Y > c2.Y;
}

bool operator <=(COORD c1, COORD c2)
{
	return c1.X <= c2.X && c1.Y <= c2.Y;
}

bool operator >=(COORD c1, COORD c2)
{
	return c1.X >= c2.X && c1.Y >= c2.Y;
}

bool operator ==(SMALL_RECT r1, SMALL_RECT r2)
{
	return r1.Left == r2.Left && r1.Top == r2.Top && r1.Right == r2.Right && r1.Bottom == r2.Bottom;
}

bool operator !=(SMALL_RECT r1, SMALL_RECT r2)
{
	return !(r1 == r2);
}

#endif

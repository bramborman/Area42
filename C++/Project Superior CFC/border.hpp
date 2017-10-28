/*
	Name: border.hpp v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 16:14
	Description: Basic UI element for Windows console.
*/

#ifndef BORDER_HPP
#define BORDER_HPP

#include "superior.hpp"

BORDER newBORDER()
{
	BORDER b;
	
	b.BorderType = DBORDER_TYPE;
	b.Visibility = Visible;
	
	b.BackgroundUnderBorder = DBACKGROUND_UNDER_BORDER;
	b.BorderColor	= DCOLOR_FORE_FOCUSED;
	b.Background	= DCOLOR_BACK_FOCUSED;
	
	b.Width  = DWIDTH;
	b.Height = DHEIGHT;
	
	b.HorizontalAlignment	= HLeft;
	b.VerticalAlignment		= VTop;
	b.Margin.X = 0;
	b.Margin.Y = 0;
	
	return b;
}

void draw(const BORDER &b)
{
	if (b.Visibility == Visible)
	{
		COLOR foregroundBackup = getforeground();
		COLOR backgroundBackup = getbackground();
		SMALL_RECT rect = measure(b.Width, b.Height, b.Margin, b.HorizontalAlignment, b.VerticalAlignment);
		
		setforeground(b.BorderColor);
		
		if (b.BackgroundUnderBorder)
		{
			setbackground(b.Background);
		}
		
		movecursor(rect.Left, rect.Top);
		// Cannot use drawline() or for() with putchar() 'cause therefore there will be little gaps between each line()
		fputs(createline(line(b.BorderType, Edge_Top_Left), line(b.BorderType, Horizontal), line(b.BorderType, Edge_Top_Right), b.Width - 2), stdout);
		
		for (int i = 1; i <= b.Height - 2; i++)
		{
			movecursor(rect.Left, rect.Top + i);
			putchar(line(b.BorderType, Vertical));
			
			fillbackground(b.Background, rect.Left + 1, rect.Top + i, b.Width - 2);
			
			movecursor(rect.Right, rect.Top + i);
			putchar(line(b.BorderType, Vertical));
		}
		
		movecursor(rect.Left, rect.Bottom);
		fputs(createline(line(b.BorderType, Edge_Bottom_Left), line(b.BorderType, Horizontal), line(b.BorderType, Edge_Bottom_Right), b.Width - 2), stdout);
		
		setforeground(foregroundBackup);
		setbackground(backgroundBackup);
	}
}

void erase(const BORDER &b)
{
	COLOR foregroundBackup = getforeground();
	SMALL_RECT rect = measure(b.Width, b.Height, b.Margin, b.HorizontalAlignment, b.VerticalAlignment);
	
	setforeground(getbackground());
	
	movecursor(rect.Left, rect.Top);
	fputs(createline(line(b.BorderType, Edge_Top_Left), line(b.BorderType, Horizontal), line(b.BorderType, Edge_Top_Right), b.Width - 2), stdout);
	
	for (int i = 1; i <= b.Height - 2; i++)
	{
		movecursor(rect.Left, rect.Top + i);
		putchar(line(b.BorderType, Vertical));
		
		fillbackground(getbackground(), rect.Left + 1, rect.Top + i, b.Width - 2);
		
		movecursor(rect.Right, rect.Top + i);
		putchar(line(b.BorderType, Vertical));
	}
	
	movecursor(rect.Left, rect.Bottom);
	fputs(createline(line(b.BorderType, Edge_Bottom_Left), line(b.BorderType, Horizontal), line(b.BorderType, Edge_Bottom_Right), b.Width - 2), stdout);
	
	setforeground(foregroundBackup);
}

#endif

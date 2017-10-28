/*
	Name: textblock.hpp v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 16:14
	Description: Basic UI element for Windows console.
*/

#ifndef TEXTBLOCK_HPP
#define TEXTBLOCK_HPP

#include "superior.hpp"

TEXTBLOCK newTEXTBLOCK()
{
	TEXTBLOCK t;
	
	t.Text = strdup("Text");
	
	t.Visibility = Visible;
	
	t.Foreground = DCOLOR_FORE_FOCUSED;
	t.Background = DCOLOR_BACK_FOCUSED;
	
	t.Width  = DWIDTH;
	t.Height = DHEIGHT;
	
	t.HorizontalAlignment	= HLeft;
	t.VerticalAlignment		= VTop;
	t.Margin.X = 0;
	t.Margin.Y = 0;
	
	return t;
}

void draw(const TEXTBLOCK &t)
{
	if (t.Visibility == Visible)
	{
		COLOR foregroundBackup = getforeground();
		COLOR backgroundBackup = getbackground();
		SMALL_RECT rect = measure(t.Width, t.Height, t.Margin, t.HorizontalAlignment, t.VerticalAlignment);
		
		for (int i = 0; i < t.Height; i++)
		{
			fillbackground(t.Background, rect.Left, rect.Top + i, t.Width);
		}
		
		setforeground(t.Foreground);
		setbackground(t.Background);
		
		center(rect.Left, rect.Right + 1, rect.Top, rect.Bottom + 1, t.Text);
		
		setforeground(foregroundBackup);
		setbackground(backgroundBackup);
	}
}

void erase(const TEXTBLOCK &t)
{
	COLOR foregroundBackup = getforeground();
	SMALL_RECT rect = measure(t.Width, t.Height, t.Margin, t.HorizontalAlignment, t.VerticalAlignment);
	
	for (int i = 0; i < t.Height; i++)
	{
		fillbackground(getbackground(), rect.Left, rect.Top + i, t.Width);
	}
	
	setforeground(getbackground());
	center(rect.Left, rect.Right + 1, rect.Top, rect.Bottom + 1, createline(' ', strlen(t.Text)));
	setforeground(foregroundBackup);
}

#endif

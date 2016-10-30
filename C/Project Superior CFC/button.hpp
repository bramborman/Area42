/*
	Name: button.hpp v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 16:07
	Description: Basic UI element for Windows console.
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "superior.hpp"

BUTTON newBUTTON()
{
	BUTTON b;
	
	b.Text = strdup("Button");
	b.HorizontalTextAlignment	= HCenter;
	b.VerticalTextAlignment		= VCenter;
	
	b.BackgroundUnderBorder = DBACKGROUND_UNDER_BORDER;
	b.IsEnabled = true;
	b.IsFocused = false;
	
	b.BorderType = DBORDER_TYPE;
	b.Visibility = Visible;
	
	b.Foreground			= DCOLOR_FORE_FOCUSED;
	b.UnfocusedForeground	= DCOLOR_FORE_UNFOCUSED;
	b.DisabledForeground	= DCOLOR_FORE_DISABLED;
	
	b.Background			= DCOLOR_BACK_FOCUSED;
	b.UnfocusedBackground	= DCOLOR_BACK_UNFOCUSED;
	b.DisabledBackground	= DCOLOR_BACK_DISABLED;
	
	b.BorderColor			= b.Foreground;
	b.UnfocusedBorderColor	= b.UnfocusedForeground;
	b.DisabledBorderColor	= b.DisabledForeground;
	
	b.Width  = DWIDTH;
	b.Height = DHEIGHT;
	
	b.HorizontalAlignment = HLeft;
	b.VerticalAlignment   = VTop;
	b.Margin.X = 0;
	b.Margin.Y = 0;
	
	return b;
}

void draw(const BUTTON &b)
{
	if (b.Visibility == Visible)
	{
		COLOR bForeground, bBackground, bBorderColor;
		
		if (!b.IsEnabled)
		{
			bForeground  = b.DisabledForeground;
			bBackground  = b.DisabledBackground;
			bBorderColor = b.DisabledBorderColor;
		}
		else if (!b.IsFocused)
		{
			bForeground  = b.UnfocusedForeground;
			bBackground  = b.UnfocusedBackground;
			bBorderColor = b.UnfocusedBorderColor;
		}
		else
		{
			bForeground  = b.Foreground;
			bBackground  = b.Background;
			bBorderColor = b.BorderColor;
		}
		
		BORDER border;
		
		border.BorderType = b.BorderType;
		border.Visibility = b.Visibility;
		
		border.BackgroundUnderBorder = b.BackgroundUnderBorder;
		border.BorderColor	= bBorderColor;
		border.Background	= bBackground;
		
		border.Width  = b.Width;
		border.Height = b.Height;
		
		border.HorizontalAlignment	= b.HorizontalAlignment;
		border.VerticalAlignment	= b.VerticalAlignment;
		border.Margin = b.Margin;
		
		draw(border);
		
		COLOR foregroundBackup = getforeground();
		COLOR backgroundBackup = getbackground();
		SMALL_RECT rect = measure(b.Width, b.Height, b.Margin, b.HorizontalAlignment, b.VerticalAlignment);
		
		setforeground(bForeground);
		setbackground(bBackground);
		
		SMALL_RECT textRect = measure(rect.Left + 1, rect.Right, strlen(b.Text), rect.Top + 1, rect.Bottom, 1, COORD_ORIGIN, b.HorizontalTextAlignment, b.VerticalTextAlignment);
		movecursor(textRect.Left, textRect.Top);
		fputs(strndup(b.Text, b.Width - 2), stdout);
		
		setforeground(foregroundBackup);
		setbackground(backgroundBackup);
	}
}

void erase(const BUTTON &b)
{
	BORDER border;
	
	border.BorderType = b.BorderType;
	
	border.Width  = b.Width;
	border.Height = b.Height;
	
	border.HorizontalAlignment	= b.HorizontalAlignment;
	border.VerticalAlignment	= b.VerticalAlignment;
	border.Margin = b.Margin;
	
	erase(border);
	
	COLOR foregroundBackup = getforeground();
	
	SMALL_RECT rect = measure(b.Width, b.Height, b.Margin, b.HorizontalAlignment, b.VerticalAlignment);
	
	setforeground(getbackground());
	
	SMALL_RECT textRect = measure(rect.Left + 1, rect.Right, strlen(b.Text), rect.Top + 1, rect.Bottom, 1, COORD_ORIGIN, b.HorizontalTextAlignment, b.VerticalTextAlignment);
	movecursor(textRect.Left, textRect.Top);
	fputs(strndup(createline(' ', strlen(b.Text)), b.Width - 2), stdout);
	
	setforeground(foregroundBackup);
}

#endif

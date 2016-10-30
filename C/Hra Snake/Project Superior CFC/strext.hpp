/*
	Name: strext.hpp (String extensions) v1.0
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/05/16 12:54
	Description: New and overload functions for working with strings in Windows console.
*/

#ifndef STREXT_HPP
#define STREXT_HPP

#include "superior.hpp"

char *stradd(char *str, char ch, int index)
{
	if (index >= 0 && index <= strlen(str))
	{
		str = (char *)memmove(str + index + 1, str + index, strlen(str) - index + 1);
		*(str + index) = ch;
	}
	
	return str;
}

char *strrem(char *str, int index)
{
	if (index >= 0 && index < strlen(str))
	{
		//													don't add -1 to copy even terminating char
		str = (char *)memmove(str + index, str + index + 1, strlen(str) - index);
	}
	
	return str;
}

char *strndup(const char *source, int count)
{
	if (count < 0)
	{
		count = 0;
	}
	else if (count >= strlen(source))
	{
		return (char *)source;
	}
	
	char *output = (char *)malloc(count + 1);
	
	if (output == NULL)
	{
		return NULL;
	}
	
	strncpy(output, source, count);
	*(output + count) = 0;
	
	return output;
}

char *strcat(char *dest, int sourcesCount, const char *source, ...)
{
	strcat(dest, source);
	
	if (sourcesCount <= 1)
	{
		return dest;
	}
	
	va_list ap;
	va_start(ap, source);
	
	while (sourcesCount-- > 0)
	{
		strcat(dest, va_arg(ap, char *));
	}
	
	va_end(ap);
	return dest;
}

#endif

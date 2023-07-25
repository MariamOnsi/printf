#include "main.h"
#include <ctype.h>

/**
 * get_width - calculates the width
 * @format: format string to ptint the arguments
 * @i: list of args to be printed
 * @list: list of args
 * Return: width
*/

int get_width(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int width = 0;

	for (; format[curr_i] != '\0'; curr_i++)
	{
		if (isdigit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '\0';
		} else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		} else
		{
			break;
		}
	}
	*i = curr_i - 1;

	return (width);
}

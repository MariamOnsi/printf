#include "main.h"
#include <ctype.h>

/**
 * get_precision - calculate precision to print it
 * @format: format string to print the arguments
 * @i: list of args to be printed
 * @list: list of args
 * Return: precision
*/

int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
	{
		return (precision);
	}

	precision = 0;
	while (format[curr_i] != '\0')
	{
		if (isdigit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		} else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		} else
		{
			break;
		}
		curr_i++;
	}
	*i = curr_i - 1;

	return (precision);
}

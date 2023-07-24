#include "main.h"

/**
 * printf_pointer - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_pointer(va_list val)
{
	void *ptr;
	long int x;
	int y;
	int j;
	char *s = "(nil)";

	ptr = va_arg(val, void*);
	if (ptr == NULL)
	{
		for (j = 0; s[j] != '\0'; j++)
		{
			_putchar(s[j]);
		}
		return (j);
	}

	x = (unsigned long int)ptr;
	_putchar('0');
	_putchar('x');
	y = printf_hex_aux(x);
	return (y + 2);
}

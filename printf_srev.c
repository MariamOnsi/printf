#include "main.h"

/**
 * printf_srev - function that prints a str in reverse
 * @args: type struct va_arg where is allocated printf arguments
 *
 * Return: the string
 */
int printf_srev(va_list args)
{

	char *str = va_arg(args, char*);
	int x;
	int y = 0;

	if (str == NULL)
		str = "(null)";
	while (str[y] != '\0')
		y++;
	for (x = y - 1; x >= 0; x--)
		_putchar(str[x]);
	return (y);
}

#include "main.h"
/**
 * printf_exclusive_string - print exclusuives string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int printf_exclusive_string(va_list val)
{
	char *strr;
	int j;
	int length = 0;
	int cast;

	strr = va_arg(val, char *);
	if (strr == NULL)
		strr = "(null)";
	for (j = 0; strr[j] != '\0'; j++)
	{
		if (strr[j] < 32 || strr[j] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			length = length + 2;
			cast = strr[j];
			if (cast < 16)
			{
				_putchar('0');
				length++;
			}
			length = length + printf_HEX_aux(cast);
		}
		else
		{
			_putchar(strr[j]);
			length++;
		}
	}
	return (length);
}

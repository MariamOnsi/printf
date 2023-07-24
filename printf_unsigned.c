#include "main.h"
/**
 * printf_unsigned - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_unsigned(va_list args)
{
	unsigned int m = va_arg(args, unsigned int);
	int numb, last_num = m % 10, digits, exp = 1;
	int  j = 1;

	m = m / 10;
	numb = m;

	if (last_num < 0)
	{
		_putchar('-');
		numb = -numb;
		m = -m;
		last_num = -last_num;
		j++;
	}
	if (numb > 0)
	{
		while (numb / 10 != 0)
		{
			exp = exp * 10;
			numb = numb / 10;
		}
		numb = m;
		while (exp > 0)
		{
			digits = numb / exp;
			_putchar(digits + '0');
			numb = numb - (digits * exp);
			exp = exp / 10;
			j++;
		}
	}
	_putchar(last_num + '0');

	return (j);
}

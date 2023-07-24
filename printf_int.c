#include "main.h"
/**
 * printf_int - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_int(va_list args)
{
	int m = va_arg(args, int);
	int numb, last_num = m % 10, digits;
	int  j = 1, exp = 1;

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

/**
 * printf_dec - prints decimal
 * @args: argument to print
 * Return: number of characters printed
 */

int printf_dec(va_list args)
{
	int m = va_arg(args, int);
	int numb, last_num = m % 10, digits;
	int  j = 1;
	int exp = 1;

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

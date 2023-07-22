#include "main.h"

/********* PRINT CHAR *********/

/**
 * print_char - Prints a char
 * @kinds: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_char(va_list kinds, char buffer[],
		int flag, int width, int precision, int size)
{
	char c = va_arg(kinds, int);

	return (handle_write_char(c, buffer, flag, width, precision, size));
}

/********* PRINT STRING *********/

/**
 * print_strings - Prints a string
 * @kinds: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_strings(va_list kinds, char buffer[],
		int flag, int width, int precision, int size)
{
	int l = 0;
	int a;
	char *s = va_arg(kinds, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[l] != '\0')
		l++;
	if (precision >= 0 && precision < l)
		l = precision;
	if (width > l)
	{
		if (flag & F_MINUS)
		{
			write(1, &s[0], l);
			for (a = width - l; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - l; a > 0; a--)
				write(1, " ", 1);
			write(1, &s[0], l);
			return (width);
		}
	}
	return (write(1, s, l));
}

/********* PRINT PERCENT SIGN *********/

/**
 * print_percent_sign - Prints a percent sign
 * @kinds: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: int
 */

int print_percent_sign(va_list kinds,
		char buffer[], int flag, int width,
		int precision, int size)
{
	UNUSED(kinds);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(width);

	return (write(1, "%%", 1));
}

/********* PRINT INT *********/

/**
 * print_integer - a function to print int
 * @kinds: list of argument
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_integer(va_list kinds,
		char buffer[], int flag, int width,
		int precision, int size)
{
	int negative = 0;
	int j = BUFF_SIZE - 2;
	long int a = va_arg(kinds, long int);
	unsigned long int num;

	a = convert_size_number(a, size);
	if (a == 0)
		buffer[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)a;
	if (a < 0)
	{
		num = (unsigned long int)((-1) * a);
		negative = 1;
	}
	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}
	j++;
	return (write_number(negative, j, buffer, flag, width, precision, size));
}

/********* PRINT BINARY *********/


/**
 * print_binary_num - Prints an unsigned number
 * @kinds: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */

int print_binary_num(va_list kinds,
		char buffer[], int flag, int width,
		int precision, int size)
{
	unsigned int x, y, j, total;
	unsigned int arr[32];
	int count;
	char c;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(kinds, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	arr[0] = x / y;
	for (j = 1; j < 32; j++)
	{
		y /= 2;
		arr[j] = (x / y) % 2;
	}
	for (j = 0, total = 0, count = 0; j < 32; j++)
	{
		total += arr[j];
		if (total || j == 31)
		{
			c = '0' + arr[j];
			write(1, &c, 1);
				count++;
		}
	}
	return (count);
}

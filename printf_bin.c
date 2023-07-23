#include "main.h"

/**
 * printf_bin - prints a binary number.
 * @val: arguments.
 * Return: 1.
 */
int printf_bin(va_list val)
{
	int j, y;
	int x = 1;
	int flag = 0;
	int add = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int num1;

	for (j = 0; j < 32; j++)
	{
		num1 = ((x << (31 - j)) & num);
		if (num1 >> (31 - j))
			flag = 1;
		if (flag)
		{
			y = num1 >> (31 - j);
			_putchar(y + 48);
			add++;
		}
	}
	if (add == 0)
	{
		add++;
		_putchar('0');
	}
	return (add);
}

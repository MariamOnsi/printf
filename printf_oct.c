#include "main.h"

/**
 * printf_oct - prints an octal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_oct(va_list val)
{
	int j, *arr;
	int count = 0;
	unsigned int numb = va_arg(val, unsigned int);
	unsigned int temp = numb;

	while (numb / 8 != 0)
	{
		numb /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (j = 0; j < count; j++)
	{
		arr[j] = temp % 8;
		temp /= 8;
	}
	for (j = count - 1; j >= 0; j--)
	{
		_putchar(arr[j] + '0');
	}
	free(arr);
	return (count);
}

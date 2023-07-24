#include "main.h"

/**
 * printf_hex - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_hex(va_list val)
{
	int k;
	int *arr;
	int count = 0;
	unsigned int numb = va_arg(val, unsigned int);
	unsigned int temp = numb;

	while (numb / 16 != 0)
	{
		numb /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (k = 0; k < count; k++)
	{
		arr[k] = temp % 16;
		temp /= 16;
	}
	for (k = count - 1; k >= 0; k--)
	{
		if (arr[k] > 9)
			arr[k] = arr[k] + 39;
		_putchar(arr[k] + '0');
	}
	free(arr);
	return (count);
}

#include "main.h"
/**
 * printf_rot13 - printf str to ROT13 place into buffer
 * @args: type struct va_arg where is allocated printf arguments
 * Return: counter
 *
 */
int printf_rot13(va_list args)
{
	int x, y, count = 0, k = 0;
	char *str = va_arg(args, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (str == NULL)
		str = "(null)";
	for (x = 0; str[x]; x++)
	{
		k = 0;
		for (y = 0; alpha[y] && !k; y++)
		{
			if (str[x] == alpha[y])
			{
				_putchar(beta[y]);
				count++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(str[x]);
			count++;
		}
	}
	return (count);
}

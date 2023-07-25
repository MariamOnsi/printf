#include "main.h"

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * get_flags - calculates active flags
 * @format: format string to print the arguments
 * @i: take parameter
 * Return: flags
*/

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16  */

	int j, curr_i = *i + 1;
	int flags = 0;
	const char Flags_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int Flags_arr[] = {F_MINUS, F_PLUS, F_ZERO,
		F_HASH, F_SPACE, 0};

	while (format[curr_i] != '\0')
	{
		for (j = 0; Flags_ch[j] != '\0'; j++)
		{
			if (format[curr_i] == Flags_ch[j])
			{
				flags |= Flags_arr[j];
				break;
			}
		}
		if (Flags_ch[j] == 0)
		{
			break;
		}
		curr_i++;
	}
	*i = curr_i - 1;

	return (flags);
}

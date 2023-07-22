#include "main.h"

/************ PRINT UNSIGNED NUMBER **********/

/**
 * print_unsigned_num - Prints an unsigned number
 * @kinds: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int print_unsigned_num(va_list kinds,
		char buffer[], int flag, int width,
		int precision, int size)
{
	 int j = BUFF_SIZE - 2;
	 unsigned long int num = va_arg(kinds, unsigned long int);

	 num = convert_size_unsgnd(num, size);
	 if (num == 0)
		 buffer[j--] = '0';
	 buffer[BUFF_SIZE - 1] = '\0';
	 while (num > 0)
	 {
		 buffer[j--] = (num % 10) + '0';
		 num /= 10;
	 }
	 j++;
	 return (write_unsgnd(0, j, buffer, flag, width, precision, size));
}

/********* PRINT UNSIGNED NUMBER IN OCTAL  ***********/

/**
 * print_unsigned_octal_num - Prints an unsigned number in octal notation
 * @kinds: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_unsigned_octal_num(va_list kinds,
		char buffer[], int flag, int width,
		int precision, int size)
{
	unsigned long int oct = va_arg(kinds, unsigned long int);
	int j = BUFF_SIZE - 2;
	unsigned long int init_num_oct = oct;

	UNUSED(width);
	oct = convert_size_unsgnd(oct, size);
	 if (oct == 0)
		 buffer[j--] = '0';
	 buffer[BUFF_SIZE - 1] = '\0';
	 while (oct > 0)
	 {
		  buffer[j--] = (oct % 8) + '0';
		  oct /= 8;
	 }
	 if (flag & F_HASH && init_num_oct != 0)
		 buffer[j--] = '0';
	  j++;
	  return (write_unsgnd(0, j, buffer, flag, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/

/**
 * print_hexadecimal_num - Prints an unsigned number in hexadecimal notation
 * @kinds: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hexadecimal_num(va_list kinds,
		char buffer[],int flag,
		int width, int precision, int size)
{
	return (print_hexa_num(kinds, "0123456789abcdef", buffer,
				flag, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/

/**
 * print_hexa_upper_num - Prints an unsigned number in upper hexadecimal notation
 * @kinds: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hexa_upper_num(va_list kinds,
		char buffer[], int flag, int width,
		int precision, int size)
{
	return (print_hexa_num(kinds, "0123456789ABCDEF", buffer,
				flag, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/

/**
 * print_hexa_num - Prints a hexadecimal number in lower or upper
 * @kinds: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */

int print_hexa_num(va_list kinds, char map_to[],
		char buffer[], int flag, char flag_ch,
		int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
        unsigned long int num_hex = va_arg(kinds, unsigned long int);
        unsigned long int upper = num_hex;

        UNUSED(width);

        num_hex = convert_size_unsgnd(num_hex, size);
        if (num_hex == 0)
                buffer[j--] = '0';
        buffer[BUFF_SIZE - 1] = '\0';
        while (num_hex > 0)
        {
                buffer[j--] = map_to[num_hex % 16];
                num_hex /= 16;
        }
        if (flag & F_HASH && upper != 0)
        {
                buffer[j--] = flag_ch;
                buffer[j--] = '0';
        }
        j++;
        return (write_unsgnd(0, j, buffer, flag, width, precision, size));
}






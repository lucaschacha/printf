#include "main.h"

/************************* PRINTS UNSIGNED DIGIT *************************/
/**
 * print_unsigned - Prints unsigned num
 * @types: List a of arg
 * @buffer: Buffer array to handle prints
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision and its specification
 * @size: Size specifier
 * Return: Num of characters to be printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINTS UNSIGNED DIGIT IN OCTAL  ****************/
/**
 * print_octal - Print an unsigned num in octal notation
 * @types: Lista of argu
 * @buffer: Buffer array to handle prints
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision and its specification
 * @size: Size specifier
 * Return: Num of characters to be printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINTS UNSIGNED NUMB IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Print an unsigned num in hexadecimal notation
 * @types: Lista of arg
 * @buffer: Buffer array to handle prints
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision and its specification
 * @size: Size specifier
 * Return: Num of characters to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINTS UNSIGNED DIGITS IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Print the unsigned digit in upper hexadecimal notation
 * @types: Lista of arg
 * @buffer: Buffer array to handle print
 * @flags:  Calculate the active flags
 * @width: get width
 * @precision: Precision and its specification
 * @size: Size specifier
 * Return: Num of characters to be printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINTS HEXX NUMBER IN LOWER OR UPPER CASES **************/
/**
 * print_hexa - Print a hexadecimal num in lower or upper case
 * @types: Lista of arg
 * @map_to: Array of values to map the num to
 * @buffer: Buffer array to handle prints
 * @flags:  Calculate active flags
 * @flag_ch: Calculate active flags
 * @width: get width
 * @precision: Precision and its specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Num of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

#include "main.c"

void print_buffer(char buffer [], int *buff_ind);

/**
 * _printf - Printf function 
 * @format: format code to std_format.
 * Return: Prints chars.
 * /
int _printf(const char *format, ...)
{
        int i, printed = 0, print_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer [BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list,format);

	for (i=0; format && format [i] != '\0'; i++)

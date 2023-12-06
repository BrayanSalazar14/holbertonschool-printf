/*
 *Authors: -Brayan Salazar
 *	   -Camilo Fetecua
 */

#include "main.h"

/**
 * formatSpecifier - Format specifier function for printf-like functionality.
 * @format: The format specifier character.
 * @arguments: A va_list of arguments to be processed based on the format.
 *
 * Return: The number of characters printed (excluding null-terminating byte).
 *
 * Description:
 * - 'c': Print a single character.
 * - 's': Print a null-terminated string.
 * - 'd' or 'i': Print an integer.
 * - '%': Print a literal '%' character.
 * If the format is not recognized, print the format character as is.
 */
int formatSpecifier(char format, va_list arguments)
{
	if (format == 'c')
		return (printChar(arguments));

	else if (format == 's')
		return (printString(arguments));

	else if (format == 'd' || format == 'i')
		return (printNumsInt(arguments));

	else if (format == '%')
		return (printPercent(arguments));

	else if (format == 'b')
		return (printBinary(va_arg(arguments, unsigned int)));

	else if (format == 'u')
		return (printU(arguments));

	else
	{
		write(1, "%", 1);
		write(1, &format, 1);
		return (2);
	}
}


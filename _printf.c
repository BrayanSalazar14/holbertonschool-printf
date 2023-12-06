/*
 *Authors: -Brayan Salazar
 *	   -Camilo Fetecua
 */

#include "main.h"

/**
 * _printf - Custom printf function with limited format specifiers.
 * @format: A format string containing format specifiers.
 *
 * Return: The number of characters printed (excluding null-terminating byte).
 *
 * Description:
 * - Supports '%c' for characters.
 * - Supports '%s' for strings.
 * - Supports '%d' and '%i' for integers.
 * - Supports '%%' to print a literal '%'.
 * - Returns -1 if the format string is NULL or if it only contains a single %
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list arguments;
	const char *pf;

	va_start(arguments, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (pf = format; *pf != '\0'; pf++)
	{
		if (*pf == '%' && *(pf + 1) != '\0')
		{
			pf++;
			count += formatSpecifier(*pf, arguments);
		}
		else
		{
			write(1, pf, 1);
			count++;
		}
	}
	va_end(arguments);
	return (count);
}

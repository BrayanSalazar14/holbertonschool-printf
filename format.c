#include "main.h"

int formatSpecifier(char format, va_list arguments)
{
	if (format == 'c')
		return (printChar(arguments));

	else if (format == 's')
		return (printString(arguments));

	else if (format == 'd' || format == 'i')
		return (printNumsInt(arguments));

	else if (format == '%')
	{
		return (printPercent(arguments));
	}

		write(1, "%", 1);
		write(1, &format, 1);
		return (2);
}


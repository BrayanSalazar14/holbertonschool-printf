#include "main.h"
#include <stddef.h>
#include <unistd.h>

int printChar(va_list arguments)
{
	char c = va_arg(arguments, int);

	write(1, &c, 1);
	return (1);
}

int printString(va_list arguments)
{
	int count = 0;
	char *s = va_arg(arguments, char *);

	if (s == NULL)
		s = "(null)";

	while (s[count] != '\0')
		count++;

	write(1, s, count);
	return (count);
}

int printPercent(va_list arguments)
{
	(void)arguments;
	write(1, "%", 1);
	return (1);
}

int countNum(unsigned int n)
{
	int count;
	unsigned int x, y;
	char digitChar;

	if (n != 0)
	{
		count = 0;

		x = (n / 10);
		y = (n % 10);
		count += countNum(x);
		count++;
		digitChar = y + '0';
		write(1, &digitChar, 1);
		return (count);
	}
	return (0);
}
int printNumsInt(va_list arguments)
{
	int num, signCont = 0;
	unsigned int numberCont;

	num = va_arg(arguments, int);

	if (num < 0)
	{
		write(1, "-", 1);
		signCont = 1;
		numberCont = num * (-1);
	}
	else
		numberCont = num;

	if (numberCont > 0)
		return (signCont + countNum(numberCont));

	write(1, "0", 1);

	return (1);
}

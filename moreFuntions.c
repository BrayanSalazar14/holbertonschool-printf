/*
 *Authors: -Brayan Salazar
 *	   -Camilo Fetecua
 */

#include "main.h"

/**
 * printBinary - Print the binary representation of an unsigned integer.
 * @num: Unsigned integer to print in binary.
 *
 * This function prints the binary representation of the provided number.
 *
 * Return: The count of digits printed in the binary representation.
 */
int printBinary(unsigned int num)
{
	char digit;
	int count = 0;

	if (num > 1)
		count += printBinary(num / 2);

	digit = (num % 2) + '0';
	write(1, &digit, 1);
	count++;

	return (count);
}

/**
 * printU - Print an unsigned integer.
 * @arguments: A va_list containing the unsigned integer to print.
 *
 * Return: The number of characters printed (excluding null-terminating byte).
 */
int printU(va_list arguments)
{
	unsigned int num = va_arg(arguments, unsigned int);

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (countNum(num));
}

/**
 * rot13 - Converts string to rot13
 * @list: string to convert
 * Return: converted string
 */
int rot13(va_list arguments)
{
	char *s = va_arg(arguments, char *);
	int i, j;
	char orden[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char transformed, c;
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		c = s[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			transformed = c;
			for (j = 0; j < 52; j++)
			{
				if (c == orden[j])
				{
					transformed = rot13[j];
					break;
				}
			}
			write(1, &transformed, 1);
		}
		else
		{
			write(1, &c, 1);
		}
	}
	return (i);
}

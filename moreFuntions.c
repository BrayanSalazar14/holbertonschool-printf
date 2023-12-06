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
 * printRev - Print a string in reverse order.
 * @s: A pointer to the null-terminated string to print in reverse.
 *
 * This function prints the characters of the input string in reverse order
 * using the write system call. It also returns the length of the original
 * string (excluding the null-terminating byte).
 *
 * Return: The length of the original string.
 */
int printRev(va_list arguments)
{
	int count = 0;
	int length;
	char *rev = va_arg(arguments, char *);

	while(rev[count] != '\0')
		count++;

	length = count;

	for(count = length - 1; count >= 0; count--)
		write(1, &rev[count], 1);

	return(length);
}

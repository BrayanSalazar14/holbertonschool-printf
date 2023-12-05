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

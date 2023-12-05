#include "main.h"

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

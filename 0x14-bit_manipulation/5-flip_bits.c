#include <stdio.h>
#include "main.h"

/**
 * flip_bits - eturns the number of bits you would need to flip
 * @n: given number #1
 * @m: given number #2
 * Return: number of bits to be changed
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int counter = 0;
	unsigned long int xor = n ^ m;

	while (xor != 0)
	{
		if ((xor & 1) == 1)
			counter++;

		xor >>= 1;
	}
	return (counter);
}

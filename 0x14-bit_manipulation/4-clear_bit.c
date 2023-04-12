#include "main.h"
#include <stdio.h>

/**
 * clear_bit - function that sets the value of a bit to 0 at a given index.
 * @n: the given number to be changed
 * @index: the given index og the bit to be manipulated
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x = 1;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	x <<= index;

	*n = (*n & ~x);

	return (1);
}

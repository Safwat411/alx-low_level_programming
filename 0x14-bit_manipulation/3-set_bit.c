#include <stdio.h>
#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index.
 * @n: pointer to the number to be changed
 * @index: the given index of bit to be set to 1
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x = 1;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	x <<= index;

	*n = (*n | x);

	return (1);
}

#include "main.h"
#include <stdio.h>

/*
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b: a pointer to a string of zeros and ones
 * Return: the number has been converted or 0
 */

unsigned int binary_to_uint(const char *b)
{
	int n;
	unsigned int dc = 0;

	if (b == NULL)
		return (0);
	for (n = 0; b[n] != '\0'; n++)
	{
		if (b[n] == '0')
			dc = dc * 2 + 0;
		else if (b[n] == '1')
			dc = dc * 2 + 1;
		else
			return (0);
	}
	return (dc);
}

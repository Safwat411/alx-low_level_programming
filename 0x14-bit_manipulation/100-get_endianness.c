#include <stdio.h>
#include "main.h"

/**
 * get_endianness - function that checks the endianness.
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int number = 1;
	char *e = (char *)&number;

	if (*e == 1)
		return (1);
	else
		return (0);
}

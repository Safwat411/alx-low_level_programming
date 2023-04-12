#include "main.h"
#include <stdio.h>

/**
 * print_binary - function that prints a number in the binary representation
 * @n: the number to be printed in binary
 */

void print_binary(unsigned long int n)
{
	int f;
	unsigned long int l;

	f = 0;

	for (l = 1UL << 63; l > 0; l >>= 1)
	{
		if (n & l)
		{
			_putchar('1');
			f = 1;
		}
		else if (f)
			_putchar('0');
	}
	if (!f)
		_putchar('0');
}

#include "main.h"

/**
 * print_rev - function that prints a string, in reverse
 * followed by a new line.
 * @s: string
 */

void print_rev(char *s)
{
	int L = 0;
	int o;

	while (*s != '\0')
	{
		L++;
		s++;
	}
	s--;
	for (o = L; o > 0; o--)
	{
		_putchar(*s);
		s--;
	}
	_putchar('\n');
}

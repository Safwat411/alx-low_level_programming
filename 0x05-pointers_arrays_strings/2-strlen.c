#include "main.h"

/**
 * _strlen - function that returns the length of a string.
 * @s: string
 * Return: Lenght
 */

int _strlen(char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}

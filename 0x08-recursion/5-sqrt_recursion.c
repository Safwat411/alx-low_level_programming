#include "main.h"

int actual_sqrt(int n, int i);

/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: number
 * Return: Return the root
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (actual_sqrt(n, 0));
}

/**
 * actual_sqrt - function that returns the natural square root of a number
 * @n: number
 * @i: riit of n
 * Return: Return the root
 */

int actual_sqrt(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (actual_sqrt(n, i + 1));
}

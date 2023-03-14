#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that multiplies two numbers.
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0
 */

int main (int argc, char *argv[])
{
	int i;
	int mul = 1;

	if (argc == 1)
	{
		printf("Error\n");
		return (1);
	}
	else if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			mul = mul * atoi(argv[i]);
		}
		printf("%d\n", mul);
	}
	return (0);
}

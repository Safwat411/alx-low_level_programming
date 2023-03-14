#include <stdio.h>

/**
 * main - program that prints its name, followed by a new line.
 * @argc: Argument counr
 * @argv: Argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	printf("%s\n", argv[argc - 1]);

	return (0);
}

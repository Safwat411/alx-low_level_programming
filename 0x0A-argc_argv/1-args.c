#include <stdio.h>

/**
 * main - program that prints the number of arguments passed into it.
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0
 */

int main(int argc,char *argv[])
{
	printf("%d\n%s", argc, argv[argc]);
	return (0);
}

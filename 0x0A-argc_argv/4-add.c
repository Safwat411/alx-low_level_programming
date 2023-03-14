#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
/**
 * check_num - function to check numbers
 * @str: String
 * Return: 0 if it's a number, otherwise 1
 */

int check_num(char *str)
{
	unsigned int count = 0;

	while (count < strlen(str))
	{
		if (!isdigit(str[count]))
		{
			return (0);
		}
		count++;
	}
	return (1);
}

/**
 * main - function that adds positive numbers.
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 if it's a symble, otherwise 1
 */

int main(int argc, char *argv[])
{
	int count = 1;
	int sum = 0;

	while (count < argc)
	{
		if (check_num(argv[count]))
		{
			sum += atoi(argv[count]);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
		count++;
	}
	printf("%d\n", sum);
	return (0);
}

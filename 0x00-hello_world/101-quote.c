#include <unistd.h>
/**
 * main - Entering the required message
 * write - printing the message without using printf() or puts()
 * Return: Always 1
 */
int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}

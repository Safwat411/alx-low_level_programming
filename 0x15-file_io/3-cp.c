#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

/**
 * main - Copies the content of one file to another file
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 * Return: 0 on success
 */

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
	int fd_from, fd_to;
	ssize_t nread;
	char buf[BUF_SIZE];
	char error_msg[BUF_SIZE];

	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3) 
	{
	write(STDERR_FILENO, "Usage: cp file_from file_to\n", 28);
	exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1) 
	{
	snprintf(error_msg, BUF_SIZE, "Error: Can't read from file %s\n", argv[1]);
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (fd_to == -1) 
	{
	char error_msg[BUF_SIZE];
	snprintf(error_msg, BUF_SIZE, "Error: Can't write to %s\n", argv[2]);
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	exit(99);
	}

	while ((nread = read(fd_from, buf, BUF_SIZE)) > 0) 
	{
	if (write(fd_to, buf, nread) != nread)
	{
	char error_msg[BUF_SIZE];
	snprintf(error_msg, BUF_SIZE, "Error: Can't write to %s\n", argv[2]);
	write(STDERR_FILENO, error_msg, strlen(error_msg));
		exit(99);
	}
	}

	if (nread == -1)
	{
		char error_msg[BUF_SIZE];
	snprintf(error_msg, BUF_SIZE, "Error: Can't read from file %s\n", argv[1]);
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		exit(98);
	}

	if (close(fd_from) == -1)
	{
		char error_msg[BUF_SIZE];
	snprintf(error_msg, BUF_SIZE, "Error: Can't close fd %d\n", fd_from);
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		exit(100);
	}

	if (close(fd_to) == -1)
	{
	char error_msg[BUF_SIZE];
	snprintf(error_msg, BUF_SIZE, "Error: Can't close fd %d\n", fd_to);
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	exit(100);
	}

	exit(EXIT_SUCCESS);
}

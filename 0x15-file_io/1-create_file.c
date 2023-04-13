#include "main.h"
#include <string.h>

/**
 * create_file - function that creates a file.
 * @filename: pointer to the file to be created
 * @text_content: A NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int bytes_written;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
	bytes_written = write(fd, text_content, strlen(text_content));
	if (bytes_written == -1 || (size_t) bytes_written != strlen(text_content))
	{
		close(fd);
		return (-1);
	}
	}
	close(fd);
	return (1);
}

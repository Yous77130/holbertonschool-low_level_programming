#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t w;
	size_t len;
	char *tmp;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}
	len = 0;
	tmp = text_content;
	while (*tmp++)
		len++;
	w = write(fd, text_content, len);
	close(fd);
	if (w == -1 || (size_t)w != len)
		return (-1);
	return (1);
}

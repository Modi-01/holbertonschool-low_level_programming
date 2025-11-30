#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: pointer to the name of the file
 * @text_content: pointer to a NULL-terminated string to add
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len = 0;
	ssize_t w_bytes;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;

		if (len > 0)
		{
			w_bytes = write(fd, text_content, len);
			if (w_bytes == -1 || w_bytes != len)
			{
				close(fd);
				return (-1);
			}
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}

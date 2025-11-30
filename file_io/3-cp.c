#include "main.h"
#include <stdio.h>

/**
 * open_file_from - opens the source file
 * @file_from: name of the file to copy from
 *
 * Return: file descriptor of the source file
 */
int open_file_from(const char *file_from)
{
	int fd_from;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	return (fd_from);
}

/**
 * open_file_to - opens or creates the destination file
 * @file_to: name of the file to copy to
 *
 * Return: file descriptor of the destination file
 */
int open_file_to(const char *file_to)
{
	int fd_to;

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file_to);
		exit(99);
	}

	return (fd_to);
}

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor to close
 *
 * Return: void
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_content - copies the content from one file to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: name of the source file
 * @file_to: name of the destination file
 *
 * Return: void
 */
void copy_content(int fd_from, int fd_to,
		  const char *file_from, const char *file_to)
{
	ssize_t r_bytes, w_bytes;
	char buffer[1024];

	while ((r_bytes = read(fd_from, buffer, 1024)) > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes == -1 || w_bytes != r_bytes)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file_to);
			close_file(fd_from);
			close_file(fd_to);
			exit(99);
		}
	}

	if (r_bytes == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", file_from);
		close_file(fd_from);
		close_file(fd_to);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file_from(argv[1]);
	fd_to = open_file_to(argv[2]);
	copy_content(fd_from, fd_to, argv[1], argv[2]);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}

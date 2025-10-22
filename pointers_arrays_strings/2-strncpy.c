#include "main.h"

/**
 * _strncpy - copy at most n bytes from src to dest (like strncpy)
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Description: If src is shorter than n, pad the remainder of dest with '\0'.
 * If src length is >= n, no terminating null byte is added to dest.
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

#include "main.h"

/**
 * _strncpy - copy at most n bytes from src to dest
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Description: Behaves like the standard strncpy. If src is shorter than n,
 * the remaining bytes in dest are padded with '\0'. If src length is at
 * least n, no terminating null byte is added.
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

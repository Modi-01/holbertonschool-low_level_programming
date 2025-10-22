#include "main.h"

/**
 * _strncpy - copy at most n bytes from src to dest
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Description: Behaves like standard strncpy.
 * If src is shorter than n, pad the rest of dest with '\0'.
 * If src length is >= n, do not add a terminating '\0'.
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* copy from src to dest while both n not exhausted and src not ended */
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	/* if src ended before n, pad remaining bytes with '\0' */
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

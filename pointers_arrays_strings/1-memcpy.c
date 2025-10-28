#include "main.h"

/**
 * _memcpy - copies a memory area
 * @dest: destination buffer
 * @src: source buffer
 * @n: number of bytes to copy
 *
 * Description: Copies @n bytes from memory area @src to @dest.
 * Overlap is undefined (use memmove for overlaps).
 *
 * Return: pointer to @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}


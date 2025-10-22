#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: buffer where the string is copied
 * @src: string to copy
 * @n: number of bytes to copy from src
 *
 * Description: works exactly like strncpy from the C standard library.
 * If src is shorter than n, the remaining bytes in dest are filled with '\0'.
 *
 * Return: pointer to the resulting string dest
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

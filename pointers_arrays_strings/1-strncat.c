#include "main.h"

/**
 * _strncat - concatenates two strings, using at most n bytes from src
 * @dest: pointer to the destination buffer
 * @src: pointer to the source string
 * @n: maximum number of bytes to use from src
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* Move to the end of dest */
	while (dest[i] != '\0')
		i++;

	/* Append at most n bytes from src */
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add terminating null byte */
	dest[i] = '\0';

	return (dest);
}

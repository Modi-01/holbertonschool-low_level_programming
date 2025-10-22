#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: pointer to the destination buffer (must have enough space)
 * @src:  pointer to the source string to append
 *
 * Return: pointer to the resulting string @dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* move i to the end of dest */
	while (dest[i] != '\0')
		i++;

	/* copy src (without its terminating '\0') to the end of dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* add the new terminating null byte */
	dest[i] = '\0';

	return (dest);
}

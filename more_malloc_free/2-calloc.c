#include "main.h"
#include <limits.h>

/**
 * _calloc - allocates memory for an array using malloc and sets it to zero.
 * @nmemb: number of elements.
 * @size:   size (in bytes) of each element.
 *
 * Return: pointer to allocated zeroed memory; NULL on failure
 *         or if nmemb == 0 or size == 0 or on overflow.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i, total;
	unsigned char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	/* overflow guard: nmemb * size must fit in unsigned int */
	if (size != 0 && nmemb > (UINT_MAX / size))
		return (NULL);

	total = nmemb * size;

	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);

	/* set allocated memory to zero without using memset */
	p = (unsigned char *)ptr;
	for (i = 0; i < total; i++)
		p[i] = 0;

	return (ptr);
}

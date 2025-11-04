#include "main.h"

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: number of bytes to allocate.
 *
 * Return: pointer to allocated memory.
 *         If malloc fails, the process terminates with status 98.
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (p == NULL)
		exit(98);

	return (p);
}

#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees dogs
 * @d: pointer to dog to free
 *
 * Description: Frees all memory allocated for a dog_t,
 * including its name and owner strings. If @d is NULL,
 * the function does nothing.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}

#include "dog.h"
#include <stddef.h>

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to struct dog to initialize
 * @name: pointer to name to assign
 * @age: age to assign
 * @owner: pointer to owner to assign
 *
 * Description: This function assigns the given name, age,
 * and owner values to the struct dog pointed to by @d.
 * If @d is NULL, the function does nothing.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

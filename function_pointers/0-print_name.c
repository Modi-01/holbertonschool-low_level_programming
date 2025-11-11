#include "function_pointers.h"

/**
 * print_name - call a printing function on a name
 * @name: pointer to the name string
 * @f: pointer to a function that prints a name
 *
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	f(name);
}

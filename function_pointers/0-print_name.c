#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - call a printer function on a given name
 * @name: pointer to the name string
 * @f: pointer to a function that receives (char *) and returns nothing
 *
 * Return: Nothing.
 *
 * Description:
 * If either @name or @f is NULL, the function does nothing to
 * respect robustness and avoid dereferencing invalid pointers.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

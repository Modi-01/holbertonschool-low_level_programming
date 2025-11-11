#include "function_pointers.h"

/**
 * print_name - calls a function given as a parameter on a name
 * @name: Pointer to the name string
 * @f: Pointer to a function that takes (char *) and returns void
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == 0 || f == 0)
		return;

	f(name);
}

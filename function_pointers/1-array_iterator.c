#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - executes a function on each element of an int array
 * @array: pointer to the first element of the array
 * @size: number of elements in @array
 * @action: pointer to a function that takes an int and returns nothing
 *
 * Return: Nothing.
 *
 * Description:
 * If @array or @action is NULL, the function does nothing.
 * Iterates from index 0 to size - 1, calling @action on each element.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}

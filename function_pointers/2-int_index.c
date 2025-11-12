#include "function_pointers.h"

/**
 * int_index - searches for an integer using a compare callback
 * @array: pointer to the first element of the int array
 * @size: number of elements in @array
 * @cmp: pointer to a function that takes an int and returns non-zero on match
 *
 * Return: index of first element for which @cmp does not return 0,
 *         or -1 if no element matches or if @array/@cmp is NULL or @size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == (void *)0 || cmp == (void *)0 || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}

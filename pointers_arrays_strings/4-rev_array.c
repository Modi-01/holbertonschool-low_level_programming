#include "main.h"

/**
 * reverse_array - reverse the content of an array of integers
 * @a: pointer to the first element of the array
 * @n: number of elements in the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i, j, tmp;

	if (n <= 1 || a == 0)
		return;

	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

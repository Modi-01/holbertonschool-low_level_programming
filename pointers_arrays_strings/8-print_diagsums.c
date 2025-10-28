#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of a square matrix (stored in 1D)
 * @size: the width/height of the square matrix
 *
 * Description: The matrix is stored in row-major order in a 1D array.
 * The primary diagonal elements are at indices i * size + i.
 * The secondary diagonal elements are at indices i * size + (size - 1 - i).
 *
 * Return: Nothing.
 */
void print_diagsums(int *a, int size)
{
	int i;
	long int d1 = 0, d2 = 0;

	for (i = 0; i < size; i++)
	{
		d1 += a[i * size + i];
		d2 += a[i * size + (size - 1 - i)];
	}

	printf("%ld, %ld\n", d1, d2);
}

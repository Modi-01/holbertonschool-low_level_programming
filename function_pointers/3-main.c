#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - simple calculator
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Usage: calc num1 operator num2
 * Return: 0 on success, exits with codes 98/99/100 on errors.
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	int (*op_fun)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op_fun = get_op_func(argv[2]);
	if (op_fun == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = op_fun(a, b);
	printf("%d\n", result);
	return (0);
}

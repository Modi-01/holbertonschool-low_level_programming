#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers.
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + '0');          /* 1st usage */

		if (n != 9)
		{
			putchar(',');          /* 2nd usage */
			putchar(' ');          /* 3rd usage */
		}
	}
	putchar('\n');                 /* 4th usage */

	return (0);
}

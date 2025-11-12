#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - Prints strings separated by @separator, then a newline.
 * @separator: String printed between strings (ignored if NULL).
 * @n:        Number of strings passed to the function.
 *
 * Description: If any string argument is NULL, prints (nil) instead.
 * Return: (void)
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	const char *s;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		s = va_arg(args, const char *);
		if (s == NULL)
			printf("(nil)");
		else
			printf("%s", s);

		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}

	printf("\n");
	va_end(args);
}

#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_one - print one argument based on type specifier
 * @t: type specifier ('c', 'i', 'f', 's')
 * @ap: variadic list pointer
 * @sep: in/out current separator to print before the value
 *
 * Return: Nothing.
 */
static void print_one(char t, va_list *ap, const char **sep)
{
	char *s;

	switch (t)
	{
	case 'c':
		printf("%s%c", *sep, (char)va_arg(*ap, int));
		*sep = ", ";
		break;
	case 'i':
		printf("%s%d", *sep, va_arg(*ap, int));
		*sep = ", ";
		break;
	case 'f':
		printf("%s%f", *sep, va_arg(*ap, double));
		*sep = ", ";
		break;
	case 's':
		s = va_arg(*ap, char *);
		if (s == NULL)
			s = "(nil)";
		printf("%s%s", *sep, s);
		*sep = ", ";
		break;
	default:
		break;
	}
}

/**
 * print_all - prints anything according to a format string
 * @format: string of type chars: 'c', 'i', 'f', 's'
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	const char *sep = "";

	va_start(ap, format);

	if (format != NULL)
		while (format[i] != '\0')
			print_one(format[i++], &ap, &sep);

	printf("\n");
	va_end(ap);
}

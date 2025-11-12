#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything according to a format string
 * @format: string of type chars:
 *          'c' char, 'i' int, 'f' float, 's' char* (NULL -> "(nil)")
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *s;
	char *sep = "";
	char t;

	va_start(ap, format);

	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			t = format[i];
			switch (t)
			{
			case 'c':
				printf("%s%c", sep, (char)va_arg(ap, int));
				sep = ", ";
				break;
			case 'i':
				printf("%s%d", sep, va_arg(ap, int));
				sep = ", ";
				break;
			case 'f':
				printf("%s%f", sep, va_arg(ap, double));
				sep = ", ";
				break;
			case 's':
				s = va_arg(ap, char *);
				if (s == NULL)
					s = "(nil)";
				printf("%s%s", sep, s);
				sep = ", ";
				break;
			default:
				break;
			}
			i++;
		}
	}

	printf("\n");
	va_end(ap);
}

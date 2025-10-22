#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string to convert
 *
 * Description:
 * Scan the string until the first digit. Count every '+' and '-'
 * found before the first digit to compute the final sign.
 * If no digits exist, return 0.
 * The numeric value is built as a negative number to handle INT_MIN
 * safely without overflow. Stop at the first non-digit after digits start.
 *
 * Return: the converted integer value
 */
int _atoi(char *s)
{
	char *p = s;
	int sign = 1;
	int started = 0;
	int result = 0; /* keep result non-positive while building */

	/* move to the first digit; accumulate signs */
	while (*p != '\0' && !started)
	{
		if (*p == '-')
			sign = -sign;
		else if (*p == '+')
		{
			/* nothing */
		}
		else if (*p >= '0' && *p <= '9')
			started = 1;

		if (!started)
			p++;
	}

	/* no digits at all */
	if (!started)
		return (0);

	/* build number as negative to safely support INT_MIN */
	while (*p >= '0' && *p <= '9')
	{
		int digit = *p - '0';

		result = (result * 10) - digit;
		p++;
	}

	/* if the overall sign is negative, result is already negative */
	if (sign < 0)
		return (result);

	/* otherwise, flip back to positive */
	return (-result);
}

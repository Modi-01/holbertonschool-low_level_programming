#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string to convert
 *
 * Description:
 * Parse the string until the first digit. Count every '+' and '-'
 * before the first digit to determine the final sign. If no digits
 * exist, return 0. Build the numeric value as a negative number to
 * safely handle INT_MIN without overflow. Stop at the first non-digit
 * after digits start.
 *
 * Return: the converted integer value
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int result = 0; /* keep result non-positive while building */

	/* scan until the first digit; count signs */
	while (s[i] != '\0' && !started)
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] == '+')
		{
			/* do nothing */
		}
		else if (s[i] >= '0' && s[i] <= '9')
			started = 1;

		if (!started)
			i++;
	}

	/* no digits found */
	if (!started)
		return (0);

	/* build number as negative to support INT_MIN safely */
	while (s[i] >= '0' && s[i] <= '9')
	{
		int digit = s[i] - '0';

		result = (result * 10) - digit;
		i++;
	}

	/* if sign is negative, result already negative */
	if (sign < 0)
		return (result);

	/* sign is positive: make the negative result positive */
	return (-result);
}

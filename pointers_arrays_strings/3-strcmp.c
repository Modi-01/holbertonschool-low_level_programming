#include "main.h"

/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Description: Works exactly like the standard strcmp function.
 * It compares two strings character by character.
 * Return: 0 if s1 == s2,
 *         a negative value if s1 < s2,
 *         a positive value if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	return (s1[i] - s2[i]);
}

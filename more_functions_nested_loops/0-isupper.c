#include "main.h"

/**
 * _isupper - Check if a character is an uppercase letter (A-Z).
 * @c: The character code to check (int, typically an unsigned char cast to int).
 *
 * Return: 1 if @c is uppercase, otherwise 0.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

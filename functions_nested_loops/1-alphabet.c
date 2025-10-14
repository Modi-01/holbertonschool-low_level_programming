#include "main.h"

/**
 * print_alphabet - Prints the alphabet in lowercase
 *
 * Description: prints all lowercase letters from 'a' to 'z'
 * followed by a new line. Uses _putchar only twice.
 * Return: void
 */
void print_alphabet(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		_putchar(ch);
	}
	_putchar('\n');
}

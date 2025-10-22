#include "main.h"

/**
 * leet - encode a string into 1337
 * @s: pointer to the string to encode
 *
 * Description: Replaces a/A->4, e/E->3, o/O->0, t/T->7, l/L->1.
 * Uses only two loops and a single if; no switch, no ternary.
 *
 * Return: pointer to the modified string
 */
char *leet(char *s)
{
	int i = 0, j;
	/* matching tables (10 chars) */
	char from[] = "aAeEoOtTlL";
	char to[]   = "4433007711";

	while (s[i] != '\0')         /* loop 1: over the string */
	{
		j = 0;
		while (from[j] != '\0')  /* loop 2: over mappings */
		{
			if (s[i] == from[j]) /* single if in the whole function */
			{
				s[i] = to[j];
				break;
			}
			j++;
		}
		i++;
	}
	return (s);
}

#include "main.h"

/**
 * leet - encode a string into 1337
 * @s: string to encode
 *
 * Return: pointer to s
 */
char *leet(char *s)
{
	int i = 0, j;
	char from[] = "aAeEoOtTlL";
	char to[] = "4433007711";

	while (s[i] != '\0')           /* loop 1 */
	{
		j = 0;
		while (from[j] != '\0')   /* loop 2 */
		{
			if (s[i] == from[j])  /* single if in code */
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_key(char *username, char *key);

/**
 * main - entry point for key generator of crackme5
 * @argc: number of arguments
 * @argv: array of argument strings (expects username)
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char key[7];

	if (argc != 2)
	{
		printf("Correct usage: %s username\n", argv[0]);
		return (1);
	}

	generate_key(argv[1], key);
	printf("%s\n", key);

	return (0);
}

/**
 * generate_key - computes a valid key for crackme5 from a username
 * @username: input username
 * @key: buffer where the generated key will be stored (size >= 7)
 *
 * Return: void
 */
void generate_key(char *username, char *key)
{
	unsigned int i, b;
	size_t len, add;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	len = strlen(username);

	/* 1st character */
	key[0] = l[(len ^ 59) & 63];

	/* 2nd character */
	add = 0;
	for (i = 0; i < len; i++)
		add += username[i];
	key[1] = l[(add ^ 79) & 63];

	/* 3rd character */
	b = 1;
	for (i = 0; i < len; i++)
		b *= username[i];
	key[2] = l[(b ^ 85) & 63];

	/* 4th character */
	b = (unsigned int)username[0];
	for (i = 0; i < len; i++)
		if ((char)b <= username[i])
			b = username[i];
	srand(b ^ 14);
	key[3] = l[rand() & 63];

	/* 5th character */
	b = 0;
	for (i = 0; i < len; i++)
		b += username[i] * username[i];
	key[4] = l[(b ^ 239) & 63];

	/* 6th character */
	b = 0;
	for (i = 0; (char)i < username[0]; i++)
		b = rand();
	key[5] = l[(b ^ 229) & 63];

	key[6] = '\0';
}

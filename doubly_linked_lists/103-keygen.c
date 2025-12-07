#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generate a key depending on a username for crackme5
 * @argc: number of arguments passed
 * @argv: array of arguments (expects the username)
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int i, b;
	size_t len, add;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7];

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	len = strlen(argv[1]);

	/* 1st char of the key */
	p[0] = l[(len ^ 59) & 63];

	/* 2nd char of the key */
	add = 0;
	for (i = 0; i < len; i++)
		add += argv[1][i];
	p[1] = l[(add ^ 79) & 63];

	/* 3rd char of the key */
	b = 1;
	for (i = 0; i < len; i++)
		b *= argv[1][i];
	p[2] = l[(b ^ 85) & 63];

	/* 4th char of the key */
	b = argv[1][0];
	for (i = 0; i < len; i++)
		if ((char)b <= argv[1][i])
			b = argv[1][i];
	srand(b ^ 14);
	p[3] = l[rand() & 63];

	/* 5th char of the key */
	b = 0;
	for (i = 0; i < len; i++)
		b += argv[1][i] * argv[1][i];
	p[4] = l[(b ^ 239) & 63];

	/* 6th char of the key */
	b = 0;
	for (i = 0; (char)i < argv[1][0]; i++)
		b = rand();
	p[5] = l[(b ^ 229) & 63];

	p[6] = '\0';

	printf("%s\n", p);

	return (0);
}

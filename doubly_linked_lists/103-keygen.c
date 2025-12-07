#include <stdio.h>
#include <stdlib.h>

/**
 * main - generate a valid key for crackme5
 * @argc: argument count
 * @argv: argument vector (expects username)
 *
 * Return: 0 on success, 1 on wrong usage
 */
int main(int argc, char *argv[])
{
	char *username;
	char key[7];
	int len, i;
	unsigned int tmp;

	if (argc != 2)
		return (1);

	username = argv[1];

	/* get length of username */
	len = 0;
	while (username[len] != '\0')
		len++;

	/* 1st char of key */
	key[0] = ((len ^ 59) & 63) + 65;

	/* 2nd char: sum of chars */
	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += username[i];
	key[1] = ((tmp ^ 79) & 63) + 65;

	/* 3rd char: product of chars */
	tmp = 1;
	for (i = 0; i < len; i++)
		tmp *= username[i];
	key[2] = ((tmp ^ 85) & 63) + 65;

	/* 4th char: based on max char + rand */
	tmp = username[0];
	for (i = 0; i < len; i++)
		if ((unsigned int)username[i] > tmp)
			tmp = username[i];

	srand(tmp ^ 14);
	key[3] = (rand() & 63) ^ 239;
	key[3] += 65;

	/* 5th char: sum of squares of chars */
	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += username[i] * username[i];
	key[4] = ((tmp ^ 239) & 63) + 65;

	/* 6th char: last rand value */
	tmp = 0;
	for (i = 0; i < len; i++)
		tmp = rand();
	key[5] = ((tmp ^ 229) & 63) + 65;

	key[6] = '\0';

	printf("%s", key);

	return (0);
}

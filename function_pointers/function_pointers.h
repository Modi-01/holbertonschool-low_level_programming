/**
 * File: function_pointers.h
 * Desc: Header with prototypes for function-pointers tasks.
 */

#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 *         On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c);

/**
 * print_name - calls a function given as a parameter on a name
 * @name: Pointer to the name string
 * @f: Pointer to a function that takes (char *) and returns void
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */

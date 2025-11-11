#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/**
 * File: function_pointers.h
 * Desc: Prototypes used in the function pointers tasks.
 */

/**
 * _putchar - Write a character to standard output
 * @c: Character to print
 *
 * Return: 1 on success, or -1 on error with errno set.
 */
int _putchar(char c);

/**
 * print_name - Call a callback function to print a name
 * @name: Pointer to the name string
 * @f: Pointer to a function that takes (char *) and returns void
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */

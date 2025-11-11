#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/**
 * File: function_pointers.h
 * Desc: Prototypes for function pointers tasks.
 */

int _putchar(char c);

/**
 * print_name - prototype for printing a name via a callback
 * @name: pointer to the name string
 * @f: pointer to a function that takes (char *) and returns void
 */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */

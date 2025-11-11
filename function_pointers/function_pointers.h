#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

int _putchar(char c);

/**
 * print_name - prototype: يطبع الاسم عبر استدعاء دالّة مُمرَّرة كمؤشّر
 * @name: مؤشر إلى سلسلة الاسم
 * @f:    مؤشّر إلى دالّة تأخذ (char *) وتُعيد void
 */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */

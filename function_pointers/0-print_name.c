#include "function_pointers.h"

/**
 * print_name - يستدعي الدالّة f لطباعة الاسم
 * @name: اسم الشخص
 * @f: مؤشّر إلى دالّة مسؤولة عن الطباعة (تأخذ char * وتُعيد void)
 *
 * Return: لا شيء.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == 0 || f == 0)
		return;

	f(name);
}

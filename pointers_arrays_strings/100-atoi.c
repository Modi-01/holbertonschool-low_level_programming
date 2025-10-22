#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: pointer to the string
 *
 * Description:
 * - يتجاهل أي عدد من المحارف قبل الأرقام.
 * - يجمع كل إشارات '+' و '-' قبل أول رقم؛
 *   إذا كان عدد الـ '-' فردي تصبح الإشارة سالبة.
 * - يتوقف التحويل عند أول محرف غير رقمي بعد بدء القراءة.
 * - إن لم توجد أرقام يُرجَع 0.
 *
 * Return: the converted integer value
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int result = 0;

	/* اعبر كل ما قبل الأرقام واجمع الإشارات */
	while (s[i] != '\0' && !started)
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] == '+')
			; /* لا شيء */
		else if (s[i] >= '0' && s[i] <= '9')
			started = 1;
		else
			; /* محارف أخرى قبل الرقم تُتجاهل */

		if (!started)
			i++;
	}

	/* حوّل الأرقام المتتالية */
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}

	return (result * sign);
}

#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on format
 * @format: list of types
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i;
	int count;
	char c;
	int n;
	float f;
	char *s;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format && format[i])
	{
		if (count > 0 && (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's'))
			printf(", ");
		if (format[i] == 'c')
		{
			c = va_arg(args, int);
			printf("%c", c);
			count++;
		}
		if (format[i] == 'i')
		{
			n = va_arg(args, int);
			printf("%d", n);
			count++;
		}
		if (format[i] == 'f')
		{
			f = va_arg(args, double);
			printf("%f", f);
			count++;
		}
		if (format[i] == 's')
		{
			s = va_arg(args, char *);
			if (s == NULL)
				s = "(nil)";
			printf("%s", s);
			count++;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}

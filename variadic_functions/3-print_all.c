#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_one - prints one argument based on type
 * @type: the format character
 * @args: the va_list pointer
 * @sep: separator pointer
 */
static void print_one(char type, va_list *args, char **sep)
{
	char c;
	int n;
	float f;
	char *s;

	switch (type)
	{
	case 'c':
		c = va_arg(*args, int);
		printf("%s%c", *sep, c);
		*sep = ", ";
		break;
	case 'i':
		n = va_arg(*args, int);
		printf("%s%d", *sep, n);
		*sep = ", ";
		break;
	case 'f':
		f = va_arg(*args, double);
		printf("%s%f", *sep, f);
		*sep = ", ";
		break;
	case 's':
		s = va_arg(*args, char *);
		if (s == NULL)
			s = "(nil)";
		printf("%s%s", *sep, s);
		*sep = ", ";
		break;
	default:
		break;
	}
}

/**
 * print_all - prints anything based on format
 * @format: list of types (c=char, i=int, f=float, s=string)
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i;
	char *sep;

	va_start(args, format);
	i = 0;
	sep = "";
	while (format && format[i])
	{
		print_one(format[i], &args, &sep);
		i++;
	}
	va_end(args);
	printf("\n");
}

#include "main.h"

/**
 * print_rev - Prints a string in reverse followed by a new line
 * @s: Pointer to the string
 *
 * Return: void (nothing)
 */
void print_rev(char *s)
{
	int j = 0;

	while (s[j] != '\0')
	{
	j++;
	}

	for (j = j - 1; j >= 0; j--)
	{
	_putchar(s[j]);
	}

	_putchar('\n');
}

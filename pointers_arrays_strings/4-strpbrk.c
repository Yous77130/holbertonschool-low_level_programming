#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to scan
 * @accept: characters to match
 * Return: pointer to the byte in s that matches one in accept, or NULL
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		i = 0;

		while (accept[i])
		{
			if (*s == accept[i])
				return (s);
			i++;
		}

		s++;
	}

	return (NULL);
}

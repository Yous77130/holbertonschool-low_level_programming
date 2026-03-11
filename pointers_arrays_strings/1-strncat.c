#include "main.h"

/**
 * _strncat - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Maximum number of bytes to use from src.
 * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;
	int i = 0;

	while (dest[dest_len] != '\0')
	{
	dest_len++;
	}

	while (i < n && src[i] != '\0')
	{
	dest[dest_len + i] = src[i];
	i++;
	}

	dest[dest_len + i] = '\0';

	return (dest);
}

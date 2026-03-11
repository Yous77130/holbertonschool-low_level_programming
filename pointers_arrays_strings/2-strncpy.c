#include "main.h"
/**
 * *_strncpy - copies a string
 * @dest: the destination string where the content is copied
 * @src: the source string to copy from
 * @n: The maximum number of characters to copy from src.
 * Return: The maximum number of char
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
	dest[i] = src[i];
	}


	for (; i < n; i++)
	{
	dest[i] = '\0';
	}

	return (dest);
}

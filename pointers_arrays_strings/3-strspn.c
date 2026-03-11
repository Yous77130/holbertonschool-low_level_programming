#include "main.h"
/**
 * _strspn - Gets the length of a prefix substring
 * @s: The main string to be scanned
 * @accept: The string containing the characters to match
 * Return: The number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	int i = 0;
	int n = 0;
	int a = 0;

	while (s[i] != '\0')
	{
	for (a = 0; accept[a] != '\0'; a++)
	{
	if (s[i] == accept[a])
	{
	n++;
	break;
	}
	}
	if (accept[a] == '\0')
	{
	break;
	}
	i++;
	}
	return (n);
}

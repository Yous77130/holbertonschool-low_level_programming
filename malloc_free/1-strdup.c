#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if it fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	/* Calculer la longueur de la chaîne */
	for (len = 0; str[len] != '\0'; len++)
		;

	/* Allocation mémoire (+1 pour le caractère nul \0) */
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	/* Copie des caractères */
	for (i = 0; i <= len; i++)
	{
		dup[i] = str[i];
	}

	return (dup);
}
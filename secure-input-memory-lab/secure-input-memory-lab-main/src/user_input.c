#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_input.h"

/**
 * read_username - Lit un nom d'utilisateur depuis stdin
 * Return: Pointeur vers la chaîne allouée, ou NULL en cas d'erreur
 */
char *read_username(void)
{
	char buffer[32];
	char *username;
	size_t len;

	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		return (NULL);

	len = strlen(buffer);
	if (len > 0 && buffer[len - 1] == '\n')
	{
		buffer[len - 1] = '\0';
		len--;
	}

	username = malloc(sizeof(char) * (len + 1));
	if (username == NULL)
		return (NULL);

	strncpy(username, buffer, len + 1);
	username[len] = '\0';

	return (username);
}

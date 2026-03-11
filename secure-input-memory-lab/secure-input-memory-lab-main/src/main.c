#include <stdio.h>
#include <stdlib.h>
#include "user_input.h"
#include "session.h"

/**
 * main - Point d'entrée du programme
 * Return: 0 en cas de succès, 1 en cas d'erreur
 */
int main(void)
{
	char *username = NULL;
	session_t *session = NULL;

	printf("Enter username: ");
	username = read_username();
	if (username == NULL)
	{
		printf("Failed to read username\n");
		return (1);
	}

	session = session_create(username);
	if (session == NULL)
	{
		printf("Failed to create session\n");
		free(username);
		return (1);
	}

	session_print(session);
	/* On libère la session d'abord car elle utilise le nom */
	session_destroy(session);
	/* On libère le nom en dernier, en dehors de la session */
	free(username);

	return (0);
}

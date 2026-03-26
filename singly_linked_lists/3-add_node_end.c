#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list
 * @head: pointer to the head of the list
 * @str: string to add
 * Return: address of new element, or NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *tmp;
	unsigned int i;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	for (i = 0; str[i]; i++)
		;
	new->len = i;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

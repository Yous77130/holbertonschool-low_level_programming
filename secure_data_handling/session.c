#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - creates a new session
 * @id: session identifier
 * @uid: user id
 * @data: session data
 * @data_len: length of data
 * Return: pointer to new session, or NULL if failed
 */
session_t *session_create(const char *id, unsigned int uid,
		const unsigned char *data, size_t data_len)
{
	session_t *s;

	s = (session_t *)malloc(sizeof(*s));
	if (!s)
		return (NULL);

	s->id = strdup(id);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	s->uid = uid;

	if (data_len > 0)
	{
		s->data = (unsigned char *)malloc(data_len);
		if (!s->data)
		{
			free(s->id);
			free(s);
			return (NULL);
		}
		memcpy(s->data, data, data_len);
		s->data_len = data_len;
	}
	else
	{
		s->data = NULL;
		s->data_len = 0;
	}

	return (s);
}

/**
 * session_set_data - updates the data buffer of a session
 * @s: the session
 * @data: new data
 * @data_len: length of new data
 * Return: 1 if succeeded, 0 otherwise
 */
int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *tmp;

	if (!s)
		return (0);

	if (data_len == 0)
	{
		free(s->data);
		s->data = NULL;
		s->data_len = 0;
		return (1);
	}

	tmp = (unsigned char *)realloc(s->data, data_len);
	if (!tmp)
		return (0);

	s->data = tmp;
	memcpy(s->data, data, data_len);
	s->data_len = data_len;
	return (1);
}

/**
 * session_destroy - destroys a session and frees all memory
 * @s: the session to destroy
 */
void session_destroy(session_t *s)
{
	if (!s)
		return;

	free(s->id);
	free(s->data);
	free(s);
}

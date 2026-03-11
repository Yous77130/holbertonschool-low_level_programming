#include <unistd.h>
#include "main.h"

/**
 * main - Point d'entrée
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	char *sh = "_putchar";
	int i;

	for (i = 0; i < 8; i++)
	{
		_putchar(sh[i]);
	}
	_putchar('\n');

	return (0);
}

#include <stdio.h>

/**
 * main - Point d'entrée
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		putchar(letter);
	}
	putchar('\n');

	return (0);
}

#include <stdio.h>

/**
 * main - Point d'entrée
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	char letter;

	for (letter = 'z'; letter >= 'a'; letter--)
	{
		putchar(letter);
	}
	putchar('\n');

	return (0);
}

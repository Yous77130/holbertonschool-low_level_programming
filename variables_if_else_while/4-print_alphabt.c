#include <stdio.h>

/**
 * main - Point d'entrée
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	char la;

	for (la = 'a'; la <= 'z'; la++)
	{
		if (la != 'e' && la != 'q')
		{
			putchar(la);
		}
	}
	putchar('\n');

	return (0);
}

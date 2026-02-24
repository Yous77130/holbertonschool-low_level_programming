#include <stdio.h>

/**
 * main - Point d entrée
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	int n;
	char l;

	for (n = 0; n < 10; n++)
	{
		putchar(n + '0');
	}
	for (l = 'a'; l <= 'f'; l++)
	{
		putchar(l);
	}
	putchar('\n');

	return (0);
}

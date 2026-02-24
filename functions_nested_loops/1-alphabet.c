#include "main.h"

/**
 * print_alphabet - Affiche l'alphabet en minuscules
 *
 * Description: Utilise une boucle pour parcourir les caractères de a à z
 * et utilise _putchar seulement deux fois (une pour la lettre, une pour le \n).
 * Return: void
 */
void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}
	_putchar('\n');
}

#include <stdio.h>

/**
 * main - Point d'entrée du programme de calculatrice
 * Return: Toujours 0
 */
int main(void)
{
	int choice = -1;

	printf("Simple Calculator\n");

	while (choice != 0)
	{
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		/* Lecture de l'entier saisi par l'utilisateur */
		if (scanf("%d", &choice) != 1)
		{
			/* Si l'utilisateur entre autre chose qu'un chiffre */
			break;
		}

		if (choice == 0)
		{
			printf("Bye!\n");
		}
		/* Pour l'instant, on ne fait rien pour les choix 1 à 4 */
	}

	return (0);
}

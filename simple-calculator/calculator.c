#include <stdio.h>

/**
 * main - Entry point for the calculator
 * Return: Always 0
 */
int main(void)
{
	int choice = -1;

	printf("Simple Calculator\n");

	while (choice != 0)
	{
		printf("\n1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		/* Lecture du choix */
		if (scanf("%d", &choice) != 1)
		{
			/* Sortie de secours si l'utilisateur entre du texte */
			break;
		}

		/* Validation du choix */
		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if (choice >= 1 && choice <= 4)
		{
			/* Pour l'instant on ne fait rien, la Task 2 arrive */
		}
		else
		{
			/* Si le nombre n'est ni 0, ni entre 1 et 4 */
			printf("Invalid choice\n");
		}
	}

	return (0);
}

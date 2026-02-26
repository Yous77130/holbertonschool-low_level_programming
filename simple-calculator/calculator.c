#include <stdio.h>

/**
 * main - Entry point for the calculator
 * Return: Always 0
 */
int main(void)
{
	int choice = -1;
	int a, b, result;

	printf("Simple Calculator\n");

	while (choice != 0)
	{
		printf("\n1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
			break;

		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if (choice == 1 || choice == 2)
		{
			/* On demande A et B pour l'addition ET la soustraction */
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);

			if (choice == 1)
				result = a + b;
			else
				result = a - b;

			printf("Result: %d\n", result);
		}
		else if (choice >= 3 && choice <= 4)
		{
			printf("Operation to be implemented\n");
		}
		else
		{
			printf("Invalid choice\n");
		}
	}
	return (0);
}

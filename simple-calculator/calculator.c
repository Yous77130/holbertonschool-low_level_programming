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
		else if (choice == 1)
		{
			/* Task 2: Addition */
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);

			result = a + b;
			printf("Result: %d\n", result);
		}
		else if (choice >= 2 && choice <= 4)
		{
			/* À implémenter dans les prochaines tâches */
			printf("Operation to be implemented\n");
		}
		else
		{
			printf("Invalid choice\n");
		}
	}
	return (0);
}

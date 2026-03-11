#include <stdio.h>

/**
 * print_table - Prints a multiplication table of a given size
 * @size: The size of the table
 *
 * Return: void
 */
void print_table(int size)
{
	int row, col;

	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= size; col++)
		{
			/* On affiche le nombre suivi d'un espace, sans condition */
			printf("%d ", row * col);
		}
		printf("\n");
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	print_table(4);
	return (0);
}

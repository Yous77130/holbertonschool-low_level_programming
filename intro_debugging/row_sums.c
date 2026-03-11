#include <stdio.h>

/**
 * row_sum - Computes the sum of a specific row
 * @row: The row number
 * @cols: Number of columns
 *
 * Return: Sum of the row
 */
int row_sum(int row, int cols)
{
	int c;
	int sum = 0;

	for (c = 1; c <= cols; c++)
		sum += row * c;

	return (sum);
}

/**
 * total_sum - Computes the total sum of all rows
 * @rows: Number of rows
 * @cols: Number of columns
 *
 * Return: Total sum
 */
int total_sum(int rows, int cols)
{
	int r;
	int total = 0;

	for (r = 1; r <= rows; r++)
	{
		/* On ajoute directement le résultat de la ligne au total */
		total += row_sum(r, cols);
	}

	return (total);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	printf("%d\n", total_sum(3, 3));
	return (0);
}

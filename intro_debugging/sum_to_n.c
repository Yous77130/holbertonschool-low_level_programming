#include <stdio.h>

/**
 * sum_to_n - Computes the sum of all integers from 1 to n
 * @n: The number to sum up to
 *
 * Return: The total sum
 */
int sum_to_n(int n)
{
	int i;
	int sum = 0;

	/* On utilise <= pour inclure n, et on s'arrête quand i dépasse n */
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}

	return (sum);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	printf("%d\n", sum_to_n(10));
	return (0);
}

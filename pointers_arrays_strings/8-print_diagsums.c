#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix
 * @a: Pointer to the first element of the matrix
 * @size: The size of the matrix (size x size)
*/
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	for (i = 0; i < size ; i++)
	{
	sum1 += a[i * size + i];
	sum2 += a[i * size + (size - i - 1)];
	}
	printf("%d, %d\n", sum1, sum2);
}

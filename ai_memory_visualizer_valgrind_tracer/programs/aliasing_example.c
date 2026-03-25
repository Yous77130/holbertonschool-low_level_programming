#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
	int *a;
	int *b;

	a = malloc(sizeof(int));
	if (a == NULL)
		return (1);
	*a = 10;
	b = a;
	*b = 20;
	printf("a = %d\n", *a);
	printf("b = %d\n", *b);
	free(a);
	return (0);
}

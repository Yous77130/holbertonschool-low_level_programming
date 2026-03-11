#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	int *a;

	a = array_range(0, 10);
	if (a == NULL)
		return (1);
	printf("%d\n", a[0]); /* Affiche 0 */
	free(a);
	return (0);
}
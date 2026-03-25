#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
	int *ptr;

	ptr = malloc(sizeof(int));
	if (ptr == NULL)
		return (1);
	*ptr = 42;
	printf("Value: %d\n", *ptr);
	free(ptr);
	return (0);
}

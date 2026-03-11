#include <stdio.h>
#include <stdlib.h>

/**
 * main - multplies two numbers
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int a, b;

	if (argc != 3)
	{
	printf("Error\n");
	return (1);
	}
	else
	{
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d\n", a * b);
	return (0);
	}
}
#include <stdio.h>

/**
 * add - adds two integers
 * @a: first integer
 * @b: second integer
 * Return: sum of a and b
 */
int add(int a, int b)
{
	int result;

	result = a + b;
	return (result);
}

/**
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
	int x;
	int y;
	int sum;

	x = 5;
	y = 3;
	sum = add(x, y);
	printf("Sum: %d\n", sum);
	return (0);
}

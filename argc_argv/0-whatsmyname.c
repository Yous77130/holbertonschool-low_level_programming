cat > 0-whatsmyname.c << 'EOF'
#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	printf("%s\n", argv[argc - argc]);
	return (0);
}
EOF


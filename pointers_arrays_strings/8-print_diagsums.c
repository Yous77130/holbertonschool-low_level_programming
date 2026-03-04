#include "main.h"
#include <stdio.h>
void print_diagsums(int *a, int size)
{
    int i;
    int diag1;
    int diag2;

    i = 0;
    diag1 = 0;
    diag2 = 0;
    while (i < size)
    {
        diag1 += a[i * size + i];
        diag2 += a[i * size + (size - 1 - i)];
        i++;
    }
    printf("%d, %d\n", diag1, diag2);
}

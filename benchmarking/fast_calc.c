#include <stdio.h>
#include <time.h>

int main(void)
{
    unsigned long n = 1000000000UL;
    unsigned long long sum = 0;
    clock_t start, end;

    start = clock();
    /* Formule de Gauss : n * (n - 1) / 2 */
    sum = (unsigned long long)n * (n - 1) / 2;
    end = clock();

    printf("Sum: %llu\n", sum);
    printf("Fast time: %.6f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

#include <stdio.h>
#include <time.h>

int main(void)
{
    unsigned long i;
    unsigned long long sum = 0;
    clock_t start, end;

    start = clock();
    for (i = 0; i < 1000000000UL; i++) {
        sum += i;
    }
    end = clock();

    printf("Sum: %llu\n", sum);
    printf("Slow time: %.6f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

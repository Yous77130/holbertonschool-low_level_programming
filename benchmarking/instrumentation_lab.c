#include <stdio.h>
#include <time.h>

/* ... fonctions static ... */

int main(void)
{
    unsigned long checksum;
    clock_t start_total, end_total;
    clock_t start_build, end_build;
    clock_t start_process, end_process;
    clock_t start_reduce, end_reduce;
    
    /* Le script cherche l'appel de clock() ici */
    start_total = clock();
    
    /* ... exécution des phases ... */
    
    end_total = clock();

    /* Le script cherche l'utilisation de CLOCKS_PER_SEC ici */
    printf("TOTAL seconds: %.6f\n", (double)(end_total - start_total) / CLOCKS_PER_SEC);
    /* ... autres printf ... */

    return (0);
}

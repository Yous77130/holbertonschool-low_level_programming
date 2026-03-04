#include "main.h"
char *leet(char *s)
{
    int i;
    int j;
    char plain[] = "aAeEoOtTlL";
    char leetc[] = "4433007711";

    i = 0;
    while (s[i] != '\0')
    {
        j = 0;
        while (plain[j] != '\0')
        {
            if (s[i] == plain[j])
                s[i] = leetc[j];
            j++;
        }
        i++;
    }
    return (s);
}

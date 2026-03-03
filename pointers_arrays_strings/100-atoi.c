#include "main.h"
int _atoi(char *s)
{
    int sign;
    int nb;
    int minus;
    int i;

    sign = 1;
    nb = 0;
    minus = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '-')
            minus++;
        else if (s[i] == '+')
            ;
        else if (s[i] >= '0' && s[i] <= '9')
        {
            if (minus % 2 != 0)
                sign = -1;
            while (s[i] >= '0' && s[i] <= '9')
            {
                nb = nb * 10 + (s[i] - '0');
                i++;
            }
            return (sign * nb);
        }
        else
        {
            minus = 0;
            sign = 1;
        }
        i++;
    }
    return (0);
}

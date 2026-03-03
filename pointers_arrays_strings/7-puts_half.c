#include "main.h"
void puts_half(char *str)
{
    int len;
    int start;
    len = 0;
    while (str[len] != '\0')
        len++;
    start = (len + 1) / 2;
    while (str[start] != '\0')
    {
        _putchar(str[start]);
        start++;
    }
    _putchar('\n');
}

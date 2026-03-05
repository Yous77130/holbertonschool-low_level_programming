#include "main.h"

/**
* puts_half - Prints the second half of a string
* @str: The input string
*
* Description: If the number of characters is odd, the function prints
* the last n characters, where n = (length_of_the_string + 1) / 2.
*/
void puts_half(char *str)
{
int length = 0, i, start;

while (str[length] != '\0')
{
length++;
}

if (length % 2 == 0)
start = length / 2;
else
start = (length + 1) / 2;

for (i = start; i < length; i++)
{
_putchar(str[i]);
}
_putchar('\n');
}

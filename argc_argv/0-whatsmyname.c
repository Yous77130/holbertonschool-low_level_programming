#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *name = strrchr(argv[0], '/');
    if (name)
        name++;  // sauter le '/'
    else
        name = argv[0];
    printf("%s\n", name);
    return 0;
}


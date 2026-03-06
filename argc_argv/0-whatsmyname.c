#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    (void)argc;  // évite le warning de variable non utilisée

    // Obtenir seulement le nom du fichier, pas le chemin
    char *name = strrchr(argv[0], '/');
    if (name)
        name++;  // passer le '/'
    else
        name = argv[0];

    printf("%s\n", name);
    return 0;
}


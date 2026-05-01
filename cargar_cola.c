#include "catalogo.h"

enum boolean cargar_cola(struct Cola *c, const char *archivo) {
    FILE *f = fopen(archivo, "r");
    
    if (f == NULL) {
        return False;
    }

    int idR, idL, idU, punt;
    char texto[500];

    // Leemos separando por Pipes
    while (fscanf(f, "%d|%d|%d|%499[^|]|%d\n", &idR, &idL, &idU, texto, &punt) == 5) {
        enqueue(c, idR, idL, idU, texto, punt);
    }

    fclose(f);
    return True;
}
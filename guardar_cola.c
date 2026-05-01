#include "catalogo.h"

enum boolean guardar_cola(struct Cola *c, const char *archivo) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        return False;
    }

    struct Peticion *actual = c->head;

    while (actual != NULL) {
        // Guardamos todos los datos 
        fprintf(f, "%d|%d|%d|%s|%d\n", 
                actual->idResena, actual->idLibro, actual->idUsuario, 
                actual->texto, actual->puntuacion);
        
        actual = actual->nxt;
    }

    fclose(f);
    return True;
}
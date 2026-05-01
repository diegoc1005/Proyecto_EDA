#include "catalogo.h"

enum boolean guardar_catalog(struct Libro *head, const char *archivo) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error: No se pudo abrir el archivo para guardar el catalogo.\n");
        return False;
    }

    struct Libro *actual = head;

    // Recorremos la Lista Doble hasta el final
    while (actual != NULL) {
        // Escribimos los datos de regreso al .txt usando los |
        fprintf(f, "%d|%s|%s|%s|%.2f|%d\n", 
                actual->id, actual->titulo, actual->autor, actual->genero, 
                actual->calificacion, actual->numResenas);
        actual = actual->nxt;
    }

    fclose(f);
    return True;
}
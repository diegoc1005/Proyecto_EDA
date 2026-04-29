#include "catalogo.h"

enum boolean guardar_usuarios(struct Usuario *head_usuarios, const char *archivo) {
    // Abrimos el archivo en "w" para poder escribir
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error: No se pudo abrir el archivo para guardar usuarios.\n");
        return False;
    }

    // Apuntador auxiliar para no perder la cabeza
    struct Usuario *actual = head_usuarios;

    // Recorremos la lista hasta el final
    while (actual != NULL) {
        // fprintf imprime directo en el .txt en lugar de la consola
        fprintf(f, "%d|%s|%s|%s\n", actual->id, actual->nombre, actual->password, actual->rol);
        actual = actual->nxt;
    }

    fclose(f);
    return True;
}
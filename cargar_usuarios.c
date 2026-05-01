#include "catalogo.h"

enum boolean cargar_usuarios(struct Usuario **head_usuarios, int *numUsuarios, const char *archivo) {
    FILE *f = fopen(archivo, "r");
    
    // Si el archivo no existiera, simplemente retornamos False.
    if (f == NULL) {
        printf("Error fatal: Falta el archivo %s para iniciar el sistema.\n", archivo);
        return False; 
    }

    int id;
    char nombre[50], password[50], rol[10];

    // Leemos línea por línea separados por |
    while (fscanf(f, "%d|%49[^|]|%49[^|]|%9[^\n]\n", &id, nombre, password, rol) == 4) {
        struct Usuario *tmp = (struct Usuario*)malloc(sizeof(struct Usuario));
        if (tmp != NULL) {
            tmp->id = id;
            strcpy(tmp->nombre, nombre);
            strcpy(tmp->password, password);
            strcpy(tmp->rol, rol);
            tmp->top_notificaciones = NULL;

            // Se inserta por la cabeza
            tmp->nxt = *head_usuarios;
            *head_usuarios = tmp;
            
            (*numUsuarios)++;
        }
    }

    fclose(f);
    return True;
}
#include "catalogo.h"

struct Usuario* login_usuario(struct Usuario *head_usuarios, char *nombre, char *pass) {
    struct Usuario *actual = head_usuarios;

    // Recorrido lineal de la lista ligada
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0 && strcmp(actual->password, pass) == 0) {
            return actual; 
        }
        actual = actual->nxt;
    }
    return NULL; 
}
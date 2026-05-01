#include "catalogo.h"

enum boolean pop_notificacion(struct Notificacion **top, char *destino) {
    if (*top == NULL) return False;

    struct Notificacion *tmp = *top;
    
    // Rescatamos el mensaje
    strcpy(destino, tmp->mensaje);
    
    // El tope baja
    *top = tmp->nxt;
    
    // Aislamos el nodo antes de matarlo
    tmp->nxt = NULL;
    free(tmp);

    return True;
}
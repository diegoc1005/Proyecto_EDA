#include "catalogo.h"

enum boolean push_notificacion(struct Notificacion **top, char *mensaje) {

    struct Notificacion *tmp = (struct Notificacion*)malloc(sizeof(struct Notificacion));
    if (tmp == NULL) return False;

    strcpy(tmp->mensaje, mensaje);
    
    // Inserción
    tmp->nxt = *top;
    *top = tmp;

    return True;
}
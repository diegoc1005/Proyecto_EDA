#include "catalogo.h"

enum boolean dequeue(struct Cola *c, struct Peticion *destino) {
    if (c->head == NULL) return False;

    struct Peticion *tmp = c->head;

    // Rescatamos los nuevos datos
    destino->idResena = tmp->idResena;
    destino->idLibro = tmp->idLibro;
    destino->idUsuario = tmp->idUsuario;
    strcpy(destino->texto, tmp->texto);
    destino->puntuacion = tmp->puntuacion;

    c->head = tmp->nxt; 
    if (c->head == NULL) c->tail = NULL; 

    tmp->nxt = NULL; 
    free(tmp); 
    return True;
}
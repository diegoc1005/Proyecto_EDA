#include "catalogo.h"

// Recibe los datos de la reseña
enum boolean enqueue(struct Cola *c, int idR, int idL, int idU, const char *texto, int punt) {
    struct Peticion *tmp = (struct Peticion*)malloc(sizeof(struct Peticion));
    if (tmp == NULL) return False;

    // Llenamos los nuevos datos
    tmp->idResena = idR;
    tmp->idLibro = idL;
    tmp->idUsuario = idU;
    strcpy(tmp->texto, texto);
    tmp->puntuacion = punt;
    
    tmp->nxt = NULL; 

    // Añadimos por el final 
    if (c->head == NULL) {
        c->head = tmp;
        c->tail = tmp;
    } else {
        c->tail->nxt = tmp; 
        c->tail = tmp;      
    }
    return True;
}
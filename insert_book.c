#include "catalogo.h"

enum boolean insert_book(struct Libro **head, struct Libro *nuevo_libro) {
    if (nuevo_libro == NULL) return False;

    // Caso 1: La lista está vacía
    if (*head == NULL) {
        nuevo_libro->prev = NULL;
        nuevo_libro->nxt = NULL;
        *head = nuevo_libro;
        return True;
    }

    // Caso 2: Inserción al principio (el nuevo va antes del head actual)
    // strcmp compara cadenas, si da menor a 0, significa que va antes alfabéticamente, si da mayo la primera palabra va despues, si da 0 son identicas.
    if (strcmp(nuevo_libro->titulo, (*head)->titulo) < 0) {
        nuevo_libro->nxt = *head;
        nuevo_libro->prev = NULL;
        (*head)->prev = nuevo_libro;
        *head = nuevo_libro;
        return True;
    }

    // Caso 3: Inserción en medio o al final
    struct Libro *actual = *head;
    
    // Recorremos hasta encontrar el hueco correcto o llegar al final
    while (actual->nxt != NULL && strcmp(nuevo_libro->titulo, actual->nxt->titulo) > 0) {
        actual = actual->nxt;
    }

    // Insertamos el nuevo nodo después del nodo "actual"
    nuevo_libro->nxt = actual->nxt;
    nuevo_libro->prev = actual;

    if (actual->nxt != NULL) {
        actual->nxt->prev = nuevo_libro; // Conectamos el de adelante de regreso al nuevo
    }
    actual->nxt = nuevo_libro; // Conectamos el actual hacia adelante al nuevo

    return True;
}
#include "catalogo.h"

enum boolean delete_book(struct Libro **head, char *titulo_buscar) {
    // Si la lista está vacía, no hay nada que eliminar
    if (*head == NULL) {
        return False;
    }

    struct Libro *actual = *head;

    // Buscamos el libro por título
    while (actual != NULL) {
        if (strcmp(actual->titulo, titulo_buscar) == 0) {
            // Encontramos el libro, ahora lo eliminamos ajustando los apuntadores

            // Caso 1: Es el primer nodo (head)
            if (actual->prev == NULL) {
                *head = actual->nxt;
                if (*head != NULL) {
                    (*head)->prev = NULL;
                }
            }
            // Caso 2: Es un nodo intermedio o el último
            else {
                actual->prev->nxt = actual->nxt;
                if (actual->nxt != NULL) {
                    actual->nxt->prev = actual->prev;
                }
            }

            // Liberamos la memoria del nodo eliminado
            free(actual);
            return True;
        }
        actual = actual->nxt;
    }

    // No se encontró el libro
    return False;
}
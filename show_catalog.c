#include "catalogo.h"

void show_catalog(struct Libro *head) {
    // Si la lista está vacía, no hay nada que imprimir
    if (head == NULL) {
        printf("\n[!] El catalogo esta vacio. No hay libros para mostrar.\n\n");
        return;
    }

    // Usamos un apuntador auxiliar para no perder la cabeza de la lista
    struct Libro *actual = head;

    // Imprimimos el encabezado de la tabla
    printf("\n========================================================================================\n");
    // %-35s asegura que las columnas queden perfectamente alineadas sin importar el tamaño del texto.
    printf("%-35s | %-25s | %-15s | %-5s\n", "TITULO", "AUTOR", "GENERO", "CALIF");
    printf("========================================================================================\n");

    // Recorremos la lista nodo por nodo hasta llegar a NULL osea el final
    while (actual != NULL) {
        printf("%-35s | %-25s | %-15s | %.1f\n", 
               actual->titulo, actual->autor, actual->genero, actual->calificacion);
        
        // Saltamos al siguiente nodo
        actual = actual->nxt;
    }
    printf("========================================================================================\n\n");
}
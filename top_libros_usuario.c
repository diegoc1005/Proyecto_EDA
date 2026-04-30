#include "catalogo.h"

void top_libros_usuario(struct Libro *libros) {
    printf("\n--- TOP 10 LIBROS MEJOR CALIFICADOS ---\n");
    
    if (libros == NULL) {
        printf("[!] El catalogo esta vacio.\n");
        return;
    }
    
    // Contamos cuántos libros hay
    int total = 0;
    struct Libro *temp = libros;
    while (temp != NULL) {
        total++;
        temp = temp->nxt;
    }
    
    // Creamos un arreglo de apuntadores para ordenar
    struct Libro **array = (struct Libro**)malloc(total * sizeof(struct Libro*));
    if (array == NULL) {
        printf("[!] Error de memoria.\n");
        return;
    }
    
    // Llenamos el arreglo
    temp = libros;
    for (int i = 0; i < total; i++) {
        array[i] = temp;
        temp = temp->nxt;
    }
    
    // Ordenamos por calificación (bubble sort simple)
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (array[j]->calificacion < array[j+1]->calificacion) {
                struct Libro *swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
    
    // Mostramos el top 10 (o menos si hay menos libros)
    int mostrar = (total < 10) ? total : 10;
    
    printf("\n==============================================================================================\n");
    printf("%-4s | %-35s | %-25s | %-15s | %-5s\n", "POS", "TITULO", "AUTOR", "GENERO", "CALIF");
    printf("==============================================================================================\n");
    
    for (int i = 0; i < mostrar; i++) {
        printf("%-4d | %-35s | %-25s | %-15s | %.2f ⭐\n", 
               i+1, array[i]->titulo, array[i]->autor, array[i]->genero, array[i]->calificacion);
    }
    
    printf("==============================================================================================\n\n");
    
    free(array);
}

// Made with Bob

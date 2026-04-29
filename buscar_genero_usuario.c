#include "catalogo.h"

void buscar_genero_usuario(struct Libro *libros) {
    printf("\n--- BUSCAR POR GENERO ---\n");
    
    if (libros == NULL) {
        printf("[!] El catalogo esta vacio.\n");
        return;
    }
    
    // Limpiamos el buffer
    while(getchar() != '\n');
    
    char genero_buscar[MAX_STR];
    printf("Ingresa el genero a buscar: ");
    fgets(genero_buscar, MAX_STR, stdin);
    genero_buscar[strcspn(genero_buscar, "\n")] = 0;
    
    // Buscamos y mostramos libros del género
    struct Libro *actual = libros;
    int encontrados = 0;
    
    printf("\n========================================================================================\n");
    printf("%-35s | %-25s | %-15s | %-5s\n", "TITULO", "AUTOR", "GENERO", "CALIF");
    printf("========================================================================================\n");
    
    while (actual != NULL) {
        // Comparación case-insensitive básica
        if (strstr(actual->genero, genero_buscar) != NULL || 
            strcmp(actual->genero, genero_buscar) == 0) {
            printf("%-35s | %-25s | %-15s | %.1f\n", 
                   actual->titulo, actual->autor, actual->genero, actual->calificacion);
            encontrados++;
        }
        actual = actual->nxt;
    }
    
    printf("========================================================================================\n");
    
    if (encontrados == 0) {
        printf("No se encontraron libros del genero '%s'.\n", genero_buscar);
    } else {
        printf("Total: %d libro(s) encontrado(s).\n", encontrados);
    }
    printf("\n");
}

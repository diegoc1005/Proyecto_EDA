#include "catalogo.h"

void buscar_genero_usuario(struct Libro *libros) {
    printf("\n--- BUSCAR POR GENERO ---\n");
    
    if (libros == NULL) {
        printf("[!] El catalogo esta vacio.\n");
        return;
    }
    
    // Primero mostramos los géneros disponibles
    printf("\n=== GENEROS DISPONIBLES ===\n");
    char generos_unicos[50][MAX_STR];
    int num_generos = 0;
    
    struct Libro *temp = libros;
    while (temp != NULL) {
        int ya_existe = 0;
        for (int i = 0; i < num_generos; i++) {
            if (strcmp(generos_unicos[i], temp->genero) == 0) {
                ya_existe = 1;
                break;
            }
        }
        if (!ya_existe && num_generos < 50) {
            strcpy(generos_unicos[num_generos], temp->genero);
            num_generos++;
        }
        temp = temp->nxt;
    }
    
    for (int i = 0; i < num_generos; i++) {
        printf("  - %s\n", generos_unicos[i]);
    }
    printf("===========================\n\n");
    
    while(getchar() != '\n');
    
    char genero_buscar[MAX_STR];
    printf("Ingresa el genero a buscar: ");
    fgets(genero_buscar, MAX_STR, stdin);
    genero_buscar[strcspn(genero_buscar, "\n")] = 0;
    
    // Buscamos y mostramos libros del género
    struct Libro *actual = libros;
    int encontrados = 0;
    
    printf("\n==============================================================================================\n");
    printf("%-4s | %-35s | %-25s | %-15s | %-5s\n", "ID", "TITULO", "AUTOR", "GENERO", "CALIF");
    printf("==============================================================================================\n");
    
    while (actual != NULL) {
        // Comparación case-insensitive básica
        if (strstr(actual->genero, genero_buscar) != NULL ||
            strcmp(actual->genero, genero_buscar) == 0) {
            printf("%-4d | %-35s | %-25s | %-15s | %.1f\n",
                   actual->id, actual->titulo, actual->autor, actual->genero, actual->calificacion);
            encontrados++;
        }
        actual = actual->nxt;
    }
    
    printf("==============================================================================================\n");
    
    if (encontrados == 0) {
        printf("No se encontraron libros del genero '%s'.\n", genero_buscar);
    } else {
        printf("Total: %d libro(s) encontrado(s).\n", encontrados);
    }
    printf("\n");
}

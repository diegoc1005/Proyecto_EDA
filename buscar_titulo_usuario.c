#include "catalogo.h"

void buscar_titulo_usuario(struct Libro *libros) {
    printf("\n--- BUSCAR POR TITULO ---\n");
    
    if (libros == NULL) {
        printf("[!] El catalogo esta vacio.\n");
        return;
    }
    
    while(getchar() != '\n');
    
    char titulo_buscar[MAX_STR];
    printf("Ingresa parte del titulo a buscar: ");
    fgets(titulo_buscar, MAX_STR, stdin);
    titulo_buscar[strcspn(titulo_buscar, "\n")] = 0;
    
    struct Libro *actual = libros;
    int encontrados = 0;
    
    printf("\n==============================================================================================\n");
    printf("%-4s | %-35s | %-25s | %-15s | %-5s\n", "ID", "TITULO", "AUTOR", "GENERO", "CALIF");
    printf("==============================================================================================\n");
    
    while (actual != NULL) {
        // Búsqueda parcial (case-sensitive)
        if (strstr(actual->titulo, titulo_buscar) != NULL) {
            printf("%-4d | %-35s | %-25s | %-15s | %.1f\n",
                   actual->id, actual->titulo, actual->autor, actual->genero, actual->calificacion);
            encontrados++;
        }
        actual = actual->nxt;
    }
    
    printf("==============================================================================================\n");
    
    if (encontrados == 0) {
        printf("No se encontraron libros con '%s' en el titulo.\n", titulo_buscar);
    } else {
        printf("Total: %d libro(s) encontrado(s).\n", encontrados);
    }
    printf("\n");
}

// Made with Bob

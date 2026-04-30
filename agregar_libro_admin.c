#include "catalogo.h"

void agregar_libro_admin(struct Libro **libros) {
    printf("\n--- AGREGAR NUEVO LIBRO ---\n");
    struct Libro *nuevo = (struct Libro*)malloc(sizeof(struct Libro));
    if (nuevo == NULL) {
        printf("[!] Error: No se pudo asignar memoria.\n");
        return;
    }
    
    // Generamos un ID único (el último ID + 1)
    int maxId = 0;
    struct Libro *temp = *libros;
    while (temp != NULL) {
        if (temp->id > maxId) maxId = temp->id;
        temp = temp->nxt;
    }
    nuevo->id = maxId + 1;
    
    // Limpiamos el buffer
    while(getchar() != '\n');
    
    printf("Titulo: ");
    fgets(nuevo->titulo, MAX_STR, stdin);
    nuevo->titulo[strcspn(nuevo->titulo, "\n")] = 0;
    
    printf("Autor: ");
    fgets(nuevo->autor, MAX_STR, stdin);
    nuevo->autor[strcspn(nuevo->autor, "\n")] = 0;
    
    printf("Genero: ");
    fgets(nuevo->genero, MAX_STR, stdin);
    nuevo->genero[strcspn(nuevo->genero, "\n")] = 0;
    
    // Inicializamos con valores por defecto
    nuevo->calificacion = 0.0;
    nuevo->numResenas = 0;
    nuevo->prev = NULL;
    nuevo->nxt = NULL;
    
    if (insert_book(libros, nuevo) == True) {
        printf("\n[OK] Libro agregado exitosamente con ID %d.\n", nuevo->id);
        
        // Guardamos el catálogo inmediatamente
        if (guardar_catalog(*libros, "libros.txt") == True) {
            printf("[OK] Catalogo guardado.\n");
        }
    } else {
        printf("\n[!] Error al agregar el libro.\n");
        free(nuevo);
    }
}

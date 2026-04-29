#include "catalogo.h"

enum boolean load_catalog(struct Libro **head) {
    FILE *f = fopen("libros.txt", "r"); 
    if (f == NULL) {
        printf("Error: No se pudo abrir la base de datos.\n");
        return False; 
    }

    int id, numResenas;
    char titulo[MAX_STR], autor[MAX_STR], genero[MAX_STR];
    float calificacion;

    // Leemos el .txt separado por |
    while (fscanf(f, "%d|%99[^|]|%99[^|]|%99[^|]|%f|%d\n", &id, titulo, autor, genero, &calificacion, &numResenas) == 6) {
        
        struct Libro *nuevo = (struct Libro *)malloc(sizeof(struct Libro));
        if (nuevo != NULL) {
            nuevo->id = id;
            strcpy(nuevo->titulo, titulo);
            strcpy(nuevo->autor, autor);
            strcpy(nuevo->genero, genero);
            nuevo->calificacion = calificacion;
            nuevo->numResenas = numResenas;
            nuevo->prev = NULL;
            nuevo->nxt = NULL;

            // Lo mandamos a insertar ordenadamente a la lista
            insert_book(head, nuevo);
        }
    }
    
    fclose(f);
    return True; 
}
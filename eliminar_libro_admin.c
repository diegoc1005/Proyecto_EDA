#include "catalogo.h"

void eliminar_libro_admin(struct Libro **libros) {
    printf("\n--- ELIMINAR LIBRO ---\n");
    
    if (*libros == NULL) {
        printf("[!] El catalogo esta vacio.\n");
        return;
    }
    
    // Limpiamos el buffer
    while(getchar() != '\n');
    
    char titulo_buscar[MAX_STR];
    printf("Ingresa el titulo exacto del libro a eliminar: ");
    fgets(titulo_buscar, MAX_STR, stdin);
    titulo_buscar[strcspn(titulo_buscar, "\n")] = 0;
    
    if (delete_book(libros, titulo_buscar) == True) {
        printf("\n[OK] Libro eliminado exitosamente.\n");
        
        // Guardamos el catálogo inmediatamente
        if (guardar_catalog(*libros, "libros.txt") == True) {
            printf("[OK] Catalogo guardado.\n");
        }
    } else {
        printf("\n[!] No se encontro un libro con ese titulo.\n");
    }
}

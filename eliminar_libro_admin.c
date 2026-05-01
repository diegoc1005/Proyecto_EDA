#include "catalogo.h"

void eliminar_libro_admin(struct Libro **libros) {
    printf("\n--- ELIMINAR LIBRO ---\n");
    
    if (*libros == NULL) {
        printf("[!] El catalogo esta vacio.\n");
        return;
    }
    
    // Mostramos el catálogo para que vea los IDs
    show_catalog(*libros);
    
    int id_eliminar;
    printf("\nIngresa el ID del libro a eliminar: ");
    if(scanf("%d", &id_eliminar) != 1) {
        printf("\n[!] Error: ID invalido.\n");
        while(getchar() != '\n');
        return;
    }
    
    // Buscamos y eliminamos el libro por ID
    struct Libro *actual = *libros;
    struct Libro *libro_eliminar = NULL;
    
    while (actual != NULL) {
        if (actual->id == id_eliminar) {
            libro_eliminar = actual;
            break;
        }
        actual = actual->nxt;
    }
    
    if (libro_eliminar == NULL) {
        printf("\n[!] No se encontro un libro con ese ID.\n");
        return;
    }
    
    // Confirmamos antes de eliminar
    printf("\n¿Estas seguro de eliminar '%s'? (1=Si, 0=Cancelar): ", libro_eliminar->titulo);
    int confirmar;
    if(scanf("%d", &confirmar) != 1 || confirmar != 1) {
        printf("\n[i] Eliminacion cancelada.\n");
        while(getchar() != '\n');
        return;
    }
    
    // Eliminamos el libro
    if (delete_book(libros, libro_eliminar->titulo) == True) {
        printf("\n[OK] Libro eliminado exitosamente.\n");
        
        // Guardamos el catálogo inmediatamente
        if (guardar_catalog(*libros, "libros.txt") == True) {
            printf("[OK] Catalogo guardado.\n");
        }
    } else {
        printf("\n[!] Error al eliminar el libro.\n");
    }
}

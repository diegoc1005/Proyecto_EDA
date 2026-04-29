#include "catalogo.h"

void escribir_resena_usuario(struct Usuario *user, struct Libro *libros, struct Cola *cola) {
    printf("\n--- ESCRIBIR RESENA ---\n");
    
    if (libros == NULL) {
        printf("[!] No hay libros en el catalogo.\n");
        return;
    }
    
    // Mostramos el catálogo para que el usuario vea los IDs
    show_catalog(libros);
    
    int idLibro;
    printf("\nIngresa el ID del libro que deseas resenar: ");
    if(scanf("%d", &idLibro) != 1) {
        printf("\n[!] Error: ID invalido.\n");
        while(getchar() != '\n');
        return;
    }
    
    // Verificamos que el libro exista
    struct Libro *libro_encontrado = libros;
    int encontrado = 0;
    while (libro_encontrado != NULL) {
        if (libro_encontrado->id == idLibro) {
            encontrado = 1;
            break;
        }
        libro_encontrado = libro_encontrado->nxt;
    }
    
    if (!encontrado) {
        printf("\n[!] No existe un libro con ese ID.\n");
        return;
    }
    
    int puntuacion;
    printf("Calificacion (1-5 estrellas): ");
    if(scanf("%d", &puntuacion) != 1 || puntuacion < 1 || puntuacion > 5) {
        printf("\n[!] Error: La calificacion debe ser entre 1 y 5.\n");
        while(getchar() != '\n');
        return;
    }
    
    // Limpiamos el buffer
    while(getchar() != '\n');
    
    char texto[500];
    printf("Escribe tu resena (max 500 caracteres):\n");
    fgets(texto, 500, stdin);
    texto[strcspn(texto, "\n")] = 0;
    
    // Generamos un ID único para la reseña
    static int idResenaCounter = 1000;
    idResenaCounter++;
    
    // Agregamos la reseña a la cola de pendientes
    if (enqueue(cola, idResenaCounter, idLibro, user->id, texto, puntuacion) == True) {
        printf("\n[OK] Tu resena ha sido enviada y esta pendiente de aprobacion.\n");
        
        // Agregamos una notificación al usuario
        char mensaje[200];
        snprintf(mensaje, 200, "Tu resena para '%s' esta en revision.", libro_encontrado->titulo);
        push_notificacion(&(user->top_notificaciones), mensaje);
    } else {
        printf("\n[!] Error al enviar la resena.\n");
    }
}

#include "catalogo.h"

void moderar_resenas_admin(struct Libro **libros, struct Cola *cola) {
    printf("\n--- MODERACION DE RESENAS ---\n");
    struct Peticion peticion_actual;
    
    // Intentamos sacar la peticion mas antigua de la cola
    if (dequeue(cola, &peticion_actual) == True) {
        printf("ID Libro: %d | ID Usuario: %d | Calificacion: %d estrellas\n",
               peticion_actual.idLibro, peticion_actual.idUsuario, peticion_actual.puntuacion);
        printf("Texto: %s\n", peticion_actual.texto);
        
        int decision;
        printf("\n1. Aprobar | 2. Rechazar | 0. Volver (dejar pendiente)\nDecision: ");
        
        if(scanf("%d", &decision) != 1) {
            printf("\n[!] Error: Entrada invalida. La resena se regresara a la cola.\n");
            while(getchar() != '\n');
            // Regresamos la reseña a la cola para que no se pierda
            enqueue(cola, peticion_actual.idResena, peticion_actual.idLibro,
                    peticion_actual.idUsuario, peticion_actual.texto, peticion_actual.puntuacion);
            return;
        }
        
        if (decision == 0) {
            // Usuario decidió volver sin moderar
            printf("\n[i] Resena devuelta a la cola.\n");
            enqueue(cola, peticion_actual.idResena, peticion_actual.idLibro,
                    peticion_actual.idUsuario, peticion_actual.texto, peticion_actual.puntuacion);
            return;
        } else if (decision == 1) {
            printf("Resena APROBADA.\n");
            
            // Buscamos el libro para actualizar su calificación
            struct Libro *libro_actual = *libros;
            while (libro_actual != NULL) {
                if (libro_actual->id == peticion_actual.idLibro) {
                    // Calculamos el nuevo promedio
                    float suma_total = libro_actual->calificacion * libro_actual->numResenas;
                    suma_total += peticion_actual.puntuacion;
                    libro_actual->numResenas++;
                    libro_actual->calificacion = suma_total / libro_actual->numResenas;
                    
                    printf("[OK] Calificacion actualizada: %.1f (%d resenas)\n",
                           libro_actual->calificacion, libro_actual->numResenas);
                    
                    // Guardamos la reseña aprobada en archivo
                    FILE *f = fopen("resenas_aprobadas.txt", "a");
                    if (f != NULL) {
                        fprintf(f, "%d|%d|%d|%s\n",
                                peticion_actual.idResena,
                                peticion_actual.idLibro,
                                peticion_actual.idUsuario,
                                peticion_actual.texto);
                        fclose(f);
                    }
                    
                    // Guardamos el catálogo actualizado inmediatamente
                    if (guardar_catalog(*libros, "libros.txt") == True) {
                        printf("[OK] Catalogo actualizado.\n");
                    }
                    break;
                }
                libro_actual = libro_actual->nxt;
            }
        } else if (decision == 2) {
            printf("Resena RECHAZADA.\n");
        } else {
            printf("\n[!] Opcion invalida. La resena se regresara a la cola.\n");
            enqueue(cola, peticion_actual.idResena, peticion_actual.idLibro,
                    peticion_actual.idUsuario, peticion_actual.texto, peticion_actual.puntuacion);
            return;
        }
        
        // Guardamos la cola actualizada (se quitó una reseña)
        if (guardar_cola(cola, "resenas_pendientes.txt") == True) {
            printf("[OK] Cola de pendientes actualizada.\n");
        }
    } else {
        printf("No hay resenas pendientes en la cola. ¡Todo al dia!\n");
    }
}

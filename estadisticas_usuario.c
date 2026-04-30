#include "catalogo.h"

void estadisticas_usuario(struct Libro *libros) {
    printf("\n=== ESTADISTICAS DEL SISTEMA ===\n\n");
    
    if (libros == NULL) {
        printf("[!] El catalogo esta vacio.\n");
        return;
    }
    
    int total_libros = 0;
    int total_resenas = 0;
    float suma_calificaciones = 0.0;
    
    // Contamos géneros únicos
    char generos[50][MAX_STR];
    int contador_generos[50] = {0};
    int num_generos = 0;
    
    struct Libro *actual = libros;
    
    while (actual != NULL) {
        total_libros++;
        total_resenas += actual->numResenas;
        suma_calificaciones += actual->calificacion;
        
        // Contamos libros por género
        int encontrado = 0;
        for (int i = 0; i < num_generos; i++) {
            if (strcmp(generos[i], actual->genero) == 0) {
                contador_generos[i]++;
                encontrado = 1;
                break;
            }
        }
        
        if (!encontrado && num_generos < 50) {
            strcpy(generos[num_generos], actual->genero);
            contador_generos[num_generos] = 1;
            num_generos++;
        }
        
        actual = actual->nxt;
    }
    
    // Encontramos el género más popular
    int max_libros = 0;
    char genero_popular[MAX_STR] = "";
    for (int i = 0; i < num_generos; i++) {
        if (contador_generos[i] > max_libros) {
            max_libros = contador_generos[i];
            strcpy(genero_popular, generos[i]);
        }
    }
    
    float promedio_general = (total_libros > 0) ? suma_calificaciones / total_libros : 0.0;
    
    // Mostramos estadísticas
    printf("📚 LIBROS:\n");
    printf("   Total de libros en catalogo: %d\n", total_libros);
    printf("   Generos diferentes: %d\n", num_generos);
    printf("   Genero mas popular: %s (%d libros)\n\n", genero_popular, max_libros);
    
    printf("⭐ CALIFICACIONES:\n");
    printf("   Total de resenas: %d\n", total_resenas);
    printf("   Promedio general: %.2f estrellas\n", promedio_general);
    printf("   Promedio de resenas por libro: %.1f\n\n", (float)total_resenas / total_libros);
    
    printf("📊 DISTRIBUCION POR GENERO:\n");
    for (int i = 0; i < num_generos; i++) {
        printf("   %-20s: %2d libro(s)\n", generos[i], contador_generos[i]);
    }
    
    printf("\n");
}

// Made with Bob

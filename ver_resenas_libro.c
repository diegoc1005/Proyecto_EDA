#include "catalogo.h"

void ver_resenas_libro(struct Libro *libros) {
    printf("\n--- VER RESENAS DE UN LIBRO ---\n");
    
    if (libros == NULL) {
        printf("[!] No hay libros en el catalogo.\n");
        return;
    }
    
    show_catalog(libros);
    
    int idLibro;
    printf("\nIngresa el ID del libro para ver sus resenas: ");
    if(scanf("%d", &idLibro) != 1) {
        printf("\n[!] Error: ID invalido.\n");
        while(getchar() != '\n');
        return;
    }
    
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
    
    printf("\n========================================\n");
    printf("LIBRO: %s\n", libro_encontrado->titulo);
    printf("AUTOR: %s\n", libro_encontrado->autor);
    printf("CALIFICACION PROMEDIO: %.2f estrellas\n", libro_encontrado->calificacion);
    printf("TOTAL DE RESENAS: %d\n", libro_encontrado->numResenas);
    printf("========================================\n\n");
    
    FILE *archivo = fopen("resenas_aprobadas.txt", "r");
    if (archivo == NULL) {
        printf("[!] No hay resenas aprobadas aun.\n");
        return;
    }
    
    char linea[600];
    int resenas_mostradas = 0;
    
    printf("--- RESENAS APROBADAS ---\n\n");
    
    while (fgets(linea, sizeof(linea), archivo)) {
        int idLibroArchivo, idUsuario;
        char texto[500];
        
        char *token = strtok(linea, "|");
        if (token == NULL) continue;
        // Saltamos el idResena, no lo necesitamos
        
        token = strtok(NULL, "|");
        if (token == NULL) continue;
        idLibroArchivo = atoi(token);
        
        token = strtok(NULL, "|");
        if (token == NULL) continue;
        idUsuario = atoi(token);
        
        token = strtok(NULL, "\n");
        if (token == NULL) continue;
        strncpy(texto, token, 499);
        texto[499] = '\0';
        
        if (idLibroArchivo == idLibro) {
            printf("Usuario ID %d:\n", idUsuario);
            printf("\"%s\"\n", texto);
            printf("---\n\n");
            resenas_mostradas++;
        }
    }
    
    fclose(archivo);
    
    if (resenas_mostradas == 0) {
        printf("[!] Este libro aun no tiene resenas aprobadas.\n");
    } else {
        printf("Total: %d resena(s) mostrada(s).\n", resenas_mostradas);
    }
}
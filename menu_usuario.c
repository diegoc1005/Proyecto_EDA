#include "catalogo.h"

enum OpcionesUsuario { SALIR_USUARIO = 0, VER_CATALOGO_U = 1, ESCRIBIR_RESENA = 2, VER_NOTIFICACIONES = 3, BUSCAR_GENERO = 4, VER_RESENAS = 5, BUSCAR_TITULO = 6, TOP_LIBROS = 7, ESTADISTICAS = 8 };

void menu_usuario(struct Usuario *user, struct Libro *libros, struct Cola *cola) {
    int opcion;

    do {
        printf("\n=== MENU DE USUARIO (%s) ===\n", user->nombre);
        printf("1. Ver catalogo de libros\n");
        printf("2. Escribir una resena\n");
        printf("3. Ver mis notificaciones\n");
        printf("4. Buscar libros por genero\n");
        printf("5. Ver resenas de un libro\n");
        printf("6. Buscar libros por titulo\n");
        printf("7. Ver Top 10 libros\n");
        printf("8. Ver estadisticas del sistema\n");
        printf("0. Cerrar sesion\n");
        printf("Elige una opcion: ");
        
        if(scanf("%d", &opcion) != 1) {
            printf("\n[!] Error: Solo se permiten numeros.\n");
            while(getchar() != '\n'); 
            opcion = -1; 
            continue;
        }

        switch (opcion) {
            case VER_CATALOGO_U:
                show_catalog(libros);
                break;
                
            case ESCRIBIR_RESENA:
                escribir_resena_usuario(user, libros, cola);
                break;
                
            case VER_NOTIFICACIONES:
                ver_notificaciones_usuario(user);
                break;
                
            case BUSCAR_GENERO:
                buscar_genero_usuario(libros);
                break;
                
            case VER_RESENAS:
                ver_resenas_libro(libros);
                break;
                
            case BUSCAR_TITULO:
                buscar_titulo_usuario(libros);
                break;
                
            case TOP_LIBROS:
                top_libros_usuario(libros);
                break;
                
            case ESTADISTICAS:
                estadisticas_usuario(libros);
                break;
                
            case SALIR_USUARIO:
                printf("\nCerrando sesion...\n");
                break;
                
            default:
                printf("\n[!] Opcion invalida.\n");
        }
    } while (opcion != SALIR_USUARIO);
}

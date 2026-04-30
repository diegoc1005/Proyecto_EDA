#include "catalogo.h"

enum OpcionesUsuario { SALIR_USUARIO = 0, VER_CATALOGO_U = 1, ESCRIBIR_RESENA = 2, VER_NOTIFICACIONES = 3, BUSCAR_GENERO = 4, VER_RESENAS = 5 };

void menu_usuario(struct Usuario *user, struct Libro *libros, struct Cola *cola) {
    int opcion;

    do {
        printf("\n=== MENU DE USUARIO (%s) ===\n", user->nombre);
        printf("1. Ver catalogo de libros\n");
        printf("2. Escribir una resena\n");
        printf("3. Ver mis notificaciones\n");
        printf("4. Buscar libros por genero\n");
        printf("5. Ver resenas de un libro\n");
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
                
            case SALIR_USUARIO:
                printf("\nCerrando sesion...\n");
                break;
                
            default:
                printf("\n[!] Opcion invalida.\n");
        }
    } while (opcion != SALIR_USUARIO);
}

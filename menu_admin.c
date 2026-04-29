#include "catalogo.h"

enum OpcionesAdmin { SALIR_ADMIN = 0, VER_CATALOGO = 1, AGREGAR_LIBRO = 2, MODERAR_RESENAS = 3, ELIMINAR_LIBRO = 4 };

void menu_admin(struct Libro **libros, struct Cola *cola) {
    int opcion;

    do {
        printf("\n=== PANEL DE ADMINISTRADOR ===\n");
        printf("1. Ver catalogo completo\n");
        printf("2. Agregar un nuevo libro\n");
        printf("3. Moderar resenas pendientes\n");
        printf("4. Eliminar un libro\n");
        printf("0. Cerrar sesion\n");
        printf("Elige una opcion: ");
       
        if(scanf("%d", &opcion) != 1) {
            printf("\n[!] Error: Solo se permiten numeros.\n");
            while(getchar() != '\n'); 
            opcion = -1; 
            continue;
        }

        switch (opcion) {
            case VER_CATALOGO:
                show_catalog(*libros);
                break;
                
            case AGREGAR_LIBRO:
                agregar_libro_admin(libros);
                break;
                
            case MODERAR_RESENAS:
                moderar_resenas_admin(libros, cola);
                break;
                
            case ELIMINAR_LIBRO:
                eliminar_libro_admin(libros);
                break;
                
            case SALIR_ADMIN:
                printf("\nCerrando sesion de administrador...\n");
                break;
                
            default:
                printf("\n[!] Opcion invalida.\n");
        }
    } while (opcion != SALIR_ADMIN);
}

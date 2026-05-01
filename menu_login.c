#include "catalogo.h"

// El enum para hacer el switch mas legible
enum OpcionesLogin { SALIR_LOGIN = 0, INICIAR_SESION = 1, REGISTRO = 2 };

// Usamos doble apuntador para head_usuarios porque registrar_usuario podría modificar la cabeza de la lista
void menu_login(struct Usuario **head_usuarios, int *numUsuarios, struct Libro **libros, struct Cola *cola) {
    int opcion = 0;
    char user[50], pass[50];
    struct Usuario *sesion = NULL; // Aquí guardamos quién inició sesión

    do {
        printf("\n=== BIENVENIDO AL SISTEMA DE RESENAS ===\n");
        printf("1. Iniciar Sesion\n");
        printf("2. Registrarse\n");
        printf("0. Salir del programa\n");
        printf("Elige una opcion: ");
        
        if(scanf("%d", &opcion) != 1) {
            printf("\n[!] Error: Solo se permiten numeros.\n");
            while(getchar() != '\n'); // Limpiar el buffer
            opcion = -1; // Evita que se cierre por accidente
            continue;
        }

        switch (opcion) {
            case INICIAR_SESION:
                printf("\n--- LOGIN ---\n");
                printf("Usuario: ");
                while(getchar() != '\n'); // Limpiar buffer
                fgets(user, 50, stdin);
                user[strcspn(user, "\n")] = 0; // Quitar salto de línea
                
                // Verificamos si el usuario existe ANTES de pedir password
                struct Usuario *actual = *head_usuarios;
                enum boolean existe = False;
                
                while (actual != NULL) {
                    if (strcmp(actual->nombre, user) == 0) {
                        existe = True;
                        break; // Lo encontramos, rompemos el ciclo
                    }
                    actual = actual->nxt;
                }

                if (existe == False) {
                    printf("\n[!] El usuario '%s' no esta registrado en el sistema.\n", user);
                    break; // Cortamos el proceso y regresamos al menu
                }

                // Si existe, pedimos la contraseña
                printf("Password: ");
                fgets(pass, 50, stdin);
                pass[strcspn(pass, "\n")] = 0; // Quitar salto de línea
                
                // Intentamos hacer login
                sesion = login_usuario(*head_usuarios, user, pass);
                
                if (sesion != NULL) {
                    // Login exitoso, verificamos el rol
                    if (strcmp(sesion->rol, "admin") == 0) {
                        menu_admin(libros, cola);
                    } else {
                        menu_usuario(sesion, *libros, cola);
                    }
                } else {
                    printf("\n[!] Credenciales incorrectas. Intenta de nuevo.\n");
                }
                break;
                
            case REGISTRO:
                printf("\n--- NUEVO REGISTRO ---\n");
                // Le pasamos el doble apuntador directo
                registrar_usuario(head_usuarios, numUsuarios);
                break;
                
            case SALIR_LOGIN:
                // No hacemos nada, el while terminara y regresara al menu principal
                break;
                
            default:
                printf("\n[!] Opcion invalida.\n");
        }
    } while (opcion != SALIR_LOGIN);
}
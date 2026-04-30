#include "catalogo.h"

enum boolean registrar_usuario(struct Usuario **head_usuarios, int *numUsuarios) {
    char nombre_temp[50];
    
    printf("Escribe tu nombre de usuario: ");
    scanf(" %49[^\n]", nombre_temp);
    
    // Verificamos que el nombre no exista ya
    struct Usuario *actual = *head_usuarios;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre_temp) == 0) {
            printf("\n[!] Error: El nombre de usuario '%s' ya existe.\n", nombre_temp);
            printf("[!] Por favor elige otro nombre.\n");
            return False;
        }
        actual = actual->nxt;
    }
    
    struct Usuario *tmp = (struct Usuario*)malloc(sizeof(struct Usuario));
    if (tmp == NULL) return False;

    tmp->id = (*numUsuarios) + 1;
    strcpy(tmp->nombre, nombre_temp);

    printf("Escribe tu password: ");
    scanf(" %49[^\n]", tmp->password);

    strcpy(tmp->rol, "user");
    tmp->top_notificaciones = NULL;

    tmp->nxt = *head_usuarios;
    *head_usuarios = tmp;

    (*numUsuarios)++;
    printf("\n[OK] Usuario %s registrado con exito (ID: %d).\n", tmp->nombre, tmp->id);
    
    // Guardamos la lista de usuarios inmediatamente
    if (guardar_usuarios(*head_usuarios, "usuarios.txt") == True) {
        printf("[OK] Usuario guardado.\n");
    }

    return True;
}
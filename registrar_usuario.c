#include "catalogo.h"

enum boolean registrar_usuario(struct Usuario **head_usuarios, int *numUsuarios) {
    struct Usuario *tmp = (struct Usuario*)malloc(sizeof(struct Usuario));
    if (tmp == NULL) return False;

    // Le asignamos su ID usando el contador general
    tmp->id = (*numUsuarios) + 1;

    // Pedimos sus datos
    printf("Escribe tu nombre de usuario: ");
    scanf(" %49[^\n]", tmp->nombre); 

    printf("Escribe tu password: ");
    scanf(" %49[^\n]", tmp->password);

    // Valores por defecto
    strcpy(tmp->rol, "user");          
    tmp->top_notificaciones = NULL;    

    // Inserción en la lista por la cabeza
    tmp->nxt = *head_usuarios;
    *head_usuarios = tmp;

    (*numUsuarios)++;
    printf("Usuario %s registrado con exito (ID: %d).\n", tmp->nombre, tmp->id);

    return True;
}
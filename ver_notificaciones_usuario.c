#include "catalogo.h"

void ver_notificaciones_usuario(struct Usuario *user) {
    printf("\n--- MIS NOTIFICACIONES ---\n");
    char mensaje[200];
    
    // Hacemos pop a su pila personal
    if (pop_notificacion(&(user->top_notificaciones), mensaje) == True) {
        printf(">> %s\n", mensaje);
    } else {
        printf("No tienes notificaciones nuevas.\n");
    }
}

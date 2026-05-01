#include "catalogo.h"

void menu_principal() {
    // Inicializamos todas nuestras estructuras dinamicas en vacio
    struct Usuario *head_usuarios = NULL;
    int numUsuarios = 0;
    
    struct Libro *libros = NULL; // Lista Doble del catalogo
    
    struct Cola colaPendientes;  // Cola para las reseñas
    colaPendientes.head = NULL;
    colaPendientes.tail = NULL;

    // printf("\nIniciando Sistema de Resenas...\n");

    // Cargamos los datos persistentes de los archivos .txt
    load_catalog(&libros);
    cargar_usuarios(&head_usuarios, &numUsuarios, "usuarios.txt");
    cargar_cola(&colaPendientes, "resenas_pendientes.txt");

    // Lanzamos la interfaz visual y le pasamos las direcciones de memoria de todo para que pueda modificar los datos
    menu_login(&head_usuarios, &numUsuarios, &libros, &colaPendientes);

    // Al salir del menu_login cuando el usuario elige la opcion "Salir" se guarda todo
    printf("\nGuardando cambios en la base de datos...\n");
    guardar_usuarios(head_usuarios, "usuarios.txt");
    guardar_catalog(libros, "libros.txt");
    guardar_cola(&colaPendientes, "resenas_pendientes.txt");

    printf("Sistema cerrado correctamente. ¡Hasta luego!\n");
}
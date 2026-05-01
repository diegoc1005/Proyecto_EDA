#ifndef CATALOGO_H
#define CATALOGO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

// Tipo de dato booleano personalizado para el control de errores
enum boolean {False, True};

// ==========================================
// 1. EL CATÁLOGO - Lista Doble
// ==========================================

// Estructura para los nodos de la Lista Doblemente Ligada, nuestro Catálogo principal
struct Libro {
    int id;                 // Identificador único del libro
    char titulo[MAX_STR];   // Título de la obra
    char autor[MAX_STR];    // Nombre del autor
    char genero[MAX_STR];   // Clasificación literaria
    float calificacion;     // Promedio de estrellas otorgadas
    int numResenas;         // Cantidad total de reseñas aprobadas
    struct Libro *prev;     // Apuntador al libro anterior
    struct Libro *nxt;      // Apuntador al libro siguiente
};

// --- Prototipos del Catálogo ---

// Lee el archivo .txt de libros y los inserta en la memoria dinámica
enum boolean load_catalog(struct Libro **head);

// Inserta un nuevo libro en la lista doble manteniendo el orden alfabético
enum boolean insert_book(struct Libro **head, struct Libro *nuevo_libro);

// Recorre e imprime la tabla formateada del catálogo en la consola
void show_catalog(struct Libro *head);

// Busca por título y elimina un libro ajustando los apuntadores dobles
enum boolean delete_book(struct Libro **head, char *titulo_buscar);

enum boolean guardar_catalog(struct Libro *head, const char *archivo);


// ==========================================
// 2. LA COLA, nuestro Buzón
// ==========================================

// Estructura para los nodos de la Cola, para las reseñas pendientes de aprobación
struct Peticion {
    int idResena;           // Identificador temporal de la petición
    int idLibro;            // Libro al que pertenece la reseña
    int idUsuario;          // Autor de la reseña
    char texto[500];        // Contenido textual de la reseña
    int puntuacion;         // Calificación propuesta (1 a 5)
    struct Peticion *nxt;   // Apuntador a la siguiente petición en la fila
};

// Controlador de la Cola con apuntadores a los extremos para inserciones eficientes
struct Cola {
    struct Peticion *head;  // Apuntador al frente (para extraer)
    struct Peticion *tail;  // Apuntador al final (para insertar)
};

// --- Prototipos de la Cola ---

// Añade una nueva petición de reseña al final del buzón 
enum boolean enqueue(struct Cola *c, int idR, int idL, int idU, const char *texto, int punt);

// Extrae la petición más antigua del frente del buzón para ser moderada
enum boolean dequeue(struct Cola *c, struct Peticion *destino);

// Prototipos de Guardado/Carga de la Cola
enum boolean guardar_cola(struct Cola *c, const char *archivo);
enum boolean cargar_cola(struct Cola *c, const char *archivo);


// ==========================================
// 3. ESTRUCTURAS PARA USUARIOS Y NOTIFICACIONES
// ==========================================

// Estructura para los nodos de la Pila, nuestro Historial de notificaciones
struct Notificacion {
    char mensaje[200];          // Contenido de la alerta
    struct Notificacion *nxt;   // Apuntador a la notificación anterior
};

// Estructura para los nodos de la Lista Simple, nuestros Usuarios del sistema
struct Usuario {
    int id;                                  // Identificador único de usuario
    char nombre[50];                         // Nombre de inicio de sesión
    char password[50];                       // Contraseña de acceso
    char rol[10];                            // Nivel de permisos ("admin" o "user")
    struct Notificacion *top_notificaciones; // Puntero a su pila personal de mensajes
    struct Usuario *nxt;                     // Apuntador al siguiente usuario registrado
};

// --- Prototipos de la Pila de Notificaciones ---

// Apila un nuevo mensaje de alerta en la cima de la bandeja del usuario
enum boolean push_notificacion(struct Notificacion **top, char *mensaje);

// Extrae y elimina el mensaje más reciente de la bandeja del usuario
enum boolean pop_notificacion(struct Notificacion **top, char *destino);

// --- Prototipos de la Lista de Usuarios ---

// Crea un nuevo usuario en memoria dinámica y lo inserta en la lista
enum boolean registrar_usuario(struct Usuario **head_usuarios, int *numUsuarios);

// Valida las credenciales y retorna el apuntador directo al usuario logueado
struct Usuario* login_usuario(struct Usuario *head_usuarios, char *nombre, char *pass);

// --- Prototipos de Guardado/Carga ---

// Sobrescribe el archivo de texto volcando toda la lista dinámica de usuarios
enum boolean guardar_usuarios(struct Usuario *head_usuarios, const char *archivo);

// Lee el archivo de texto
enum boolean cargar_usuarios(struct Usuario **head_usuarios, int *numUsuarios, const char *archivo);

// ==========================================
// 4. INTERFACES VISUALES 
// ==========================================

// Menu principal que arranca la app
void menu_principal();

// Pantalla interactiva de inicio de sesión y registro
void menu_login(struct Usuario **head_usuarios, int *numUsuarios, struct Libro **libros, struct Cola *cola);

// Menú con privilegios para gestionar el catálogo y moderar reseñas
void menu_admin(struct Libro **libros, struct Cola *cola);

// Menú estándar para explorar libros y redactar nuevas peticiones
void menu_usuario(struct Usuario *user, struct Libro *libros, struct Cola *cola);

// ==========================================
// 5. FUNCIONES AUXILIARES DE MENÚS
// ==========================================

// Funciones del menú de administrador
void agregar_libro_admin(struct Libro **libros);
void moderar_resenas_admin(struct Libro **libros, struct Cola *cola);
void eliminar_libro_admin(struct Libro **libros);

// Funciones del menú de usuario
void escribir_resena_usuario(struct Usuario *user, struct Libro *libros, struct Cola *cola);
void ver_notificaciones_usuario(struct Usuario *user);
void buscar_genero_usuario(struct Libro *libros);
void ver_resenas_libro(struct Libro *libros);
void buscar_titulo_usuario(struct Libro *libros);
void top_libros_usuario(struct Libro *libros);
void estadisticas_usuario(struct Libro *libros);

#endif
# Sistema de Gestión de Reseñas de Libros por Género

## Descripción del Proyecto
Aplicación en lenguaje C que permite gestionar un catálogo de libros organizados por género literario, facilitando a los usuarios enviar reseñas y calificaciones, y a los administradores moderar el contenido.

## Estructuras de Datos Implementadas

### 1. Lista Doblemente Ligada (Catálogo de Libros)
- **Propósito**: Almacenar el catálogo de libros ordenado alfabéticamente
- **Operaciones**: Inserción ordenada, eliminación, recorrido bidireccional
- **Archivo**: `struct Libro` en `catalogo.h`

### 2. Cola FIFO (Reseñas Pendientes)
- **Propósito**: Gestionar reseñas pendientes de aprobación por orden de llegada
- **Operaciones**: Enqueue (agregar al final), Dequeue (extraer del frente)
- **Archivo**: `struct Peticion` y `struct Cola` en `catalogo.h`

### 3. Pila LIFO (Notificaciones)
- **Propósito**: Almacenar notificaciones de usuarios
- **Operaciones**: Push (agregar), Pop (extraer)
- **Archivo**: `struct Notificacion` en `catalogo.h`

### 4. Lista Simple (Usuarios)
- **Propósito**: Gestionar usuarios del sistema
- **Operaciones**: Registro, login, gestión de permisos
- **Archivo**: `struct Usuario` en `catalogo.h`

## Compilación

### Opción 1 - Compilar todos los archivos (Recomendado):
```bash
gcc *.c -o proyecto -Wall
```

### Opción 2 - Usar el script de Windows:
```bash
compilar.bat
```

### Opción 3 - Compilar manualmente (listando cada archivo):
```bash
gcc -o proyecto main.c menu_principal.c menu_login.c menu_admin.c menu_usuario.c \
    load_catalog.c insert_book.c show_catalog.c delete_book.c guardar_catalog.c \
    enqueue.c dequeue.c guardar_cola.c cargar_cola.c \
    push_notificacion.c pop_notificacion.c \
    registrar_usuario.c login_usuario.c guardar_usuarios.c cargar_usuarios.c \
    agregar_libro_admin.c moderar_resenas_admin.c eliminar_libro_admin.c \
    escribir_resena_usuario.c ver_notificaciones_usuario.c buscar_genero_usuario.c -Wall
```

### Ejecutar:
```bash
./proyecto
```

## Funcionalidades

### Menú de Administrador
1. **Ver catálogo completo** - Muestra todos los libros ordenados alfabéticamente
2. **Agregar un nuevo libro** - Permite agregar libros al catálogo
3. **Moderar reseñas pendientes** - Aprobar o rechazar reseñas de usuarios
4. **Eliminar un libro** - Eliminar libros del catálogo
5. **Cerrar sesión**

### Menú de Usuario
1. **Ver catálogo de libros** - Consultar libros disponibles
2. **Escribir una reseña** - Enviar reseña con calificación (1-5 estrellas)
3. **Ver mis notificaciones** - Consultar notificaciones personales
4. **Buscar libros por género** - Filtrar libros por categoría
5. **Cerrar sesión**

## Archivos de Datos

### libros.txt
Formato: `ID|Titulo|Autor|Genero|Calificacion|NumResenas`
```
1|1984|George Orwell|Ficcion|4.8|10
2|Cien Anios de Soledad|Gabriel Garcia Marquez|Realismo Magico|4.9|15
```

### usuarios.txt
Formato: `ID|Nombre|Password|Rol`
```
1|admin|admin123|admin
2|usuario1|pass123|user
```

### resenas_pendientes.txt
Formato: `IDResena|IDLibro|IDUsuario|Texto|Puntuacion`

### resenas_aprobadas.txt
Formato: `IDResena|IDLibro|IDUsuario|Texto`

## Persistencia de Datos
- Todos los cambios se guardan automáticamente al cerrar la aplicación
- Los datos se cargan al iniciar el sistema
- Archivos en formato texto plano para fácil inspección

## Requisitos Cumplidos

### Funcionales
✅ Uso de estructuras de datos lineales (pila, cola, lista)
✅ Aplicación útil y funcional
✅ Sistema de inicio de sesión con dos perfiles (admin y usuario)
✅ Persistencia de datos en archivos de texto plano

### No Funcionales
✅ Implementado en ANSI C
✅ Uso de arreglos, apuntadores, estructuras y memoria dinámica
✅ Proyecto dividido en funciones, cada una en su archivo
✅ main() solo contiene llamada a menú principal
✅ Estructuras de datos con struct y memoria dinámica

## Estructura del Proyecto

```
Proyecto/
├── catalogo.h                      # Definiciones de estructuras y prototipos
├── main.c                          # Punto de entrada
├── menu_principal.c                # Menú principal e inicialización
├── menu_login.c                    # Sistema de autenticación
├── menu_admin.c                    # Interfaz de administrador (solo switch)
├── menu_usuario.c                  # Interfaz de usuario (solo switch)
│
├── Funciones del Catálogo (Lista Doble):
│   ├── load_catalog.c              # Cargar catálogo desde archivo
│   ├── insert_book.c               # Insertar libro ordenadamente
│   ├── show_catalog.c              # Mostrar catálogo
│   ├── delete_book.c               # Eliminar libro
│   └── guardar_catalog.c           # Guardar catálogo en archivo
│
├── Funciones de la Cola (FIFO):
│   ├── enqueue.c                   # Agregar a cola
│   ├── dequeue.c                   # Extraer de cola
│   ├── guardar_cola.c              # Guardar cola en archivo
│   └── cargar_cola.c               # Cargar cola desde archivo
│
├── Funciones de la Pila (LIFO):
│   ├── push_notificacion.c         # Agregar a pila
│   └── pop_notificacion.c          # Extraer de pila
│
├── Funciones de Usuarios (Lista Simple):
│   ├── registrar_usuario.c         # Registrar nuevo usuario
│   ├── login_usuario.c             # Autenticar usuario
│   ├── guardar_usuarios.c          # Guardar usuarios en archivo
│   └── cargar_usuarios.c           # Cargar usuarios desde archivo
│
├── Funciones Auxiliares del Menú Admin:
│   ├── agregar_libro_admin.c       # Lógica para agregar libro
│   ├── moderar_resenas_admin.c     # Lógica para moderar reseñas
│   └── eliminar_libro_admin.c      # Lógica para eliminar libro
│
├── Funciones Auxiliares del Menú Usuario:
│   ├── escribir_resena_usuario.c   # Lógica para escribir reseña
│   ├── ver_notificaciones_usuario.c # Lógica para ver notificaciones
│   └── buscar_genero_usuario.c     # Lógica para buscar por género
│
├── Archivos de Datos:
│   ├── libros.txt                  # Base de datos de libros
│   ├── usuarios.txt                # Base de datos de usuarios
│   ├── resenas_pendientes.txt      # Cola de reseñas pendientes
│   └── resenas_aprobadas.txt       # Reseñas aprobadas
│
└── Documentación:
    ├── README.md                   # Este archivo
    ├── PRUEBAS.md                  # Plan de pruebas
    └── compilar.bat                # Script de compilación
```

**Total: 26 archivos .c + 1 archivo .h = 27 archivos de código**

## Autores
- Yañez Guerrero Dulce María
- Diego
- Grupo: 07
- Profesor: M.C. Jorge Alberto Solano Gálvez
- Asignatura: Estructura De Datos y Algoritmos I

## Fecha de Entrega
30 de abril de 2026
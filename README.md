# Sistema de Gestión de Reseñas de Libros por Género

## Descripción del Proyecto
Aplicación en lenguaje C que permite gestionar un catálogo de libros organizados por género literario, facilitando a los usuarios enviar reseñas y calificaciones, y a los administradores moderar el contenido.

## Estructuras de Datos Implementadas

### 1. Lista Doblemente Ligada (Catálogo de Libros) ✅

**¿Qué es?**
Una lista doblemente ligada es una estructura de datos donde cada nodo tiene dos apuntadores: uno al nodo anterior (`prev`) y otro al siguiente (`nxt`). Esto permite recorrer la lista en ambas direcciones.

**¿Cómo funciona en nuestro proyecto?**
```c
struct Libro {
    int id;
    char titulo[MAX_STR];
    char autor[MAX_STR];
    char genero[MAX_STR];
    float calificacion;
    int numResenas;
    struct Libro *prev;  // ← Apuntador al libro anterior
    struct Libro *nxt;   // → Apuntador al libro siguiente
};
```

**Operaciones implementadas:**
- **Inserción ordenada** (`insert_book.c`): Inserta libros manteniendo orden alfabético por título
  - Si la lista está vacía, el nuevo libro se convierte en el head
  - Si va al principio, se actualiza el head y se conectan los apuntadores
  - Si va en medio o al final, se busca la posición correcta y se insertan los enlaces bidireccionales
  
- **Eliminación** (`delete_book.c`): Elimina un libro ajustando los apuntadores prev y nxt de los nodos adyacentes

- **Recorrido bidireccional** (`show_catalog.c`): Puede recorrer de inicio a fin o viceversa

**¿Por qué usamos lista doble?**
- Permite inserción ordenada eficiente
- Facilita la eliminación de nodos (no necesitamos buscar el anterior)
- Permite navegación en ambas direcciones

---

### 2. Cola FIFO (Reseñas Pendientes) ✅

**¿Qué es?**
FIFO significa "First In, First Out" (Primero en Entrar, Primero en Salir). Es como una fila de personas: quien llega primero, es atendido primero.

**¿Cómo funciona en nuestro proyecto?**
```c
struct Peticion {
    int idResena;
    int idLibro;
    int idUsuario;
    char texto[500];
    int puntuacion;
    struct Peticion *nxt;  // → Apuntador al siguiente en la fila
};

struct Cola {
    struct Peticion *head;  // ← Frente de la cola (para extraer)
    struct Peticion *tail;  // ← Final de la cola (para insertar)
};
```

**Operaciones implementadas:**
- **Enqueue** (`enqueue.c`): Agrega una nueva reseña al FINAL de la cola
  ```
  Antes:  [Reseña1] → [Reseña2] → NULL
  Después: [Reseña1] → [Reseña2] → [Reseña3] → NULL
                                      ↑ tail
  ```

- **Dequeue** (`dequeue.c`): Extrae la reseña del FRENTE de la cola
  ```
  Antes:  [Reseña1] → [Reseña2] → [Reseña3] → NULL
           ↑ head
  Después: [Reseña2] → [Reseña3] → NULL
           ↑ head (se movió)
  ```

**¿Por qué usamos cola FIFO?**
- Las reseñas se moderan en orden de llegada (justo)
- El administrador atiende primero las reseñas más antiguas
- Evita que reseñas nuevas "se cuelen" antes que las antiguas

**Persistencia:**
- `guardar_cola.c`: Guarda todas las reseñas pendientes en `resenas_pendientes.txt`
- `cargar_cola.c`: Carga las reseñas al iniciar el programa

---

### 3. Pila LIFO (Notificaciones) ✅

**¿Qué es?**
LIFO significa "Last In, First Out" (Último en Entrar, Primero en Salir). Es como una pila de platos: el último que pones encima es el primero que sacas.

**¿Cómo funciona en nuestro proyecto?**
```c
struct Notificacion {
    char mensaje[200];
    struct Notificacion *nxt;  // → Apuntador a la notificación anterior
};
```

**Operaciones implementadas:**
- **Push** (`push_notificacion.c`): Agrega una notificación en la CIMA de la pila
  ```
  Antes:  [Notif2] → [Notif1] → NULL
           ↑ top
  Después: [Notif3] → [Notif2] → [Notif1] → NULL
           ↑ top (nueva cima)
  ```

- **Pop** (`pop_notificacion.c`): Extrae la notificación de la CIMA
  ```
  Antes:  [Notif3] → [Notif2] → [Notif1] → NULL
           ↑ top
  Después: [Notif2] → [Notif1] → NULL
           ↑ top (se movió)
  ```

**¿Por qué usamos pila LIFO?**
- Las notificaciones más recientes son las más importantes
- El usuario ve primero lo último que pasó (como notificaciones de celular)
- Ejemplo: "Tu reseña fue aprobada" aparece antes que notificaciones antiguas

**Integración:**
Cada usuario tiene su propia pila de notificaciones:
```c
struct Usuario {
    // ... otros campos ...
    struct Notificacion *top_notificaciones;  // ← Pila personal
};
```

---

### 4. Lista Simple (Usuarios) ✅

**¿Qué es?**
Una lista simple es una estructura donde cada nodo tiene un solo apuntador al siguiente nodo. Solo se puede recorrer en una dirección.

**¿Cómo funciona en nuestro proyecto?**
```c
struct Usuario {
    int id;
    char nombre[50];
    char password[50];
    char rol[10];  // "admin" o "user"
    struct Notificacion *top_notificaciones;  // ← Pila de notificaciones
    struct Usuario *nxt;  // → Apuntador al siguiente usuario
};
```

**Operaciones implementadas:**
- **Registro** (`registrar_usuario.c`): Agrega un nuevo usuario al final de la lista
- **Login** (`login_usuario.c`): Busca un usuario por nombre y valida su contraseña
- **Persistencia**:
  - `guardar_usuarios.c`: Guarda todos los usuarios en `usuarios.txt`
  - `cargar_usuarios.c`: Carga los usuarios al iniciar

**¿Por qué usamos lista simple?**
- No necesitamos recorrer hacia atrás
- Más eficiente en memoria (un solo apuntador por nodo)
- Suficiente para buscar usuarios por nombre

---

## Resumen de Cumplimiento de Requisitos

| Estructura | Tipo | Implementada | Archivos Clave |
|------------|------|--------------|----------------|
| **Catálogo de Libros** | Lista Doblemente Ligada | ✅ | `insert_book.c`, `delete_book.c`, `show_catalog.c` |
| **Reseñas Pendientes** | Cola FIFO | ✅ | `enqueue.c`, `dequeue.c`, `guardar_cola.c` |
| **Notificaciones** | Pila LIFO | ✅ | `push_notificacion.c`, `pop_notificacion.c` |
| **Usuarios** | Lista Simple | ✅ | `registrar_usuario.c`, `login_usuario.c` |

**Todas las estructuras usan memoria dinámica (`malloc`) y tienen persistencia en archivos de texto plano.**

## Compilación y Ejecución

### Opción 1 - Compilar todos los archivos (Recomendado):
```bash
gcc *.c -o proyecto -Wall
```

### Opción 2 - Usar el script de Windows:
```bash
compilar.bat
```
El script compila automáticamente todos los archivos .c y genera `a.exe`

### Opción 3 - Compilar manualmente (listando cada archivo):
```bash
gcc -o proyecto main.c menu_principal.c menu_login.c menu_admin.c menu_usuario.c \
    load_catalog.c insert_book.c show_catalog.c delete_book.c guardar_catalog.c \
    enqueue.c dequeue.c guardar_cola.c cargar_cola.c \
    push_notificacion.c pop_notificacion.c \
    registrar_usuario.c login_usuario.c guardar_usuarios.c cargar_usuarios.c \
    agregar_libro_admin.c moderar_resenas_admin.c eliminar_libro_admin.c \
    escribir_resena_usuario.c ver_notificaciones_usuario.c buscar_genero_usuario.c \
    ver_resenas_libro.c buscar_titulo_usuario.c top_libros_usuario.c estadisticas_usuario.c -Wall
```

### Ejecutar:
**Windows:**
```bash
a.exe
```

**Linux/Mac:**
```bash
./proyecto
```

### Credenciales de Prueba:
- **Administrador:** `admin` / `admin123`
- **Usuario:** `dulce` / `niña`

## Funcionalidades

### Menú de Administrador
1. **Ver catálogo completo** - Muestra todos los libros con ID, título, autor, género y calificación
2. **Agregar un nuevo libro** - Agrega libros al catálogo (calificación inicial 0.0)
   - Guardado automático inmediato
3. **Moderar reseñas pendientes** - Aprobar o rechazar reseñas (muestra contador de pendientes)
   - Guardado automático al aprobar/rechazar
4. **Eliminar un libro** - Elimina por ID con confirmación
   - Guardado automático inmediato
5. **Cerrar sesión**

### Menú de Usuario
1. **Ver catálogo de libros** - Consulta libros con ID, calificación y número de reseñas
2. **Escribir una reseña** - Envía reseña (primero texto, luego calificación 1-5)
   - Validación de texto no vacío
   - Guardado automático en cola de pendientes
3. **Ver mis notificaciones** - Consulta notificaciones (LIFO - más recientes primero)
4. **Buscar libros por género** - Filtra libros por categoría literaria
5. **Ver reseñas de un libro** - Muestra todas las reseñas aprobadas de un libro específico
6. **Buscar por título** - Búsqueda parcial en títulos (case-sensitive)
7. **Top 10 libros mejor calificados** - Muestra ranking ordenado por calificación
8. **Estadísticas del sistema** - Muestra totales, promedios y género más popular
9. **Cerrar sesión**

## Archivos de Datos

### libros.txt
Formato: `ID|Titulo|Autor|Genero|Calificacion|NumResenas`
```
1|1984|George Orwell|Ficcion|4.8|10
2|Cien Anios de Soledad|Gabriel Garcia Marquez|Realismo Magico|4.9|15
```
**Contenido actual:** 50 libros de 12 géneros diferentes

### usuarios.txt
Formato: `ID|Nombre|Password|Rol`
```
1|admin|admin123|admin
2|usuario1|pass123|user
```
**Usuarios predefinidos:**
- Admin: `admin` / `admin123`
- Usuario de prueba: `dulce` / `niña`

### resenas_pendientes.txt
Formato: `IDResena|IDLibro|IDUsuario|Texto|Puntuacion`
```
1|5|2|Excelente libro, muy recomendado|5
```
**Gestión:** Cola FIFO - se procesan en orden de llegada

### resenas_aprobadas.txt
Formato: `IDResena|IDLibro|IDUsuario|Texto`
```
1|1|2|Una obra maestra de la distopia
```
**Contenido actual:** 150 reseñas aprobadas (3 por cada libro)

## Persistencia de Datos ⚡
- **Guardado automático inmediato** en todas las operaciones críticas:
  - Agregar libro → guarda catálogo
  - Eliminar libro → guarda catálogo
  - Aprobar reseña → guarda catálogo y cola
  - Rechazar reseña → guarda cola
  - Escribir reseña → guarda cola
  - Registrar usuario → guarda usuarios
- Los datos se cargan automáticamente al iniciar el sistema
- Archivos en formato texto plano (UTF-8) para fácil inspección
- Soporta caracteres especiales (ñ, acentos)

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
├── catalogo.h                          # Definiciones de estructuras y prototipos
├── main.c                              # Punto de entrada (solo llama a menu_principal)
├── menu_principal.c                    # Menú principal e inicialización de estructuras
├── menu_login.c                        # Sistema de autenticación (soporta UTF-8)
├── menu_admin.c                        # Interfaz de administrador (switch con contador)
├── menu_usuario.c                      # Interfaz de usuario (switch con 9 opciones)
│
├── Funciones del Catálogo (Lista Doblemente Ligada):
│   ├── load_catalog.c                  # Cargar catálogo desde archivo
│   ├── insert_book.c                   # Insertar libro ordenadamente (alfabético)
│   ├── show_catalog.c                  # Mostrar catálogo con columna ID
│   ├── delete_book.c                   # Eliminar libro por ID
│   └── guardar_catalog.c               # Guardar catálogo en archivo
│
├── Funciones de la Cola FIFO (Reseñas Pendientes):
│   ├── enqueue.c                       # Agregar reseña al final de la cola
│   ├── dequeue.c                       # Extraer reseña del frente de la cola
│   ├── guardar_cola.c                  # Guardar cola en archivo
│   └── cargar_cola.c                   # Cargar cola desde archivo
│
├── Funciones de la Pila LIFO (Notificaciones):
│   ├── push_notificacion.c             # Agregar notificación a la cima
│   └── pop_notificacion.c              # Extraer notificación de la cima
│
├── Funciones de Usuarios (Lista Simple):
│   ├── registrar_usuario.c             # Registrar nuevo usuario (con fgets)
│   ├── login_usuario.c                 # Autenticar usuario
│   ├── guardar_usuarios.c              # Guardar usuarios en archivo
│   └── cargar_usuarios.c               # Cargar usuarios desde archivo
│
├── Funciones Auxiliares del Menú Admin:
│   ├── agregar_libro_admin.c           # Agregar libro (guardado automático)
│   ├── moderar_resenas_admin.c         # Moderar reseñas (guardado automático)
│   └── eliminar_libro_admin.c          # Eliminar libro por ID (con confirmación)
│
├── Funciones Auxiliares del Menú Usuario:
│   ├── escribir_resena_usuario.c       # Escribir reseña (texto primero, validación)
│   ├── ver_notificaciones_usuario.c    # Ver notificaciones (LIFO)
│   ├── buscar_genero_usuario.c         # Buscar libros por género
│   ├── ver_resenas_libro.c             # Ver reseñas aprobadas de un libro
│   ├── buscar_titulo_usuario.c         # Búsqueda parcial por título
│   ├── top_libros_usuario.c            # Top 10 libros mejor calificados
│   └── estadisticas_usuario.c          # Estadísticas del sistema
│
├── Archivos de Datos:
│   ├── libros.txt                      # 50 libros de 12 géneros
│   ├── usuarios.txt                    # Usuarios del sistema
│   ├── resenas_pendientes.txt          # Cola de reseñas pendientes
│   └── resenas_aprobadas.txt           # 150 reseñas aprobadas
│
└── Documentación:
    ├── README.md                       # Este archivo (documentación completa)
    ├── PRUEBAS.md                      # Plan de pruebas del sistema
    ├── GUIA_DEMOSTRACION.md            # Guía para demostrar el proyecto
    ├── GUIA_GITHUB.md                  # Instrucciones de GitHub
    ├── INSTRUCCIONES_PARA_DESCARGAR.md # Cómo descargar el proyecto
    ├── compilar.bat                    # Script de compilación para Windows
    └── .gitignore                      # Archivos excluidos de Git
```

**Total: 30 archivos .c + 1 archivo .h = 31 archivos de código**
**Documentación: 6 archivos .md + 1 .bat + 1 .gitignore = 8 archivos auxiliares**

## Mejoras Implementadas 🚀

### Usabilidad
- ✅ **Columna ID visible** en todas las vistas del catálogo
- ✅ **Contador de reseñas pendientes** en menú admin
- ✅ **Eliminación por ID** con confirmación (más seguro que por nombre)
- ✅ **Orden intuitivo** al escribir reseñas (texto primero, calificación después)
- ✅ **Validación de entrada** (reseñas no vacías, calificaciones 1-5)

### Persistencia de Datos
- ✅ **Guardado automático inmediato** en todas las operaciones críticas
- ✅ **Soporte UTF-8** para caracteres especiales (ñ, acentos)
- ✅ **Uso de fgets()** en lugar de scanf() para entrada robusta

### Funcionalidades Extras
- ✅ **Búsqueda por título** (búsqueda parcial)
- ✅ **Top 10 libros** mejor calificados (ordenamiento bubble sort)
- ✅ **Estadísticas del sistema** (totales, promedios, género más popular)
- ✅ **Ver reseñas de un libro** específico

### Contenido
- ✅ **50 libros** de 12 géneros diferentes
- ✅ **150 reseñas aprobadas** (3 por cada libro)
- ✅ **Usuarios de prueba** predefinidos

## Verificación de Requisitos del Profesor ✅

### Requisitos Funcionales
| Requisito | Estado | Implementación |
|-----------|--------|----------------|
| Uso de estructuras lineales | ✅ | Lista doble, Cola FIFO, Pila LIFO, Lista simple |
| Aplicación útil y funcional | ✅ | Sistema completo de gestión de reseñas |
| Sistema de login con perfiles | ✅ | Admin y usuario con permisos diferenciados |
| Persistencia en archivos | ✅ | 4 archivos .txt con guardado automático |

### Requisitos No Funcionales
| Requisito | Estado | Implementación |
|-----------|--------|----------------|
| Implementado en ANSI C | ✅ | Compilado con gcc sin warnings |
| Uso de arreglos y apuntadores | ✅ | Arreglos de chars, apuntadores en todas las estructuras |
| Uso de estructuras | ✅ | 5 structs: Libro, Peticion, Cola, Notificacion, Usuario |
| Memoria dinámica | ✅ | malloc() y free() en todas las estructuras |
| Proyecto modular | ✅ | 30 archivos .c + 1 .h (una función por archivo) |
| main() solo llama a menú | ✅ | main.c solo tiene 3 líneas |

### Estructuras de Datos Requeridas
| Estructura | Tipo | Operaciones | Archivos |
|------------|------|-------------|----------|
| **Catálogo** | Lista Doblemente Ligada | insert, delete, show | insert_book.c, delete_book.c, show_catalog.c |
| **Reseñas Pendientes** | Cola FIFO | enqueue, dequeue | enqueue.c, dequeue.c |
| **Notificaciones** | Pila LIFO | push, pop | push_notificacion.c, pop_notificacion.c |
| **Usuarios** | Lista Simple | insert, search | registrar_usuario.c, login_usuario.c |

**Todas las estructuras usan memoria dinámica y tienen persistencia en archivos.**

## Repositorio GitHub
🔗 **https://github.com/diegoc1005/Proyecto_EDA**

El proyecto incluye:
- Código fuente completo (30 archivos .c + 1 .h)
- Documentación detallada (6 archivos .md)
- Archivos de datos de prueba (50 libros, 150 reseñas)
- Scripts de compilación
- Guías de uso y demostración

## Autores
- **Yañez Guerrero Dulce María** - No. Lista: 39
- **Diego** - No. Lista: [completar]
- **Grupo:** 07
- **Profesor:** M.C. Jorge Alberto Solano Gálvez
- **Asignatura:** Estructura De Datos y Algoritmos I
- **Semestre:** 4to Semestre

## Fecha de Entrega
📅 **30 de abril de 2026 a las 23:00 hrs**
📍 **Plataforma:** SiCCAAD

---

**Proyecto completo y listo para entregar** ✅
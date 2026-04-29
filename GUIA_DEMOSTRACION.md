# 🎬 Guía de Demostración del Proyecto
## Sistema de Gestión de Reseñas de Libros por Género

---

## 📋 PREPARACIÓN ANTES DE LA DEMOSTRACIÓN

### Compilación del Proyecto
```bash
gcc *.c -o proyecto -Wall
```

### Ejecutar el Programa
```bash
./proyecto
```
(En Windows: `proyecto.exe`)

---

## 🎭 ESCENARIO DE DEMOSTRACIÓN COMPLETA

### 🔐 CREDENCIALES DISPONIBLES

**Administrador:**
- Usuario: `admin`
- Contraseña: `estonoesunacontraseña`

**Usuarios Estándar:**
- Usuario: `diego` / Contraseña: `prueba`
- Usuario: `maria` / Contraseña: `mangos`

---

## 📖 PARTE 1: DEMOSTRACIÓN COMO ADMINISTRADOR

### 1.1 Iniciar Sesión como Admin
```
Paso 1: Ejecutar ./proyecto
Paso 2: Seleccionar opción "1" (Iniciar sesión)
Paso 3: Ingresar usuario: admin
Paso 4: Ingresar contraseña: estonoesunacontraseña
```

**Resultado esperado:** Acceso al Panel de Administrador

---

### 1.2 Ver Catálogo Completo (Opción 1)
```
Seleccionar: 1
```

**Qué mostrar al profesor:**
- Lista de 6 libros ordenados alfabéticamente
- Columnas: TITULO, AUTOR, GENERO, CALIF
- Formato de tabla bien alineado
- Calificaciones con decimales

**Explicar:**
- "Esta es una **lista doblemente ligada** que mantiene los libros ordenados alfabéticamente"
- "Cada nodo tiene apuntadores prev y nxt para navegación bidireccional"
- "La inserción es O(n) pero mantiene el orden automáticamente"

---

### 1.3 Agregar un Nuevo Libro (Opción 2)
```
Seleccionar: 2
Titulo: El Hobbit
Autor: J.R.R. Tolkien
Genero: Fantasia
```

**Qué mostrar al profesor:**
- El sistema asigna ID automáticamente (ID 7)
- Mensaje de confirmación: "Libro agregado exitosamente"
- Volver a ver catálogo (opción 1) para verificar que aparece en orden alfabético

**Explicar:**
- "El libro se inserta en la posición correcta alfabéticamente"
- "La función insert_book() recorre la lista y encuentra el lugar adecuado"
- "Se ajustan los apuntadores prev y nxt de los nodos adyacentes"

---

### 1.4 Moderar Reseñas Pendientes (Opción 3)

**IMPORTANTE:** Primero necesitas crear una reseña como usuario. 

**Salir del admin:**
```
Seleccionar: 0 (Cerrar sesión)
```

**Crear reseña como usuario:**
```
1. Seleccionar: 1 (Iniciar sesión)
2. Usuario: diego
3. Contraseña: prueba
4. Seleccionar: 2 (Escribir una reseña)
5. ID del libro: 1 (1984)
6. Calificación: 5
7. Texto: "Excelente libro, muy recomendado"
8. Seleccionar: 0 (Cerrar sesión)
```

**Volver como admin:**
```
1. Seleccionar: 1 (Iniciar sesión)
2. Usuario: admin
3. Contraseña: estonoesunacontraseña
4. Seleccionar: 3 (Moderar reseñas)
```

**Qué mostrar al profesor:**
- Se muestra la reseña más antigua de la cola (FIFO)
- Información: ID Libro, ID Usuario, Calificación, Texto
- Opciones: 1. Aprobar | 2. Rechazar

**Aprobar la reseña:**
```
Decisión: 1
```

**Explicar:**
- "Esta es una **cola (FIFO)** - First In, First Out"
- "Las reseñas se procesan en orden de llegada"
- "Al aprobar, se actualiza el promedio de calificación del libro"
- "La fórmula es: (calif_actual * num_reseñas + nueva_calif) / (num_reseñas + 1)"
- "La reseña aprobada se guarda en resenas_aprobadas.txt"

**Verificar actualización:**
```
Seleccionar: 1 (Ver catálogo)
```
- Mostrar que la calificación de "1984" cambió

---

### 1.5 Eliminar un Libro (Opción 4)
```
Seleccionar: 4
Titulo: El Hobbit
```

**Qué mostrar al profesor:**
- Mensaje de confirmación: "Libro eliminado exitosamente"
- Volver a ver catálogo para verificar que ya no aparece

**Explicar:**
- "La función delete_book() busca el libro por título"
- "Ajusta los apuntadores de los nodos adyacentes"
- "Libera la memoria del nodo eliminado con free()"
- "Maneja 3 casos: eliminar head, nodo intermedio, o último nodo"

---

## 👤 PARTE 2: DEMOSTRACIÓN COMO USUARIO

### 2.1 Cerrar Sesión de Admin
```
Seleccionar: 0
```

### 2.2 Iniciar Sesión como Usuario
```
Seleccionar: 1
Usuario: maria
Contraseña: mangos
```

---

### 2.3 Ver Catálogo (Opción 1)
```
Seleccionar: 1
```

**Explicar:**
- "Los usuarios también pueden ver el catálogo completo"
- "Misma lista doblemente ligada, acceso de solo lectura"

---

### 2.4 Escribir una Reseña (Opción 2)
```
Seleccionar: 2
ID del libro: 3 (El Principito)
Calificación: 5
Texto: "Un libro hermoso y profundo"
```

**Qué mostrar al profesor:**
- Se muestra el catálogo para elegir el libro
- Validación de ID (debe existir)
- Validación de calificación (1-5)
- Mensaje: "Tu reseña ha sido enviada y está pendiente de aprobación"
- Se crea una notificación automáticamente

**Explicar:**
- "La reseña se agrega a la **cola** con enqueue()"
- "Se inserta al final de la cola (tail)"
- "Queda pendiente hasta que el admin la apruebe"
- "Se genera una notificación en la **pila** del usuario"

---

### 2.5 Ver Notificaciones (Opción 3)
```
Seleccionar: 3
```

**Qué mostrar al profesor:**
- Aparece la notificación más reciente
- Mensaje: "Tu reseña para 'El Principito' está en revisión"
- Al verla, se elimina de la pila (pop)

**Explicar:**
- "Esta es una **pila (LIFO)** - Last In, First Out"
- "Cada usuario tiene su propia pila de notificaciones"
- "La más reciente se muestra primero"
- "Al hacer pop(), se elimina y se muestra"

**Volver a seleccionar opción 3:**
```
Seleccionar: 3
```
- Mostrar: "No tienes notificaciones nuevas"

---

### 2.6 Buscar Libros por Género (Opción 4)
```
Seleccionar: 4
Género: Ficcion
```

**Qué mostrar al profesor:**
- Se filtran solo los libros de ese género
- Formato de tabla igual al catálogo completo
- Contador: "Total: 2 libro(s) encontrado(s)"

**Probar con otro género:**
```
Seleccionar: 4
Género: Ciencia Ficcion
```

**Explicar:**
- "Recorre toda la lista doblemente ligada"
- "Compara el género de cada libro con el buscado"
- "Usa strstr() para búsqueda parcial (case-sensitive)"
- "Muestra solo los que coinciden"

---

## 💾 PARTE 3: DEMOSTRACIÓN DE PERSISTENCIA

### 3.1 Cerrar el Programa
```
Seleccionar: 0 (Cerrar sesión)
Seleccionar: 3 (Salir del sistema)
```

**Qué mostrar al profesor:**
- Mensaje: "Guardando cambios en la base de datos..."
- Mensaje: "Sistema cerrado correctamente. ¡Hasta luego!"

**Explicar:**
- "Al salir, se guardan automáticamente:"
  - libros.txt (catálogo actualizado)
  - usuarios.txt (usuarios registrados)
  - resenas_pendientes.txt (cola de reseñas)

---

### 3.2 Verificar Archivos de Datos

**Mostrar contenido de archivos:**
```bash
cat libros.txt
cat resenas_pendientes.txt
cat resenas_aprobadas.txt
```

**Explicar:**
- "Formato de texto plano separado por |"
- "Fácil de leer y editar manualmente si es necesario"
- "Cumple con el requisito de persistencia"

---

### 3.3 Reabrir el Programa
```bash
./proyecto
```

**Iniciar sesión como admin:**
```
Usuario: admin
Contraseña: estonoesunacontraseña
Seleccionar: 1 (Ver catálogo)
```

**Qué mostrar al profesor:**
- Todos los cambios persisten
- El libro eliminado sigue sin aparecer
- Las calificaciones actualizadas se mantienen
- Las reseñas pendientes siguen en la cola

**Explicar:**
- "Al iniciar, se cargan todos los datos de los archivos"
- "load_catalog() lee libros.txt y reconstruye la lista"
- "cargar_cola() reconstruye la cola de reseñas"
- "cargar_usuarios() carga todos los usuarios"

---

## 🎯 PARTE 4: PUNTOS CLAVE PARA DESTACAR

### Estructuras de Datos Implementadas

**1. Lista Doblemente Ligada (Catálogo)**
```
Ventajas:
- Inserción ordenada automática
- Navegación bidireccional
- Eliminación eficiente
```

**2. Cola FIFO (Reseñas Pendientes)**
```
Ventajas:
- Orden justo (primero en llegar, primero en atenderse)
- Operaciones O(1) con tail pointer
- Ideal para sistemas de moderación
```

**3. Pila LIFO (Notificaciones)**
```
Ventajas:
- Notificaciones más recientes primero
- Operaciones O(1)
- Cada usuario tiene su propia pila
```

**4. Lista Simple (Usuarios)**
```
Ventajas:
- Gestión de múltiples usuarios
- Cada usuario con su pila de notificaciones
- Sistema de roles (admin/user)
```

---

## 📊 ESTADÍSTICAS DEL PROYECTO

- **Total de archivos .c:** 26
- **Total de archivos .h:** 1
- **Líneas de código:** ~1,500
- **Funciones implementadas:** 30+
- **Estructuras de datos:** 4
- **Archivos de persistencia:** 4

---

## ✅ CHECKLIST DE DEMOSTRACIÓN

### Antes de Presentar:
- [ ] Compilar sin errores: `gcc *.c -o proyecto -Wall`
- [ ] Verificar que existen los archivos de datos
- [ ] Probar todas las funcionalidades una vez
- [ ] Preparar respuestas sobre estructuras de datos

### Durante la Presentación:
- [ ] Explicar el objetivo del proyecto
- [ ] Mostrar compilación
- [ ] Demostrar funciones de admin
- [ ] Demostrar funciones de usuario
- [ ] Mostrar persistencia de datos
- [ ] Explicar cada estructura de datos usada
- [ ] Responder preguntas del profesor

### Preguntas Frecuentes del Profesor:

**P: ¿Por qué usaste lista doblemente ligada?**
R: "Para mantener el catálogo ordenado alfabéticamente y permitir navegación bidireccional eficiente. Los apuntadores prev y nxt facilitan la inserción y eliminación."

**P: ¿Cómo funciona la cola?**
R: "Es FIFO - First In, First Out. Las reseñas se agregan al final (tail) y se extraen del frente (head). Esto garantiza que se procesen en orden de llegada."

**P: ¿Por qué una pila para notificaciones?**
R: "LIFO - Last In, First Out. Las notificaciones más recientes son más importantes, por eso se muestran primero. Cada usuario tiene su propia pila independiente."

**P: ¿Cómo manejas la memoria dinámica?**
R: "Uso malloc() para crear nodos y free() para liberarlos. Cada estructura (Libro, Peticion, Notificacion, Usuario) se asigna dinámicamente."

**P: ¿Cómo garantizas la persistencia?**
R: "Al cerrar el programa, todas las estructuras se guardan en archivos .txt. Al iniciar, se cargan de nuevo. Formato de texto plano separado por |."

---

## 🎬 SCRIPT DE PRESENTACIÓN (5-10 minutos)

### Introducción (1 min)
"Buenos días/tardes. Voy a presentar mi proyecto de Estructuras de Datos: un Sistema de Gestión de Reseñas de Libros. El objetivo es permitir que usuarios escriban reseñas que son moderadas por administradores antes de publicarse."

### Compilación (30 seg)
"Primero compilo el proyecto con gcc *.c -o proyecto -Wall. Como pueden ver, compila sin errores ni warnings."

### Demo Admin (3 min)
"Inicio sesión como administrador... Aquí puedo ver el catálogo completo, que es una lista doblemente ligada ordenada alfabéticamente. Voy a agregar un libro nuevo... Como ven, se inserta en la posición correcta automáticamente. Ahora voy a moderar una reseña pendiente de la cola FIFO..."

### Demo Usuario (2 min)
"Ahora como usuario estándar... Puedo ver el catálogo, escribir una reseña que va a la cola, ver mis notificaciones en la pila LIFO, y buscar libros por género..."

### Persistencia (1 min)
"Al cerrar el programa, todo se guarda en archivos de texto. Si lo vuelvo a abrir... todos los cambios persisten."

### Conclusión (1 min)
"El proyecto implementa 4 estructuras de datos: lista doble, cola, pila y lista simple. Cumple con todos los requisitos: persistencia, múltiples usuarios, modularidad, y uso de memoria dinámica. ¿Alguna pregunta?"

---

## 💡 TIPS FINALES

1. **Practica la demostración** al menos 2 veces antes
2. **Ten los archivos de datos limpios** antes de empezar
3. **Explica el 'por qué'** de cada decisión de diseño
4. **Muestra el código** si el profesor lo pide
5. **Sé honesto** si no sabes algo - mejor que inventar
6. **Mantén la calma** - tu proyecto está completo y funcional

---

¡Buena suerte con tu presentación! 🚀
# Plan de Pruebas - Sistema de Gestión de Reseñas de Libros

## Objetivo
Verificar que todas las funcionalidades del sistema funcionan correctamente y cumplen con los requisitos del proyecto.

## Credenciales de Prueba

### Administrador
- Usuario: `admin`
- Contraseña: `estonoesunacontraseña`

### Usuarios Estándar
- Usuario: `diego` / Contraseña: `prueba`
- Usuario: `maria` / Contraseña: `mangos`
- Usuario: `lector_pro` / Contraseña: `amoloslibros`
- Usuario: `juan` / Contraseña: `caballo`

## Casos de Prueba

### 1. Inicio de Sesión y Registro
- [ ] Login exitoso con usuario administrador
- [ ] Login exitoso con usuario estándar
- [ ] Login fallido con credenciales incorrectas
- [ ] Registro de nuevo usuario
- [ ] Verificar que el nuevo usuario se guarda en usuarios.txt

### 2. Funcionalidades de Administrador

#### 2.1 Ver Catálogo
- [ ] Mostrar todos los libros ordenados alfabéticamente
- [ ] Verificar que se muestran: título, autor, género y calificación
- [ ] Catálogo vacío muestra mensaje apropiado

#### 2.2 Agregar Libro
- [ ] Agregar libro con todos los campos válidos
- [ ] Verificar que el libro aparece en el catálogo
- [ ] Verificar que se asigna ID único automáticamente
- [ ] Verificar que se inserta en orden alfabético
- [ ] Verificar que se guarda en libros.txt al salir

#### 2.3 Eliminar Libro
- [ ] Eliminar libro existente por título exacto
- [ ] Intentar eliminar libro inexistente (debe fallar)
- [ ] Verificar que el libro ya no aparece en el catálogo
- [ ] Verificar que se elimina de libros.txt al salir

#### 2.4 Moderar Reseñas
- [ ] Ver reseña pendiente con todos sus datos
- [ ] Aprobar reseña y verificar actualización de calificación
- [ ] Verificar que la reseña aprobada se guarda en resenas_aprobadas.txt
- [ ] Rechazar reseña y verificar que no se guarda
- [ ] Verificar que la cola se vacía correctamente
- [ ] Mensaje apropiado cuando no hay reseñas pendientes

### 3. Funcionalidades de Usuario

#### 3.1 Ver Catálogo
- [ ] Mostrar todos los libros disponibles
- [ ] Verificar formato de tabla

#### 3.2 Escribir Reseña
- [ ] Escribir reseña para libro existente
- [ ] Calificación válida (1-5 estrellas)
- [ ] Calificación inválida rechazada (< 1 o > 5)
- [ ] ID de libro inválido rechazado
- [ ] Verificar que la reseña se agrega a la cola
- [ ] Verificar que se crea notificación para el usuario
- [ ] Verificar que se guarda en resenas_pendientes.txt

#### 3.3 Ver Notificaciones
- [ ] Ver notificación más reciente (LIFO)
- [ ] Verificar que se elimina después de verla
- [ ] Mensaje apropiado cuando no hay notificaciones

#### 3.4 Buscar por Género
- [ ] Buscar género existente (ej: "Ficcion")
- [ ] Buscar género inexistente
- [ ] Verificar que muestra solo libros del género buscado
- [ ] Verificar contador de resultados

### 4. Persistencia de Datos

#### 4.1 Archivos de Entrada
- [ ] libros.txt se carga correctamente al iniciar
- [ ] usuarios.txt se carga correctamente al iniciar
- [ ] resenas_pendientes.txt se carga correctamente al iniciar

#### 4.2 Archivos de Salida
- [ ] Cambios en libros se guardan en libros.txt al salir
- [ ] Nuevos usuarios se guardan en usuarios.txt al salir
- [ ] Reseñas pendientes se guardan en resenas_pendientes.txt al salir
- [ ] Reseñas aprobadas se guardan en resenas_aprobadas.txt

#### 4.3 Integridad de Datos
- [ ] Cerrar y reabrir: verificar que los datos persisten
- [ ] Agregar libro, cerrar, reabrir: libro sigue ahí
- [ ] Escribir reseña, cerrar, reabrir: reseña sigue en cola
- [ ] Aprobar reseña, cerrar, reabrir: calificación actualizada

### 5. Estructuras de Datos

#### 5.1 Lista Doblemente Ligada (Catálogo)
- [ ] Inserción mantiene orden alfabético
- [ ] Eliminación ajusta apuntadores correctamente
- [ ] Recorrido bidireccional funciona
- [ ] Memoria se libera correctamente

#### 5.2 Cola FIFO (Reseñas)
- [ ] Enqueue agrega al final
- [ ] Dequeue extrae del frente
- [ ] Orden FIFO se mantiene
- [ ] Cola vacía se maneja correctamente

#### 5.3 Pila LIFO (Notificaciones)
- [ ] Push agrega en la cima
- [ ] Pop extrae de la cima
- [ ] Orden LIFO se mantiene
- [ ] Pila vacía se maneja correctamente

#### 5.4 Lista Simple (Usuarios)
- [ ] Inserción de nuevos usuarios
- [ ] Búsqueda por nombre y contraseña
- [ ] Cada usuario tiene su propia pila de notificaciones

### 6. Manejo de Errores

- [ ] Entrada no numérica en menús se maneja correctamente
- [ ] Archivos inexistentes se manejan apropiadamente
- [ ] Memoria insuficiente se detecta
- [ ] Búsquedas sin resultados muestran mensaje apropiado
- [ ] Operaciones en estructuras vacías se manejan bien

### 7. Requisitos del Proyecto

#### Funcionales
- [x] Uso de pila, cola y lista
- [x] Aplicación útil y funcional
- [x] Dos perfiles de usuario (admin y user)
- [x] Persistencia en archivos de texto plano

#### No Funcionales
- [x] Implementado en ANSI C
- [x] Uso de arreglos, apuntadores, estructuras y memoria dinámica
- [x] Funciones en archivos separados
- [x] main() solo llama a menú
- [x] Estructuras con struct y memoria dinámica

## Escenario de Prueba Completo

### Flujo de Prueba Integral

1. **Iniciar como Admin**
   - Login: admin / estonoesunacontraseña
   - Ver catálogo inicial (6 libros)
   - Agregar nuevo libro: "El Hobbit" / "J.R.R. Tolkien" / "Fantasia"
   - Verificar que aparece en orden alfabético

2. **Cambiar a Usuario**
   - Cerrar sesión admin
   - Login: diego / prueba
   - Ver catálogo (7 libros ahora)
   - Buscar por género "Ficcion" (debe mostrar 2 libros)
   - Escribir reseña para "1984" con 5 estrellas

3. **Volver como Admin**
   - Cerrar sesión usuario
   - Login: admin / estonoesunacontraseña
   - Moderar reseña pendiente
   - Aprobar reseña
   - Verificar que calificación de "1984" se actualizó

4. **Verificar Persistencia**
   - Cerrar aplicación completamente
   - Reabrir aplicación
   - Login: admin / estonoesunacontraseña
   - Verificar que "El Hobbit" sigue en el catálogo
   - Verificar que calificación de "1984" se mantuvo

5. **Probar Eliminación**
   - Eliminar "El Hobbit"
   - Verificar que ya no aparece en catálogo
   - Cerrar y reabrir
   - Verificar que sigue eliminado

## Resultados Esperados

Todas las pruebas deben pasar exitosamente para considerar el proyecto completo y funcional.

## Notas

- Realizar pruebas en orden para verificar flujo completo
- Verificar archivos .txt después de cada operación importante
- Probar casos límite (estructuras vacías, entradas inválidas)
- Verificar que no hay fugas de memoria (valgrind en Linux/Mac)
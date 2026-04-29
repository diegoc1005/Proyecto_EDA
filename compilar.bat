@echo off
echo Compilando Sistema de Gestion de Resenas de Libros...
echo.

gcc -o proyecto main.c menu_principal.c menu_login.c menu_admin.c menu_usuario.c load_catalog.c insert_book.c show_catalog.c delete_book.c guardar_catalog.c enqueue.c dequeue.c guardar_cola.c cargar_cola.c push_notificacion.c pop_notificacion.c registrar_usuario.c login_usuario.c guardar_usuarios.c cargar_usuarios.c agregar_libro_admin.c moderar_resenas_admin.c eliminar_libro_admin.c escribir_resena_usuario.c ver_notificaciones_usuario.c buscar_genero_usuario.c -Wall

if %ERRORLEVEL% EQU 0 (
    echo.
    echo [OK] Compilacion exitosa!
    echo Ejecuta: proyecto.exe
) else (
    echo.
    echo [ERROR] Hubo errores en la compilacion.
)

pause

@REM Made with Bob

# 📥 Cómo Descargar el Proyecto (Para Principiantes)

## 🎯 Opción 1: Descargar ZIP (MÁS FÁCIL) ⭐

### Paso 1: Ir al repositorio
1. Abre tu navegador (Chrome, Firefox, etc.)
2. Ve a este link: **https://github.com/diegoc1005/Proyecto_EDA**

### Paso 2: Descargar
1. Busca el botón verde que dice **"Code"** (arriba a la derecha)
2. Click en **"Code"**
3. Click en **"Download ZIP"**
4. Guarda el archivo en tu computadora

### Paso 3: Descomprimir
1. Ve a la carpeta donde se descargó (probablemente "Descargas")
2. Busca el archivo **"Proyecto_EDA-main.zip"**
3. Click derecho → **"Extraer aquí"** o **"Extract here"**
4. Se creará una carpeta llamada **"Proyecto_EDA-main"**

### Paso 4: ¡Listo!
- Abre la carpeta
- Ahí están todos los archivos del proyecto
- Puedes compilar y ejecutar

---

## 🎯 Opción 2: Usar Git (Si tienes Git instalado)

### Si tienes Git:
```bash
git clone https://github.com/diegoc1005/Proyecto_EDA.git
cd Proyecto_EDA
```

### Si NO tienes Git:
- Usa la **Opción 1** (descargar ZIP) ⬆️

---

## 📂 ¿Qué archivos vas a encontrar?

Después de descargar, verás:

```
Proyecto_EDA-main/
├── 📄 README.md                    ← LEE ESTO PRIMERO
├── 📄 GUIA_DEMOSTRACION.md        ← Guía para presentar
├── 📄 PRUEBAS.md                   ← Plan de pruebas
│
├── 📁 Archivos de código (.c y .h)
│   ├── main.c
│   ├── catalogo.h
│   ├── menu_admin.c
│   ├── menu_usuario.c
│   └── ... (todos los demás .c)
│
└── 📁 Archivos de datos (.txt)
    ├── libros.txt
    ├── usuarios.txt
    └── resenas_pendientes.txt
```

---

## 🚀 Cómo Compilar y Ejecutar

### En Windows:

#### Paso 1: Abrir terminal
1. Abre la carpeta del proyecto
2. En la barra de direcciones, escribe: **cmd**
3. Presiona Enter

#### Paso 2: Compilar
```bash
gcc *.c -o proyecto -Wall
```

#### Paso 3: Ejecutar
```bash
proyecto.exe
```

---

### En Mac/Linux:

#### Paso 1: Abrir terminal
1. Abre la carpeta del proyecto
2. Click derecho → "Abrir en Terminal"

#### Paso 2: Compilar
```bash
gcc *.c -o proyecto -Wall
```

#### Paso 3: Ejecutar
```bash
./proyecto
```

---

## 🔑 Credenciales para Probar

### Administrador:
```
Usuario: admin
Contraseña: estonoesunacontraseña
```

### Usuarios:
```
diego / prueba
maria / mangos
lector_pro / amoloslibros
juan / caballo
```

---

## 📖 ¿Qué Leer Primero?

1. **README.md** - Documentación completa del proyecto
2. **GUIA_DEMOSTRACION.md** - Cómo presentar al profesor
3. **PRUEBAS.md** - Cómo probar todas las funciones

---

## ❓ Problemas Comunes

### "gcc no se reconoce como comando"
**Solución:** Necesitas instalar GCC
- Windows: https://sourceforge.net/projects/mingw/
- Mac: `xcode-select --install`
- Linux: `sudo apt-get install gcc`

### "No se puede abrir el archivo"
**Solución:** Asegúrate de estar en la carpeta correcta
```bash
cd ruta/a/Proyecto_EDA-main
```

### "Error al compilar"
**Solución:** Verifica que todos los archivos .c estén en la misma carpeta

---

## 💡 Consejos

1. **Lee el README.md primero** - Tiene toda la información
2. **Prueba compilar** antes de hacer cambios
3. **Usa las credenciales de prueba** para explorar
4. **Lee GUIA_DEMOSTRACION.md** para entender cómo funciona

---

## 📞 ¿Necesitas Ayuda?

Si tienes problemas:
1. Lee el README.md completo
2. Verifica que gcc esté instalado
3. Asegúrate de estar en la carpeta correcta
4. Contacta a Diego (tu compañero)

---

## ✅ Checklist

- [ ] Descargué el proyecto (ZIP o Git)
- [ ] Descomprimí el archivo
- [ ] Abrí la carpeta del proyecto
- [ ] Leí el README.md
- [ ] Instalé GCC (si no lo tenía)
- [ ] Compilé con: `gcc *.c -o proyecto -Wall`
- [ ] Ejecuté el programa
- [ ] Probé con las credenciales de prueba
- [ ] Leí GUIA_DEMOSTRACION.md

---

¡Listo! Ya tienes el proyecto en tu computadora. 🎉
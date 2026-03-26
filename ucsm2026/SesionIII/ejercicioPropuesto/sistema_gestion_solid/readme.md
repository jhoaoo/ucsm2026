README - Sistema de Gestión en C++

Descripción del proyecto

Este proyecto en C++ implementa un sistema básico para gestionar proyectos, comentarios y archivos. El programa está dividido en módulos y archivos separados para organizar mejor el código y aplicar principios SOLID.

Estructura del proyecto

La carpeta principal del proyecto es:

sistema_gestion_solid_cpp

Dentro de ella se encuentran los siguientes archivos y carpetas:

interfaces
- IProyecto.h
- IComentario.h
- IArchivo.h

modelos
- Proyecto.h
- Proyecto.cpp
- Comentario.h
- Comentario.cpp
- Archivo.h
- Archivo.cpp
- ArchivoPDF.h
- ArchivoPDF.cpp
- ArchivoImagen.h
- ArchivoImagen.cpp

gestores
- GestorProyectos.h
- GestorProyectos.cpp
- GestorComentarios.h
- GestorComentarios.cpp
- GestorArchivos.h
- GestorArchivos.cpp

archivo principal
- main.cpp

Qué hace el programa

El sistema permite:

- Crear proyectos con identificador y nombre
- Guardar proyectos en un gestor
- Mostrar los proyectos registrados
- Crear comentarios con identificador y texto
- Guardar comentarios en un gestor
- Mostrar los comentarios registrados
- Crear archivos de distintos tipos
- Abrir archivos según su tipo
- Guardar archivos en un gestor
- Mostrar los archivos registrados
- Usar una función general para abrir cualquier archivo compatible con la interfaz IArchivo

Módulos del sistema

Módulo Proyecto
Representa los datos de un proyecto mediante la clase Proyecto. Su interfaz es IProyecto.

Módulo Comentario
Representa los datos de un comentario mediante la clase Comentario. Su interfaz es IComentario.

Módulo Archivo
Representa archivos mediante la interfaz IArchivo, la clase base Archivo y las clases derivadas ArchivoPDF y ArchivoImagen.

Módulo Gestores
Permite almacenar y mostrar proyectos, comentarios y archivos mediante las clases GestorProyectos, GestorComentarios y GestorArchivos.

Archivo principal
El archivo main.cpp crea los objetos del sistema, agrega datos de prueba y ejecuta las funciones del programa.

Compilación

Para compilar el proyecto en C++ usando g++, se puede usar el siguiente comando:

g++ main.cpp modelos/*.cpp gestores/*.cpp -o programa

Luego, para ejecutar el programa:

./programa

Salida esperada

Al ejecutar el programa se mostrará:

- La lista de proyectos
- La lista de comentarios
- La lista de archivos
- Una prueba de apertura de archivos usando una misma función general
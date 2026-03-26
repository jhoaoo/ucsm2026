# Practica N°03 – Gestion de Objetos y Arreglos de Objetos (C++)

## Informacion General
- Curso: Laboratorio de Lenguajes de Programacion II
- Carrera: Ingenieria de Sistemas
- Alumno: Kenny Leonardo Carnero bornás
- Año: 2026

## Objetivo
El proposito principal de esta practica es implementar la gestion de multiples objetos en memoria utilizando estructuras de datos dinamicas como std::vector. Se busca dominar las operaciones de agregacion, lectura, actualizacion y eliminacion sobre colecciones de objetos, asi como establecer logica de equivalencia entre instancias mediante metodos de comparacion personalizados.

## Estructura del Proyecto
El codigo expande el modelo orientado a objetos previo, incorporando algoritmos de busqueda y manipulacion de arreglos:

- Clase Libro: Se agrego el metodo de comparacion de estado interno (esIgualA) y los metodos mutadores necesarios para la actualizacion de datos en tiempo de ejecucion.
- main.cpp: Contiene la implementacion de las funciones para administrar la lista de objetos (agregarLibro, imprimirListaLibros, actualizarGeneroLibro, eliminarLibro).

Operaciones implementadas:
1. Creacion e instanciacion: Uso de constructores para inicializar objetos Persona y Libro en el programa principal.
2. Arreglos y listas: Uso de la libreria vector para almacenar y recorrer iterativamente la coleccion de objetos instanciados.
3. Busqueda y modificacion: Algoritmos de recorrido lineal para localizar objetos por su titulo y modificar sus atributos, o removerlos de la coleccion utilizando iteradores de C++.
4. Comparacion de objetos: Evaluacion de igualdad basada en los atributos internos de las entidades (titulo y autor) en lugar de evaluar las referencias de memoria estandar.

## Compilacion y Ejecucion
Para compilar este proyecto en un entorno con el compilador GCC (g++), se deben enlazar las clases utilizadas con el archivo principal ejecutando el siguiente comando en la terminal:

g++ main.cpp Libro.cpp Persona.cpp -o practica3

Para iniciar el programa:
- En Windows: .\practica3.exe
- En Linux / macOS: ./practica3

## Reflexion Academica
Esta practica evidencia la transicion de manejar variables y objetos aislados a administrar conjuntos de datos complejos. La manipulacion de arreglos de objetos demuestra como la encapsulacion interactua directamente con las estructuras de control y los ciclos. Adicionalmente, el desarrollo de metodos de comparacion propios resalta la diferencia algoritmica entre la identidad de un objeto en memoria y su equivalencia semantica a traves de sus atributos.
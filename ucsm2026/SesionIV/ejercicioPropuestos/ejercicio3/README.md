# Sistema de Gestión Universitaria - Implementación UML en C++

Este proyecto consiste en la implementación de un sistema de gestión académica basado en un diagrama de clases UML. El software ha sido diseñado siguiendo los principios de la Programación Orientada a Objetos (POO) y la arquitectura de separación de interfaces y lógica.

---

## 1. Justificación de la Estructura de Directorios

Para garantizar la mantenibilidad y el orden del proyecto en entornos de desarrollo como VS Code, se ha optado por una estructura dividida:

* **Carpeta `include/` (.h):** Aloja los archivos de cabecera. Su función es declarar la estructura de las clases (atributos y prototipos de métodos). Esto permite que el compilador conozca la "interfaz" de los objetos antes de su implementación.
* **Carpeta `src/` (.cpp):** Contiene la definición detallada de la lógica de los métodos. Separar el código en archivos .cpp evita la redundancia y reduce los tiempos de compilación en proyectos de gran escala.
* **Raíz (`main.cpp`):** Actúa como el orquestador del sistema, donde se instancian los objetos y se ejecutan las pruebas de flujo.

---

## 2. Análisis Técnico de la Implementación

### 2.1. Aplicación de Herencia (Persona, Estudiante, Profesor)
Se ha implementado una jerarquía de clases donde **Persona** es la clase base.
* **Propósito:** Centralizar atributos comunes como `nombre` y `direccion`.
* **Uso de `protected`:** Se utiliza este modificador de acceso para que las clases derivadas (`Estudiante` y `Profesor`) puedan heredar y utilizar los atributos del padre directamente, manteniendo el encapsulamiento frente a clases externas.

### 2.2. Modelado de la Asociación (Asignatura y Profesor)
La clase **Asignatura** mantiene una relación de asociación con la clase **Profesor**.
* **Uso de Punteros:** Se emplea un puntero (`Profesor*`) para referenciar al docente encargado. Esto es fundamental para evitar la duplicación de objetos en memoria; múltiples asignaturas pueden apuntar al mismo objeto profesor, reflejando fielmente la realidad académica.

### 2.3. Resolución de Relación Muchos a Muchos (RegistroAcademico)
El sistema utiliza una **Clase de Asociación** llamada `RegistroAcademico` para vincular a un `Estudiante` con una `Asignatura`.
* **Lógica de Atributos:** Atributos como `nota` y `faltas` no pueden pertenecer a la clase Estudiante ni a la Asignatura de forma aislada, ya que dependen de la interacción entre ambos.
* **Funcionalidad:** Esta clase almacena las referencias de ambos objetos y gestiona el historial académico de forma independiente, permitiendo que un estudiante posea diversos registros para distintas materias.

---

## 3. Instrucciones de Compilación y Ejecución

Para compilar el proyecto de manera integral, asegurando que el enlazador reconozca las rutas de las cabeceras y los archivos fuente, ejecute el siguiente comando en la terminal:

```bash
g++ main.cpp src/RegistroAcademico.cpp -Iinclude -o gestion_universitaria
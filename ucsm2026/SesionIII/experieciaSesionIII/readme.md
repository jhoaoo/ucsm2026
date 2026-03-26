# PROYECTO: SISTEMA DE GESTIÓN DE TAREAS (SOLID) - UCSM

## 1. Escenario y Propósito
El presente proyecto desarrolla una aplicación de gestión de tareas escalable en C++. El sistema permite a los usuarios crear, asignar y realizar el seguimiento de progreso de tareas comunes, urgentes y de proyectos. La arquitectura se ha fragmentado en módulos independientes para garantizar un mantenimiento sencillo y una alta cohesión, cumpliendo estrictamente con los principios SOLID.

## 2. Desarrollo de Experiencias de Práctica

### Experiencia N°01: Principio de Responsabilidad Única (SRP)
Se han separado los módulos para que cada clase tenga una única razón de cambio:
* **Input (en Handlers.cpp)**: Responsabilidad exclusiva de la captura y validación de datos.
* **TaskManager (en Handlers.cpp)**: Responsabilidad única de organizar la colección de tareas.
* **Modelos de Tarea (en TaskModels.cpp)**: Responsabilidad de definir los atributos y comportamiento de cada tipo de tarea.
* **Puntaje: 2 puntos.**

### Experiencia N°02: Principio Abierto/Cerrado (OCP)
El sistema es abierto a la extensión pero cerrado a la modificación:
* Se definió la interfaz `ITask`. Para agregar la funcionalidad de "Tarea de Proyecto" (`ProjectTask`), no fue necesario modificar el código de `TaskManager` ni la interfaz original.
* **Puntaje: 2 puntos.**

### Experiencia N°03: Principio de Sustitución de Liskov (LSP)
Se garantiza la intercambiabilidad de las subclases:
* `SimpleTask`, `UrgentTask` y `ProjectTask` heredan de `ITask`. El `TaskManager` las procesa de forma uniforme mediante punteros polimórficos sin que el programa rompa su lógica.
* **Puntaje: 2 puntos.**

### Experiencia N°04: Principio de Segregación de Interfaces (ISP)
Se han fragmentado las interfaces para evitar métodos innecesarios:
* **ITask**: Interfaz para ejecución general.
* **INotifiable**: Interfaz independiente para alertas de urgencia.
* **Resultado**: Las tareas simples no implementan métodos de notificación que no usan.
* **Puntaje: 2 puntos.**

### Experiencia N°05: Principio de Inversión de Dependencia (DIP)
Los módulos de alto nivel no dependen de implementaciones concretas:
* `TaskManager` depende de la abstracción `ITask`. Las tareas concretas dependen de la misma abstracción, facilitando el intercambio de implementaciones.
* **Puntaje: 2 puntos.**

## 3. Estructura de Archivos
El proyecto se organiza en archivos `.cpp` para cumplir con la modularidad sin sobrecargar un solo archivo:
1. **Interfaces.cpp**: Contiene las definiciones de `ITask` e `INotifiable`.
2. **TaskModels.cpp**: Implementación de `SimpleTask`, `UrgentTask` y `ProjectTask`.
3. **Handlers.cpp**: Implementación de `TaskManager` e `Input`.
4. **main.cpp**: Punto de entrada que orquesta el sistema.

## 4. Manual de Funciones y Lógica de Control
* **Control de Errores**: La función `Input::getInt()` utiliza `std::cin.clear()` y `std::cin.ignore()` para gestionar entradas no numéricas, evitando bucles infinitos.
* **Gestión de Memoria**: Se implementan `std::shared_ptr` (Smart Pointers) para asegurar que los objetos se destruyan automáticamente, eliminando fugas de memoria.
* **Seguimiento**: El método `processAll()` dispara el comportamiento dinámico de cada tarea, permitiendo ver detalles y ejecuciones específicas.


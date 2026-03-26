# PROYECTO: SISTEMA DE GESTIÓN DE TAREAS (SOLID) - UCSM

## 1. Escenario de la Aplicación
Se ha desarrollado una solución en **C++** para la gestión, asignación y seguimiento de progreso de tareas. El sistema permite administrar tareas comunes, urgentes y de proyectos mediante una arquitectura modular que garantiza la escalabilidad y facilidad de mantenimiento solicitada en la práctica.

## 2. Desarrollo de las 5 Experiencias de Práctica

### PASO 1: Experiencia01Srp.cpp (Responsabilidad Única)
Se implementó la clase `ValidadorEntrada` con la única función de gestionar y limpiar el flujo de entrada de datos. 
* **Función `leerEntero`**: Utiliza `cin.clear()` y `cin.ignore()` para un **control perfecto de errores**, evitando bucles infinitos si el usuario ingresa caracteres no numéricos.
* **Resultado**: La lógica de negocio no se contamina con validaciones de interfaz.

### PASO 2: Experiencia02Ocp.cpp (Abierto/Cerrado)
Se definió la interfaz abstracta `IBaseTarea`. 
* **Lógica**: El sistema es **abierto a la extensión** (permite crear nuevos tipos de tareas como `TareaProyecto`) pero **cerrado a la modificación** (no es necesario alterar el código de la interfaz para que el sistema funcione).

### PASO 3: Experiencia03Lsp.cpp (Sustitución de Liskov)
Se crearon las clases `TareaSimple` y `TareaUrgente`.
* **Lógica**: `TareaUrgente` hereda de `TareaSimple` y respeta rigurosamente el contrato de la clase padre. El `GestorTareas` puede sustituir cualquier objeto base por uno derivado sin que la aplicación sufra inconsistencias o errores de ejecución.

### PASO 4: Experiencia04Isp.cpp (Segregación de Interfaces)
Se introdujo la interfaz específica `ISeguimientoProgreso`.
* **Lógica**: Esta interfaz solo es implementada por `TareaProyecto`. De esta forma, las tareas simples no se ven obligadas a implementar métodos de "actualización de porcentaje" que no necesitan, manteniendo interfaces concisas y específicas.

### PASO 5: Experiencia05Dip.cpp (Inversión de Dependencia)
Se implementó la clase de alto nivel `GestorTareas`.
* **Lógica**: El gestor no depende de clases concretas, sino de la abstracción `IBaseTarea`. Las tareas se inyectan mediante `std::shared_ptr`, permitiendo que cambios en los módulos de bajo nivel no afecten la lógica principal del programa.

## 3. Estructura de Archivos (CamelCase)
Para una correcta compilación en Visual Studio, asegúrese de tener estos 5 archivos en la misma carpeta:
1. `Experiencia01Srp.cpp`
2. `Experiencia02Ocp.cpp`
3. `Experiencia03Lsp.cpp`
4. `Experiencia04Isp.cpp`
5. `Experiencia05Dip.cpp` (Contiene la función `main`)

## 4. Guía de Funciones y Calidad
* **Gestión de Memoria**: Uso de Punteros Inteligentes (`shared_ptr`) para evitar fugas de memoria.
* **Escalabilidad**: El sistema permite añadir N tipos de tareas simplemente heredando de `IBaseTarea`.
* **Robustez**: Control total de excepciones en la entrada de datos del usuario.

## 5. Instrucciones de Ejecución
1. Abra su proyecto en Visual Studio.
2. Agregue los 5 archivos al Explorador de Soluciones.
3. Compile y ejecute desde `Experiencia05Dip.cpp`.

## Descripción
Este proyecto implementa un sistema de gestión para una tienda utilizando Python. El sistema permite administrar el inventario, procesar compras y generar reportes analíticos utilizando **pandas** para la estructuración de datos en tablas (`DataFrame`).


## Arquitectura del Sistema
El sistema se ha diseñado bajo un enfoque modular, dividiéndose en tres archivos clave para separar las responsabilidades:

### 1. `inventory.py`
Define la clase `Inventory`. Es el módulo encargado de la persistencia de datos.
* **Funciones:**
    * `get_df()`: Carga el inventario desde un archivo Excel (`data.xlsx`) a un DataFrame de **pandas**.
    * `save()`: Sincroniza los cambios en memoria hacia el archivo Excel.
    * **Responsabilidad:** Asegurar que los datos del catálogo de productos persistan tras cerrar el programa.

### 2. `order.py`
Define la lógica de comunicación externa y notificaciones.
* **Funciones:**
    * `enviar_correo()`: Gestiona el protocolo SMTP para enviar confirmaciones al cliente.
    * **Responsabilidad:** Manejar la comunicación cliente-servidor y la seguridad de las credenciales mediante archivos JSON.

### 3. `main.py`
Es el **módulo orquestador** (punto de entrada).
* **Funciones:**
    * Ejecuta el menú interactivo para Administrador y Cliente.
    * Coordina la lógica entre `inventory.py` (actualización de stock) y `order.py` (envío de notificaciones).
    * **Responsabilidad:** Gestionar el flujo completo de la aplicación, capturar errores de usuario (`try-except`) y presentar los reportes de inventario mediante **pandas**.

---

## Uso de Pandas
El uso de **pandas** es esencial para el manejo de los datos:
* Permite visualizar el inventario en formato de tabla limpia.
* Facilita la manipulación de filas y columnas para agregar o eliminar productos (CRUD).
* Optimiza la gestión de stock al permitir búsquedas rápidas por ID dentro del DataFrame.




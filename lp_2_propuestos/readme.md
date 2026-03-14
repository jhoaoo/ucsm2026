# Store System - Programación Orientada a Objetos

## Descripción

Este proyecto implementa un sistema de gestión para una tienda utilizando Python y el principio de **Programación Orientada a Objetos (POO)**.

El sistema administra:

* inventario de productos
* registro de ventas
* pedidos de clientes
* generación de reportes usando pandas

---

# Uso de pandas

Para la generación de reportes se utiliza la librería **pandas**, la cual permite estructurar los datos en tablas (DataFrame).
Esto facilita visualizar información de ventas e inventario de forma organizada y permite realizar cálculos como sumatorias de ventas.

---

# Arquitectura del sistema

El sistema se divide en módulos independientes. Cada módulo tiene una responsabilidad específica.

Esto se realiza para cumplir el principio de **separación de responsabilidades**.

---

# product.py

Define la clase `Producto`.

Variables utilizadas:

id_producto
Identificador único del producto dentro del inventario.

nombre
Nombre del producto.

precio
Precio unitario del producto.

stock
Cantidad disponible en inventario.

Funciones:

actualizar_stock(cantidad)
Se utiliza para aumentar el stock del producto.

reducir_stock(cantidad)
Se utiliza para disminuir el stock cuando se realiza una venta.
Se valida que la cantidad no supere el stock disponible.

---

# inventory.py

Define la clase `Inventario`.

Variable principal:

productos
Lista que almacena objetos de tipo `Producto`.

Se utiliza una lista porque el inventario es una colección dinámica de productos.

Funciones:

agregar_producto(producto)
Agrega un nuevo objeto producto al inventario.
Se valida que el ID no esté repetido para evitar duplicados.

obtener_producto(id_producto)
Busca un producto dentro de la lista utilizando su identificador.

mostrar_inventario()
Recorre la lista de productos y muestra su información.

buscar_producto(nombre)
Permite localizar productos utilizando coincidencias en el nombre.

---

# sale.py

Define la clase `Venta`.

Variables:

producto
Referencia al objeto producto que se está vendiendo.

cantidad
Cantidad de unidades vendidas.

total
Resultado de multiplicar el precio del producto por la cantidad.

Funciones:

procesar()
Se encarga de descontar el stock del producto cuando se confirma la venta.

---

# order.py

Define la clase `Pedido`.

Variables:

cliente
Nombre del cliente que realizó el pedido.

producto
Producto solicitado.

cantidad
Cantidad solicitada.

estado
Controla si el pedido está pendiente o listo.

Funciones:

marcar_listo()
Cambia el estado del pedido y ejecuta la notificación al cliente.

notificar_cliente()
Simula una notificación informando que el pedido está listo.

---

# store.py

Define la clase principal `Tienda`.

Esta clase centraliza la lógica del sistema.

Variables:

inventario
Objeto de tipo Inventario que almacena los productos.

ventas
Lista que almacena objetos Venta.

pedidos
Lista que almacena objetos Pedido.

Funciones:

registrar_producto()
Crea un nuevo producto y lo agrega al inventario.

registrar_venta()
Crea una venta y actualiza el stock del producto.

registrar_pedido()
Registra un pedido realizado por un cliente.

preparar_pedido()
Cambia el estado de un pedido a listo.

reporte_ventas()
Utiliza pandas para construir un DataFrame con las ventas registradas.

reporte_inventario()
Utiliza pandas para generar una tabla con los productos del inventario.

---

# main.py

Es el punto de entrada del sistema.

En este archivo se ejecutan pruebas del funcionamiento del sistema:

* registro de productos
* registro de ventas
* registro de pedidos
* generación de reportes
* búsqueda de productos

---

# Ejecución

Instalar dependencias:

pip install -r requirements.txt

Ejecutar sistema:

python main.py

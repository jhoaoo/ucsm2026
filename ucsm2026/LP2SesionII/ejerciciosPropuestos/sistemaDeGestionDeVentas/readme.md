# Sistema de Gestión de Pedidos y Facturación (C++)

Este sistema modular permite la administración de un inventario dinámico y la generación de facturas para clientes.

## Funcionalidades Principales
- **Gestión de Inventario**: Clasificación automática entre productos `Disponibles` y `Agotados`.
- **Sistema de Pedidos**: Validación de stock antes de procesar una compra.
- **Módulo de Facturación**: Registro histórico de todas las transacciones realizadas.
- **Extra de Creatividad**: Sistema de "ID Único" de factura y cálculo automático de IGV (Impuestos).

## Diseño de Clases
1. `Producto`: Entidad básica con atributos de precio y stock.
2. `Factura`: Almacena el detalle de la venta, cliente y monto total.
3. `Inventario`: El controlador central que gestiona las listas y la lógica de negocio.
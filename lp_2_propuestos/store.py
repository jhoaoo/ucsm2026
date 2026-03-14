import pandas as pd

from product import Producto
from inventory import Inventario
from sale import Venta
from order import Pedido


class Tienda:

    def __init__(self):

        self.inventario = Inventario()

        # lista donde se almacenan las ventas realizadas
        self.ventas = []

        # lista donde se almacenan pedidos de clientes
        self.pedidos = []

    def registrar_producto(self, id_producto, nombre, precio, stock):

        if precio <= 0 or stock < 0:
            raise ValueError("Precio o stock inválido")

        producto = Producto(id_producto, nombre, precio, stock)

        self.inventario.agregar_producto(producto)

    def registrar_venta(self, id_producto, cantidad):

        producto = self.inventario.obtener_producto(id_producto)

        if not producto:
            print("Producto no encontrado")
            return

        try:

            venta = Venta(producto, cantidad)
            venta.procesar()

            self.ventas.append(venta)

            print("Venta registrada")

        except ValueError as e:
            print(e)

    def registrar_pedido(self, cliente, id_producto, cantidad):

        producto = self.inventario.obtener_producto(id_producto)

        if not producto:
            print("Producto no encontrado")
            return

        try:

            pedido = Pedido(cliente, producto, cantidad)
            self.pedidos.append(pedido)

            print("Pedido registrado")

        except ValueError as e:
            print(e)

    def preparar_pedido(self, index):

        if index < 0 or index >= len(self.pedidos):
            print("Pedido inválido")
            return

        self.pedidos[index].marcar_listo()

    # --------------------------
    # REPORTES CON PANDAS
    # --------------------------

    def reporte_ventas(self):

        if not self.ventas:
            print("No hay ventas registradas")
            return

        datos = []

        for venta in self.ventas:

            datos.append({
                "Producto": venta.producto.nombre,
                "Cantidad": venta.cantidad,
                "Precio Unitario": venta.producto.precio,
                "Total": venta.total
            })

        df = pd.DataFrame(datos)

        print("\n--- REPORTE DE VENTAS ---")
        print(df)

        print("\nTotal vendido:", df["Total"].sum())

    def reporte_inventario(self):

        datos = []

        for producto in self.inventario.productos:

            datos.append({
                "ID": producto.id_producto,
                "Producto": producto.nombre,
                "Precio": producto.precio,
                "Stock": producto.stock
            })

        df = pd.DataFrame(datos)

        print("\n--- REPORTE INVENTARIO ---")
        print(df)
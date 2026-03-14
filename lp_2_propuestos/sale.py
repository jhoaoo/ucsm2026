class Venta:

    def __init__(self, producto, cantidad):

        if cantidad <= 0:
            raise ValueError("Cantidad inválida")

        self.producto = producto
        self.cantidad = cantidad
        self.total = producto.precio * cantidad

    def procesar(self):

        self.producto.reducir_stock(self.cantidad)

    def __str__(self):

        return f"{self.producto.nombre} x{self.cantidad} = {self.total}"
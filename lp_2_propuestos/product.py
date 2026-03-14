class Producto:

    def __init__(self, id_producto, nombre, precio, stock):
        self.id_producto = id_producto
        self.nombre = nombre
        self.precio = precio
        self.stock = stock

    def actualizar_stock(self, cantidad):
        self.stock += cantidad

    def reducir_stock(self, cantidad):

        if cantidad > self.stock:
            raise ValueError("Stock insuficiente")

        self.stock -= cantidad

    def __str__(self):

        return f"{self.id_producto} | {self.nombre} | Precio:{self.precio} | Stock:{self.stock}"
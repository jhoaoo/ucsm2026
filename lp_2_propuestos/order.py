class Pedido:

    def __init__(self, cliente, producto, cantidad):

        if cantidad <= 0:
            raise ValueError("Cantidad inválida")

        self.cliente = cliente
        self.producto = producto
        self.cantidad = cantidad
        self.estado = "Pendiente"

    def marcar_listo(self):

        self.estado = "Listo"
        self.notificar_cliente()

    def notificar_cliente(self):

        print(f"Notificación: {self.cliente}, su pedido de {self.producto.nombre} está listo")

    def __str__(self):

        return f"Cliente:{self.cliente} | Producto:{self.producto.nombre} | Cantidad:{self.cantidad} | Estado:{self.estado}"
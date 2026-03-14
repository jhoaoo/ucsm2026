class Inventario:

    def __init__(self):

        # Lista donde se almacenan objetos Producto
        self.productos = []

    def agregar_producto(self, producto):

        for p in self.productos:
            if p.id_producto == producto.id_producto:
                raise ValueError("El producto ya existe")

        self.productos.append(producto)

    def obtener_producto(self, id_producto):

        for producto in self.productos:
            if producto.id_producto == id_producto:
                return producto

        return None

    def mostrar_inventario(self):

        print("\n--- INVENTARIO ---")

        for producto in self.productos:
            print(producto)

    def buscar_producto(self, nombre):

        print("\n--- RESULTADOS DE BUSQUEDA ---")

        encontrados = []

        for producto in self.productos:

            if nombre.lower() in producto.nombre.lower():
                encontrados.append(producto)

        if not encontrados:
            print("No se encontraron productos")

        for p in encontrados:
            print(p)
from store import Tienda


def main():

    tienda = Tienda()

    try:

        tienda.registrar_producto(1, "Arroz", 4.5, 50)
        tienda.registrar_producto(2, "Azucar", 3.8, 40)
        tienda.registrar_producto(3, "Leche", 5.2, 30)

    except ValueError as e:
        print(e)

    tienda.inventario.mostrar_inventario()

    tienda.registrar_venta(1, 5)

    tienda.registrar_pedido("Juan", 2, 10)

    tienda.preparar_pedido(0)

    tienda.reporte_ventas()

    tienda.reporte_inventario()

    tienda.inventario.buscar_producto("arroz")


if __name__ == "__main__":
    main()
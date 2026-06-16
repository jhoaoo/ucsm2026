// main.cpp
#include "Inventario.h"
#include "Utilidades.h"
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::vector<Producto> inventario;
    std::set<std::string> codigos;

    int opcion;

    do {
        std::cout << "\n===== SISTEMA DE INVENTARIO STL =====\n";
        std::cout << "1. Registrar producto\n";
        std::cout << "2. Mostrar inventario completo\n";
        std::cout << "3. Buscar producto por codigo\n";
        std::cout << "4. Actualizar stock\n";
        std::cout << "5. Eliminar producto\n";
        std::cout << "6. Ordenar por descripcion\n";
        std::cout << "7. Mostrar por categoria\n";
        std::cout << "8. Mostrar productos con stock bajo\n";
        std::cout << "9. Producto con precio mas alto\n";
        std::cout << "10. Calcular valor total del inventario\n";
        std::cout << "11. Salir\n";

        opcion = leerOpcionMenu();

        switch (opcion) {
            case 1: registrarProducto(inventario, codigos); break;
            case 2: mostrarInventario(inventario); break;
            case 3: buscarProducto(inventario); break;
            case 4: actualizarStock(inventario); break;
            case 5: eliminarProducto(inventario, codigos); break;
            case 6: ordenarPorDescripcion(inventario); break;
            case 7: mostrarPorCategoria(inventario); break;
            case 8: mostrarStockBajo(inventario); break;
            case 9: mostrarProductoMayorPrecio(inventario); break;
            case 10: mostrarValorTotal(inventario); break;
            case 11: std::cout << "Programa finalizado.\n"; break;
            default: std::cout << "Opcion no valida.\n";
        }

    } while (opcion != 11);

    return 0;
}
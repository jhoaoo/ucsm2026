#include "Inventario.h"
#include "Utilidades.h"

#include <algorithm>
#include <iostream>
#include <numeric>

void registrarProducto(
    std::vector<Producto>& inventario,
    std::set<std::string>& codigos
) {
    std::string codigo = leerTextoNoVacio("Codigo: ");

    if (codigos.find(codigo) != codigos.end()) {
        std::cout << "No se puede registrar. El codigo ya existe.\n";
        return;
    }

    std::string descripcion = leerTextoNoVacio("Descripcion: ");
    std::string categoria = leerTextoNoVacio("Categoria: ");
    double precio = leerDouble("Precio unitario: ", 0.0);
    int stock = leerEntero("Stock disponible: ", 0);

    inventario.emplace_back(codigo, descripcion, categoria, precio, stock);
    codigos.insert(codigo);

    std::cout << "Producto registrado correctamente.\n";
}

void mostrarInventario(const std::vector<Producto>& inventario) {
    if (inventario.empty()) {
        std::cout << "El inventario esta vacio.\n";
        return;
    }

    std::cout << "\nINVENTARIO COMPLETO\n";

    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        it->mostrar();
    }
}

void buscarProducto(const std::vector<Producto>& inventario) {
    std::string codigo = leerTextoNoVacio("Codigo a buscar: ");

    auto it = std::find_if(
        inventario.begin(),
        inventario.end(),
        [&codigo](const Producto& producto) {
            return producto.getCodigo() == codigo;
        }
    );

    if (it != inventario.end()) {
        std::cout << "Producto encontrado:\n";
        it->mostrar();
    } else {
        std::cout << "No existe un producto con ese codigo.\n";
    }
}

void actualizarStock(std::vector<Producto>& inventario) {
    std::string codigo = leerTextoNoVacio("Codigo del producto: ");

    auto it = std::find_if(
        inventario.begin(),
        inventario.end(),
        [&codigo](const Producto& producto) {
            return producto.getCodigo() == codigo;
        }
    );

    if (it == inventario.end()) {
        std::cout << "No se puede actualizar. Producto inexistente.\n";
        return;
    }

    int nuevoStock = leerEntero("Nuevo stock: ", 0);
    it->actualizarStock(nuevoStock);

    std::cout << "Stock actualizado correctamente.\n";
}

void eliminarProducto(
    std::vector<Producto>& inventario,
    std::set<std::string>& codigos
) {
    std::string codigo = leerTextoNoVacio("Codigo del producto a eliminar: ");

    auto it = std::find_if(
        inventario.begin(),
        inventario.end(),
        [&codigo](const Producto& producto) {
            return producto.getCodigo() == codigo;
        }
    );

    if (it == inventario.end()) {
        std::cout << "No se puede eliminar. Producto inexistente.\n";
        return;
    }

    inventario.erase(
        std::remove_if(
            inventario.begin(),
            inventario.end(),
            [&codigo](const Producto& producto) {
                return producto.getCodigo() == codigo;
            }
        ),
        inventario.end()
    );

    codigos.erase(codigo);

    std::cout << "Producto eliminado correctamente.\n";
}

void ordenarPorDescripcion(std::vector<Producto>& inventario) {
    if (inventario.empty()) {
        std::cout << "No hay productos para ordenar.\n";
        return;
    }

    std::sort(
        inventario.begin(),
        inventario.end(),
        [](const Producto& a, const Producto& b) {
            return a.getDescripcion() < b.getDescripcion();
        }
    );

    std::cout << "Inventario ordenado alfabeticamente por descripcion.\n";
}

void mostrarPorCategoria(const std::vector<Producto>& inventario) {
    if (inventario.empty()) {
        std::cout << "El inventario esta vacio.\n";
        return;
    }

    std::string categoria = leerTextoNoVacio("Categoria a filtrar: ");

    int encontrados = std::count_if(
        inventario.begin(),
        inventario.end(),
        [&categoria](const Producto& producto) {
            return producto.getCategoria() == categoria;
        }
    );

    if (encontrados == 0) {
        std::cout << "No existen productos en esa categoria.\n";
        return;
    }

    std::cout << "\nPRODUCTOS DE LA CATEGORIA " << categoria << '\n';

    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (it->getCategoria() == categoria) {
            it->mostrar();
        }
    }
}

void mostrarStockBajo(const std::vector<Producto>& inventario) {
    if (inventario.empty()) {
        std::cout << "El inventario esta vacio.\n";
        return;
    }

    int limite = leerEntero("Limite maximo de stock bajo: ", 0);

    int cantidad = std::count_if(
        inventario.begin(),
        inventario.end(),
        [limite](const Producto& producto) {
            return producto.getStock() <= limite;
        }
    );

    if (cantidad == 0) {
        std::cout << "No hay productos con stock bajo.\n";
        return;
    }

    std::cout << "\nPRODUCTOS CON STOCK BAJO\n";

    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (it->getStock() <= limite) {
            it->mostrar();
        }
    }

    std::cout << "Cantidad de productos con stock bajo: "
              << cantidad << '\n';
}

void mostrarProductoMayorPrecio(const std::vector<Producto>& inventario) {
    if (inventario.empty()) {
        std::cout << "No hay productos registrados.\n";
        return;
    }

    auto it = std::max_element(
        inventario.begin(),
        inventario.end(),
        [](const Producto& a, const Producto& b) {
            return a.getPrecioUnitario() < b.getPrecioUnitario();
        }
    );

    std::cout << "Producto con precio mas alto:\n";
    it->mostrar();
}

void mostrarValorTotal(const std::vector<Producto>& inventario) {
    if (inventario.empty()) {
        std::cout << "El valor total del inventario es S/ 0.00\n";
        return;
    }

    double total = std::accumulate(
        inventario.begin(),
        inventario.end(),
        0.0,
        [](double acumulado, const Producto& producto) {
            return acumulado + producto.calcularValorParcial();
        }
    );

    std::cout << "Valor total del inventario: S/ "
              << total << '\n';
}
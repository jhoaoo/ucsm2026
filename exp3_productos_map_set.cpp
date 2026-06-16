#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>

constexpr int STOCK_MINIMO = 0;
constexpr int MENU_MINIMO = 1;
constexpr int MENU_MAXIMO = 6;

class Producto {
private:
    std::string codigo;
    std::string descripcion;
    int stock;

public:
    Producto() : codigo(""), descripcion(""), stock(0) {}

    Producto(const std::string& codigoProducto, const std::string& descripcionProducto, int stockProducto)
        : codigo(codigoProducto), descripcion(descripcionProducto), stock(stockProducto) {}

    std::string getCodigo() const { return codigo; }
    std::string getDescripcion() const { return descripcion; }
    int getStock() const { return stock; }

    bool actualizarStock(int nuevoStock) {
        if (nuevoStock < STOCK_MINIMO) {
            return false;
        }
        stock = nuevoStock;
        return true;
    }

    void mostrar() const {
        std::cout << codigo << " | " << descripcion << " | Stock: " << stock << '\n';
    }
};

bool contieneTextoReal(const std::string& texto) {
    return texto.find_first_not_of(" \t\n\r\f\v") != std::string::npos;
}

int leerEntero(const std::string& mensaje, int minimo, int maximo) {
    int valor{};
    bool valido = false;

    do {
        std::cout << mensaje;
        if (std::cin >> valor && valor >= minimo && valor <= maximo) {
            valido = true;
        } else {
            std::cout << "Entrada invalida. Ingrese un entero entre "
                      << minimo << " y " << maximo << ".\n";
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!valido);

    return valor;
}

int leerEnteroMinimo(const std::string& mensaje, int minimo) {
    int valor{};
    bool valido = false;

    do {
        std::cout << mensaje;
        if (std::cin >> valor && valor >= minimo) {
            valido = true;
        } else {
            std::cout << "Entrada invalida. Ingrese un entero mayor o igual a "
                      << minimo << ".\n";
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!valido);

    return valor;
}

std::string leerTexto(const std::string& mensaje) {
    std::string texto;
    do {
        std::cout << mensaje;
        std::getline(std::cin >> std::ws, texto);
        if (!contieneTextoReal(texto)) {
            std::cout << "El texto no puede estar vacio ni contener solo espacios.\n";
        }
    } while (!contieneTextoReal(texto));

    return texto;
}

void registrarProducto(std::map<std::string, Producto>& inventario, std::set<std::string>& codigos) {
    const std::string codigo = leerTexto("Codigo: ");
    const auto resultadoCodigo = codigos.insert(codigo);

    if (!resultadoCodigo.second) {
        std::cout << "No se puede registrar: el codigo ya existe.\n";
        return;
    }

    const std::string descripcion = leerTexto("Descripcion: ");
    const int stock = leerEnteroMinimo("Stock: ", STOCK_MINIMO);

    inventario.emplace(codigo, Producto(codigo, descripcion, stock));
    std::cout << "Producto registrado correctamente.\n";
}

void actualizarStock(std::map<std::string, Producto>& inventario) {
    if (inventario.empty()) {
        std::cout << "No hay productos registrados para actualizar.\n";
        return;
    }

    const std::string codigo = leerTexto("Codigo a actualizar: ");
    auto it = inventario.find(codigo);

    if (it == inventario.end()) {
        std::cout << "No existe un producto con ese codigo.\n";
        return;
    }

    const int nuevoStock = leerEnteroMinimo("Nuevo stock: ", STOCK_MINIMO);
    it->second.actualizarStock(nuevoStock);
    std::cout << "Stock actualizado correctamente.\n";
}

void buscarProducto(const std::map<std::string, Producto>& inventario) {
    if (inventario.empty()) {
        std::cout << "No hay productos registrados para buscar.\n";
        return;
    }

    const std::string codigo = leerTexto("Codigo a buscar: ");
    const auto it = inventario.find(codigo);

    if (it == inventario.end()) {
        std::cout << "Producto no encontrado.\n";
    } else {
        std::cout << "Producto encontrado:\n";
        it->second.mostrar();
    }
}

void mostrarProductos(const std::map<std::string, Producto>& inventario) {
    if (inventario.empty()) {
        std::cout << "No hay productos registrados.\n";
        return;
    }

    std::cout << "\nProductos ordenados por codigo:\n";
    for (const auto& registro : inventario) {
        registro.second.mostrar();
    }
}

void mostrarCodigos(const std::set<std::string>& codigos) {
    if (codigos.empty()) {
        std::cout << "No hay codigos registrados.\n";
        return;
    }

    std::cout << "\nCodigos registrados:\n";
    for (const std::string& codigo : codigos) {
        std::cout << codigo << '\n';
    }
}

void mostrarMenu() {
    std::cout << "\nMENU\n"
              << "1. Registrar producto\n"
              << "2. Actualizar stock\n"
              << "3. Buscar producto\n"
              << "4. Mostrar productos ordenados por codigo\n"
              << "5. Mostrar codigos registrados\n"
              << "6. Salir\n";
}

int main() {
    std::map<std::string, Producto> inventario;
    std::set<std::string> codigos;
    int opcion{};

    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", MENU_MINIMO, MENU_MAXIMO);

        switch (opcion) {
            case 1: registrarProducto(inventario, codigos); break;
            case 2: actualizarStock(inventario); break;
            case 3: buscarProducto(inventario); break;
            case 4: mostrarProductos(inventario); break;
            case 5: mostrarCodigos(codigos); break;
            case 6: std::cout << "Programa finalizado.\n"; break;
        }
    } while (opcion != MENU_MAXIMO);

    return 0;
}

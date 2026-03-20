#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Validacion de datos
template <typename T>
T obtenerDato(std::string mensaje) {
    T valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        } else {
            std::cout << "[ERROR] Entrada invalida. Ingrese un numero correcto.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
std::string obtenerTexto(std::string mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    while (texto.empty()) {
        std::cout << "[ERROR] El campo no puede estar vacio: ";
        std::getline(std::cin, texto);
    }
    return texto;
}

// (i) BIBLIOTECA Y LIBRO
class Libro {
private:
    std::string titulo;
    bool prestado;
public:
    Libro(std::string t) : titulo(t), prestado(false) {}
    void setPrestado(bool estado) { prestado = estado; }
    bool estaPrestado() const { return prestado; }
    std::string getTitulo() const { return titulo; }
};
class Biblioteca {
public:
    void prestarLibro(Libro &l) {
        if (l.estaPrestado()) {
            std::cout << "Error, el libro '" << l.getTitulo() << "' ya esta prestado.\n";
        } else {
            l.setPrestado(true);
            std::cout << "Prestamo exitoso. El libro '" << l.getTitulo() << "' ahora esta prestado.\n";
        }
    }
    void devolverLibro(Libro &l) {
        if (!l.estaPrestado()) {
            std::cout << "Error, el libro '" << l.getTitulo() << "' no esta prestado.\n";
        } else {
            l.setPrestado(false);
            std::cout << "Devolucion exitosa. El libro '" << l.getTitulo() << "' ha sido devuelto.\n";
        }
    }
};

// (j) FACTURA Y PRODUCTO
class Producto {
private:
    std::string nombre;
    double precio;
    int stock;
public:
    Producto(std::string n, double p, int s) : nombre(n), precio(p), stock(s) {}
    bool reducirStock(int cant) {
        if (stock >= cant) { stock -= cant; return true; }
        return false;
    }
    double getPrecio() const { return precio; }
    std::string getNombre() const { return nombre; }
    int getStock() const { return stock; }
};
class Factura {
public:
    void procesarVenta(std::vector<Producto> &productos) {
        std::string nombreProd = obtenerTexto("Ingrese el nombre del producto a comprar: ");
        Producto* prod = nullptr;
        for (auto &p : productos) {
            if (p.getNombre() == nombreProd) {
                prod = &p;
                break;
            }
        }
        if (!prod) {
            std::cout << "Error, el producto '" << nombreProd << "' no existe.\n";
            return;
        }
        int cant = obtenerDato<int>("¿Cuantos productos desea llevar?: ");
        if (cant > prod->getStock()) {
            std::cout << "Error, stock insuficiente. Solo hay " << prod->getStock() << " unidades disponibles.\n";
            return;
        }
        if (prod->reducirStock(cant)) {
            double total = (prod->getPrecio() * cant) * 1.18;
            std::cout << "Factura:\n";
            std::cout << "Producto: " << prod->getNombre() << "\n";
            std::cout << "Cantidad: " << cant << "\n";
            std::cout << "Total a pagar (con IGV): $" << total << "\n";
        }
    }
};

// (k) CARRO Y RUEDA 
class Rueda {
private:
    int tamano;
public:
    Rueda(int t = 15) : tamano(t) {}
};

class Carro {
private:
    Rueda ruedas[4];
public:
    void gestionarCambioRueda() {
        int numRueda;
        while (true) {
            numRueda = obtenerDato<int>("¿Que rueda desea cambiar? (1 - 4): ");
            if (numRueda >= 1 && numRueda <= 4) break;
            std::cout << "Error, esa rueda no existe. Intente de nuevo.\n";
        }
        std::string mov;
        while (true) {
            mov = obtenerTexto("¿El carro esta en movimiento? (si/no): ");
            if (mov == "si" || mov == "no") break;
            std::cout << "Error, respuesta invalida. Ingrese 'si' o 'no'.\n";
        }
        if (mov == "si") {
            std::cout << "Error, no se puede cambiar la rueda porque el auto esta en movimiento.\n";
        } else {
            int nuevoTam = obtenerDato<int>("Ingrese el tamano de la nueva rueda: ");
            ruedas[numRueda - 1] = Rueda(nuevoTam);
            std::cout << "Cambio exitoso - Rueda " << numRueda << " actualizada. El auto no esta en movimiento.\n";
        }
    }
};

// (l) TIENDA Y CLIENTE
class Tienda {
private:
    std::vector<Producto> productosDisponibles;
    std::vector<std::pair<std::string, int>> comprasClientes; 
public:
    Tienda() {}
    void agregarProducto(Producto p) { productosDisponibles.push_back(p); }
    bool vender(std::string nombre, int cant) {
        for (auto &p : productosDisponibles) {
            if (p.getNombre() == nombre && p.getStock() >= cant) {
                p.reducirStock(cant);
                comprasClientes.push_back({nombre, cant});
                return true;
            }
        }
        return false;
    }
    const std::vector<Producto>& getProductos() const { return productosDisponibles; }
};
class Cliente {
private:
    std::vector<std::pair<std::string, int>> listaCompras;
public:
    void agregarProducto(std::string nombre, int cant) {
        listaCompras.push_back({nombre, cant});
    }
    void pagarCuenta(Tienda &t) {
        double total = 0.0;
        for (auto &compra : listaCompras) {
            for (auto &p : t.getProductos()) {
                if (p.getNombre() == compra.first) {
                    total += p.getPrecio() * compra.second * 1.18;
                    break;
                }
            }
        }
        std::cout << "Total a pagar (con IGV): $" << total << "\n";
        listaCompras.clear();
    }
    const std::vector<std::pair<std::string, int>>& getListaCompras() const { return listaCompras; }
};

// Ingreso de datos
int main() {
    std::cout << "--- EJERCICIO I: BIBLIOTECA ---\n";
    Libro miLibro(obtenerTexto("Ingrese el nombre del libro: "));
    Biblioteca miBiblio;
    std::string accion;
    while (true) {
        accion = obtenerTexto("¿Desea prestar o devolver el libro? (prestar/devolver): ");
        if (accion == "prestar") {
            miBiblio.prestarLibro(miLibro);
            break;
        } else if (accion == "devolver") {
            miBiblio.devolverLibro(miLibro);
            break;
        } else {
            std::cout << "Respuesta incorrecta. Intente de nuevo.\n";
        }
    }

    std::cout << "\n--- EJERCICIO J: FACTURA ---\n";
    int numProd = obtenerDato<int>("¿Cuantos productos desea ingresar?: ");
    std::vector<Producto> productos;
    for (int i = 0; i < numProd; ++i) {
        std::string nP = obtenerTexto("Nombre del producto: ");
        int sP = obtenerDato<int>("Cantidad disponible: ");
        double pP = obtenerDato<double>("Precio unitario: ");
        productos.emplace_back(nP, pP, sP);
    }
    Factura miFactura;
    miFactura.procesarVenta(productos);

    std::cout << "\n--- EJERCICIO K: CARRO ---\n";
    Carro miCarro;
    miCarro.gestionarCambioRueda();

    std::cout << "\n--- EJERCICIO L: TIENDA ---\n";
    Tienda miTienda;
    int numProdTienda = obtenerDato<int>("¿Cuantos productos tiene la tienda?: ");
    for (int i = 0; i < numProdTienda; ++i) {
        std::string nP = obtenerTexto("Nombre del producto: ");
        int sP = obtenerDato<int>("Cantidad disponible: ");
        double pP = obtenerDato<double>("Precio unitario: ");
        miTienda.agregarProducto(Producto(nP, pP, sP));
    }
    Cliente miCliente;
    std::string prodComprar = obtenerTexto("¿Que producto desea comprar?: ");
    int cantComprar = obtenerDato<int>("¿Cuantas unidades?: ");
    if (miTienda.vender(prodComprar, cantComprar)) {
        miCliente.agregarProducto(prodComprar, cantComprar);
        miCliente.pagarCuenta(miTienda);
    } else {
        std::cout << "Error, no se pudo procesar la compra.\n";
    }
}
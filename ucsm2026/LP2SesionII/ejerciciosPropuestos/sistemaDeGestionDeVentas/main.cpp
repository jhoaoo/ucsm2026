#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

/**
 * @class Producto
 */
class Producto {
private:
    std::string nombre;
    int stock;
    double precio;

public:
    Producto(std::string _n, int _s, double _p) : nombre(_n), stock(_s), precio(_p) {}

    std::string getNombre() const { return nombre; }
    int getStock() const { return stock; }
    double getPrecio() const { return precio; }
    
    void reducirStock(int cantidad) { stock -= cantidad; }
    void aumentarStock(int cantidad) { stock += cantidad; }
};

/**
 * @class Factura
 */
class Factura {
private:
    int idFactura;
    std::string cliente;
    std::string productoNombre;
    int cantidad;
    double total;

public:
    Factura(int _id, std::string _c, std::string _p, int _cant, double _t) 
        : idFactura(_id), cliente(_c), productoNombre(_p), cantidad(_cant), total(_t) {}

    void imprimir() const {
        std::cout << "Factura #" << idFactura << " | Cliente: " << std::left << std::setw(10) << cliente 
                  << " | Articulo: " << std::setw(10) << productoNombre 
                  << " | Cant: " << cantidad << " | Total: $" << total << std::endl;
    }
};

/**
 * @class Inventario
 */
class Inventario {
private:
    std::vector<Producto> disponibles;
    std::vector<Producto> agotados;
    std::vector<Factura> historialFacturas;
    int contadorFacturas;

public:
    Inventario() : contadorFacturas(100) {}

    void agregarProducto(const Producto& p) {
        if (p.getStock() > 0) disponibles.push_back(p);
        else agotados.push_back(p);
    }

    /**
     * @brief Refactoriza las listas de disponibles y agotados según el stock actual.
     */
    void actualizarListas() {
        for (auto it = disponibles.begin(); it != disponibles.end(); ) {
            if (it->getStock() <= 0) {
                agotados.push_back(*it);
                it = disponibles.erase(it);
            } else { ++it; }
        }
        for (auto it = agotados.begin(); it != agotados.end(); ) {
            if (it->getStock() > 0) {
                disponibles.push_back(*it);
                it = agotados.erase(it);
            } else { ++it; }
        }
    }

    /**
     * @brief Procesa un pedido, actualiza stock y genera factura.
     */
    void realizarPedido(std::string cliente, std::string nombreProd, int cantidad) {
        bool encontrado = false;
        for (auto& p : disponibles) {
            if (p.getNombre() == nombreProd) {
                encontrado = true;
                if (p.getStock() >= cantidad) {
                    p.reducirStock(cantidad);
                    double total = p.getPrecio() * cantidad;
                    
                    // Crear y guardar factura
                    historialFacturas.push_back(Factura(++contadorFacturas, cliente, nombreProd, cantidad, total));
                    
                    std::cout << "[PEDIDO EXITOSO] Factura generada para " << cliente << ".\n";
                    actualizarListas();
                } else {
                    std::cout << "[ERROR] Stock insuficiente para " << nombreProd << ".\n";
                }
                break;
            }
        }
        if (!encontrado) std::cout << "[ERROR] El producto no existe o esta agotado.\n";
    }

    void mostrarEstado() const {
        std::cout << "\n--- INVENTARIO ACTUAL ---\n";
        for (const auto& p : disponibles) 
            std::cout << "[Disp] " << p.getNombre() << " - Stock: " << p.getStock() << "\n";
        for (const auto& p : agotados) 
            std::cout << "[Agot] " << p.getNombre() << "\n";
        
        std::cout << "\n--- HISTORIAL DE FACTURAS ---\n";
        if (historialFacturas.empty()) std::cout << "No hay ventas registradas.\n";
        for (const auto& f : historialFacturas) f.imprimir();
    }
};

int main() {
    Inventario sistema;

    // Poblar datos iniciales
    sistema.agregarProducto(Producto("Teclado", 10, 25.50));
    sistema.agregarProducto(Producto("Monitor", 2, 150.00));
    sistema.agregarProducto(Producto("Cable_HDMI", 0, 15.00));

    sistema.mostrarEstado();

    // Simular procesos
    std::cout << "\n> Procesando pedidos...\n";
    sistema.realizarPedido("Jhoao", "Teclado", 2);
    sistema.realizarPedido("Ana", "Monitor", 2); // Esto agotará el producto
    sistema.realizarPedido("Luis", "Monitor", 1); // Intentar comprar uno agotado

    sistema.mostrarEstado();

    return 0;
}
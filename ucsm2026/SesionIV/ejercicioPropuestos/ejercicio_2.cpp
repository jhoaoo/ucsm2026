#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class EntradaSegura {
public:
    static string cadena(string msg) {
        string res;
        while (true) {
            cout << msg;
            getline(cin, res);
            if (!res.empty()) return res;
            cout << "Entrada invalida." << endl;
        }
    }

    static double decimal(string msg) {
        double d;
        while (true) {
            cout << msg;
            if (cin >> d && d >= 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return d;
            }
            cout << "Error: Ingrese un precio/monto valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};

struct Producto {
    string codigo;
    string descripcion;
    double precio;
    string proveedor;
};

struct Venta {
    string factura;
    string fecha;
    double total;
};

class Cliente {
public:
    string nombre;
    vector<Venta> historial;
    
    void agregarVenta(Venta v) { historial.push_back(v); }
};

int main() {
    cout << "=== SISTEMA DE TIENDA DE ROPA ===" << endl;
    
    Cliente cliente;
    cliente.nombre = EntradaSegura::cadena("Nombre del Cliente: ");
    
    Producto prod;
    prod.codigo = EntradaSegura::cadena("Codigo del Producto: ");
    prod.descripcion = EntradaSegura::cadena("Descripcion de la prenda: ");
    prod.precio = EntradaSegura::decimal("Precio unitario: ");
    prod.proveedor = EntradaSegura::cadena("Proveedor: ");
    
    Venta nuevaVenta;
    nuevaVenta.factura = EntradaSegura::cadena("Numero de Factura: ");
    nuevaVenta.fecha = EntradaSegura::cadena("Fecha (DD/MM/AAAA): ");
    nuevaVenta.total = prod.precio; 
    
    double pagoRealizado = EntradaSegura::decimal("Monto pagado por el cliente: ");
    
    cliente.agregarVenta(nuevaVenta);
    
    cout << "\n--- COMPROBANTE REGISTRADO ---" << endl;
    cout << "Factura: " << nuevaVenta.factura << " | Cliente: " << cliente.nombre << endl;
    cout << "Producto: " << prod.descripcion << " | Total: $" << nuevaVenta.total << endl;
    cout << "Pago registrado: $" << pagoRealizado << endl;

}
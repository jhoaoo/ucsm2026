#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Validador {
public:
    static string leerTexto(string mensaje) {
        string entrada;
        while (true) {
            cout << mensaje;
            getline(cin, entrada);
            if (!entrada.empty()) return entrada;
            cout << "Error: El texto no puede estar vacio." << endl;
        }
    }

    static int leerEntero(string mensaje) {
        int numero;
        while (true) {
            cout << mensaje;
            if (cin >> numero) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return numero;
            }
            cout << "Error: Ingrese un numero entero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};

struct Autor {
    string nombre;
    string nacionalidad;
};

struct Libro {
    string isbn;
    string titulo;
    int anio;
    int ejemplares;
    Autor autor;
};

class Usuario {
public:
    string nombre;
    vector<string> librosPrestados;
    
    void registrarPrestamo(string titulo) {
        librosPrestados.push_back(titulo);
    }
};

int main() {
    cout << "=== REGISTRO DE BIBLIOTECA ===" << endl;
    
    Libro libro;
    libro.titulo = Validador::leerTexto("Ingrese Titulo del Libro: ");
    libro.isbn = Validador::leerTexto("Ingrese ISBN: ");
    libro.anio = Validador::leerEntero("Ingrese Anio de Publicacion: ");
    libro.ejemplares = Validador::leerEntero("Cantidad de ejemplares: ");
    
    libro.autor.nombre = Validador::leerTexto("Nombre del Autor: ");
    libro.autor.nacionalidad = Validador::leerTexto("Nacionalidad del Autor: ");
    
    Usuario user;
    user.nombre = Validador::leerTexto("Nombre del Usuario que solicita el prestamo: ");
    
    string fechaP = Validador::leerTexto("Fecha de Prestamo (DD/MM/AAAA): ");
    string fechaD = Validador::leerTexto("Fecha de Devolucion (DD/MM/AAAA): ");
    
    user.registrarPrestamo(libro.titulo);
    
    cout << "\n--- RESUMEN DE OPERACION ---" << endl;
    cout << "Libro: " << libro.titulo << " (" << libro.autor.nombre << ")" << endl;
    cout << "Usuario: " << user.nombre << endl;
    cout << "Estado: Prestado hasta " << fechaD << endl;
}
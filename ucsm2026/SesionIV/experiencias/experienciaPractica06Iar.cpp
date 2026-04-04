#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Procesador {
private:
    string modelo;
    int nucleos;
    float frecuenciaGHz;
    bool activo;

public:
    Procesador(const string& modelo, int nucleos, float frecuenciaGHz)
        : modelo(modelo), nucleos(nucleos), frecuenciaGHz(frecuenciaGHz), activo(true) {
        if (modelo.empty()) {
            throw invalid_argument("El modelo del procesador no puede estar vacio.");
        }
        if (nucleos <= 0) {
            throw invalid_argument("La cantidad de nucleos debe ser mayor que cero.");
        }
        if (frecuenciaGHz <= 0) {
            throw invalid_argument("La frecuencia debe ser mayor que cero.");
        }
    }

    string getModelo() const {
        return modelo;
    }

    int getNucleos() const {
        return nucleos;
    }

    float getFrecuenciaGHz() const {
        return frecuenciaGHz;
    }

    bool estaActivo() const {
        return activo;
    }

    void setModelo(const string& nuevoModelo) {
        if (nuevoModelo.empty()) {
            throw invalid_argument("El nuevo modelo no puede estar vacio.");
        }
        modelo = nuevoModelo;
    }

    void setNucleos(int nuevosNucleos) {
        if (nuevosNucleos <= 0) {
            throw invalid_argument("Los nucleos deben ser mayores que cero.");
        }
        nucleos = nuevosNucleos;
    }

    void setFrecuenciaGHz(float nuevaFrecuencia) {
        if (nuevaFrecuencia <= 0) {
            throw invalid_argument("La frecuencia debe ser mayor que cero.");
        }
        frecuenciaGHz = nuevaFrecuencia;
    }

    void desactivar() {
        activo = false;
    }

    void mostrarInfo() const {
        cout << "Procesador: " << modelo << endl;
        cout << "Nucleos: " << nucleos << endl;
        cout << "Frecuencia: " << frecuenciaGHz << " GHz" << endl;
        cout << "Estado: " << (activo ? "Activo" : "Desactivado") << endl;
    }
};

class Computadora {
private:
    string marca;
    string codigoInventario;
    Procesador* procesador;

public:
    Computadora(const string& marca, const string& codigoInventario, const Procesador& procesadorBase)
        : marca(marca), codigoInventario(codigoInventario) {
        if (marca.empty()) {
            throw invalid_argument("La marca no puede estar vacia.");
        }
        if (codigoInventario.empty()) {
            throw invalid_argument("El codigo de inventario no puede estar vacio.");
        }
        procesador = new Procesador(procesadorBase);
    }

    ~Computadora() {
        delete procesador;
        procesador = nullptr;
        cout << "La computadora y su procesador han sido destruidos correctamente." << endl;
    }

    string getMarca() const {
        return marca;
    }

    string getCodigoInventario() const {
        return codigoInventario;
    }

    Procesador& getProcesador() {
        if (procesador == nullptr) {
            throw runtime_error("No existe un procesador asociado.");
        }
        return *procesador;
    }

    void eliminarProcesador() {
        if (procesador != nullptr) {
            delete procesador;
            procesador = nullptr;
        }
    }

    bool tieneProcesador() const {
        return procesador != nullptr;
    }

    void mostrarInfoCompleta() const {
        cout << "===== DATOS DE LA COMPUTADORA =====" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Codigo de inventario: " << codigoInventario << endl;
        if (procesador != nullptr) {
            procesador->mostrarInfo();
        } else {
            cout << "Procesador: eliminado" << endl;
        }
        cout << endl;
    }
};

int main() {
    try {
        Procesador procesadorInicial("Intel Core i7-12700H", 14, 2.30f);
        Computadora pc("Lenovo", "PC-2026-001", procesadorInicial);

        cout << "1. Estado inicial del objeto compuesto" << endl;
        pc.mostrarInfoCompleta();

        cout << "2. Accediendo al objeto compuesto mediante getProcesador()" << endl;
        pc.getProcesador().mostrarInfo();
        cout << endl;

        cout << "3. Modificando el objeto compuesto" << endl;
        pc.getProcesador().setModelo("Intel Core i9-13900H");
        pc.getProcesador().setNucleos(14);
        pc.getProcesador().setFrecuenciaGHz(2.60f);
        pc.mostrarInfoCompleta();

        cout << "4. Desactivando el procesador" << endl;
        pc.getProcesador().desactivar();
        pc.mostrarInfoCompleta();

        cout << "5. Eliminando el objeto compuesto" << endl;
        pc.eliminarProcesador();
        pc.mostrarInfoCompleta();
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
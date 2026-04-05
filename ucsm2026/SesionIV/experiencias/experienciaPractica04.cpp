#include <iostream>
#include <vector>
#include <string>

using namespace std;

// b) Constante para el tamaño máximo
const int MAX_TRABAJADORES = 10;

// a) Clase Trabajador
class Trabajador {
protected:
    string nombre;
    Trabajador* compañeros[MAX_TRABAJADORES]; // d) Asociación reflexiva
    int numCompañeros;

public:
    Trabajador(string _nombre) : nombre(_nombre), numCompañeros(0) {}

    string getNombre() { return nombre; }

    // d) Método para establecer la asociación reflexiva
    void agregarCompanero(Trabajador* t) {
        if (numCompañeros < MAX_TRABAJADORES) {
            compañeros[numCompañeros++] = t;
        }
    }

    // f) Obtener información sobre las relaciones
    void mostrarRelaciones() {
        cout << "Trabajador: " << nombre << " tiene como compañeros a: ";
        if (numCompañeros == 0) cout << "Ninguno";
        for (int i = 0; i < numCompañeros; i++) {
            cout << compañeros[i]->getNombre() << " ";
        }
        cout << endl;
    }
};

// a) Clase Gerente que hereda de Trabajador
class Gerente : public Trabajador {
private:
    vector<Trabajador*> subordinados; // Atributo para trabajadores a su cargo

public:
    Gerente(string _nombre) : Trabajador(_nombre) {}

    void asignarSubordinado(Trabajador* t) {
        subordinados.push_back(t);
    }

    void mostrarEquipo() {
        cout << "Gerente " << nombre << " tiene a cargo a: ";
        for (auto s : subordinados) {
            cout << s->getNombre() << " ";
        }
        cout << endl;
    }
};

int main_practica4() {
    // c) Crear instancias
    Gerente* jefe = new Gerente("Sebastian");
    Trabajador* t1 = new Trabajador("Jhoan");
    Trabajador* t2 = new Trabajador("Carlos");

    jefe->asignarSubordinado(t1);
    jefe->asignarSubordinado(t2);

    // e) Establecer relaciones entre trabajadores del mismo gerente
    t1->agregarCompanero(t2);
    t2->agregarCompanero(t1);

    // f) Mostrar resultados
    jefe->mostrarEquipo();
    t1->mostrarRelaciones();
    t2->mostrarRelaciones();

    return 0;
}
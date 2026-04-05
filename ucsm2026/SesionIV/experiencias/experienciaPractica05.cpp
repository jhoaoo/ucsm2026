#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// b) Clase de los objetos que se agregarán (Parte)
class Estudiante {
private:
    int id;
    string nombre;

public:
    Estudiante(int _id, string _nom) : id(_id), nombre(_nom) {}
    int getId() const { return id; }
    string getNombre() const { return nombre; }
    void setNombre(string n) { nombre = n; }
};

// a) Clase base que representa la entidad principal (Todo)
class Universidad {
private:
    string nombre;
    vector<Estudiante*> estudiantes; // Colección de objetos agregados

public:
    Universidad(string _nom) : nombre(_nom) {}

    // c) Método para agregar
    void agregarEstudiante(Estudiante* e) {
        estudiantes.push_back(e);
    }

    // d) Método para eliminar por puntero/referencia
    void eliminarEstudiante(int id) {
        auto it = std::remove_if(estudiantes.begin(), estudiantes.end(), 
            [id](Estudiante* e) { return e->getId() == id; });
        
        if (it != estudiantes.end()) {
            estudiantes.erase(it, estudiantes.end());
            cout << "Estudiante con ID " << id << " eliminado.\n";
        }
    }

    // e) Método para obtener un objeto específico
    Estudiante* obtenerEstudiante(int id) {
        for (auto e : estudiantes) {
            if (e->getId() == id) return e;
        }
        return nullptr;
    }

    void listarEstudiantes() {
        cout << "Lista de la Universidad " << nombre << ":\n";
        for (auto e : estudiantes) {
            cout << "- ID: " << e->getId() << " | Nombre: " << e->getNombre() << endl;
        }
    }
};

int main() {
    // f) Crear objeto base y objetos a agregar
    Universidad* ucsm = new Universidad("UCSM");
    Estudiante* e1 = new Estudiante(101, "Ana");
    Estudiante* e2 = new Estudiante(102, "Luis");
    Estudiante* e3 = new Estudiante(103, "Pedro");

    // g) Agregar objetos
    ucsm->agregarEstudiante(e1);
    ucsm->agregarEstudiante(e2);
    ucsm->agregarEstudiante(e3);

    // h) Acceder a los objetos
    ucsm->listarEstudiantes();

    // i) Modificar y eliminar
    Estudiante* encontrado = ucsm->obtenerEstudiante(102);
    if (encontrado) {
        encontrado->setNombre("Luis Alberto"); // Modificación
        cout << "\nNombre modificado del ID 102.\n";
    }

    ucsm->eliminarEstudiante(101); // Eliminación

    cout << "\nEstado final de la coleccion:\n";
    ucsm->listarEstudiantes();

    return 0;
}
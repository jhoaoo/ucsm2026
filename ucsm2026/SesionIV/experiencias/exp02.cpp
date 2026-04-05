#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Curso;

class Estudiante {
private:
    string nombre;
    string apellido;
    string identificacion;
    string correo;
    vector<Curso*> cursos;

public:
    Estudiante(string nom, string ape, string id, string email) {
        nombre = nom;
        apellido = ape;
        identificacion = id;
        correo = email;
    }

    string getNombre() {
        return nombre + " " + apellido;
    }

    string getId() {
        return identificacion;
    }

    void agregarCurso(Curso* c) {
        if (find(cursos.begin(), cursos.end(), c) == cursos.end()) {
            cursos.push_back(c);
        }
    }

    void eliminarCurso(Curso* c) {
        auto it = find(cursos.begin(), cursos.end(), c);
        if (it != cursos.end()) {
            cursos.erase(it);
        }
    }

    void imprimirCursos(); 
};

class Curso {
private:
    string nombre;
    string codigo;
    string descripcion;
    string fechaInicio;
    string fechaFin;
    vector<Estudiante*> estudiantes;

public:
    Curso(string nom, string cod, string desc, string fInicio, string fFin) {
        nombre = nom;
        codigo = cod;
        descripcion = desc;
        fechaInicio = fInicio;
        fechaFin = fFin;
    }

    string getNombre() {
        return nombre;
    }

    string getCodigo() {
        return codigo;
    }

    void agregarEstudiante(Estudiante* e) {
        if (find(estudiantes.begin(), estudiantes.end(), e) == estudiantes.end()) {
            estudiantes.push_back(e);
        }
    }

    void eliminarEstudiante(Estudiante* e) {
        auto it = find(estudiantes.begin(), estudiantes.end(), e);
        if (it != estudiantes.end()) {
            estudiantes.erase(it);
        }
    }

    void imprimirEstudiantes() {
        cout << "Curso: " << nombre << " [" << codigo << "]\n";
        for (auto e : estudiantes) {
            cout << "  - " << e->getNombre() << " (ID: " << e->getId() << ")\n";
        }
        cout << "\n";
    }
};

void Estudiante::imprimirCursos() {
    cout << "Estudiante: " << getNombre() << " (ID: " << identificacion << ")\n";
    for (auto c : cursos) {
        cout << "  - " << c->getNombre() << " [" << c->getCodigo() << "]\n";
    }
    cout << "\n";
}

int main() {
    Estudiante e1("Ana", "Gomez", "1001", "ana@email.com");
    Estudiante e2("Luis", "Perez", "1002", "luis@email.com");
    Estudiante e3("Maria", "Lopez", "1003", "maria@email.com");

    Curso c1("Programacion en C++", "CS101", "Intro a C++", "01/04", "30/07");
    Curso c2("Estructuras de Datos", "CS201", "Listas y arboles", "01/04", "30/07");

    e1.agregarCurso(&c1);
    c1.agregarEstudiante(&e1);

    e1.agregarCurso(&c2);
    c2.agregarEstudiante(&e1);

    e2.agregarCurso(&c1);
    c1.agregarEstudiante(&e2);

    e3.agregarCurso(&c2);
    c2.agregarEstudiante(&e3);

    e1.eliminarCurso(&c2);
    c2.eliminarEstudiante(&e1);

    c1.imprimirEstudiantes();
    c2.imprimirEstudiantes();

    e1.imprimirCursos();
    e2.imprimirCursos();
    e3.imprimirCursos();

    return 0;
}
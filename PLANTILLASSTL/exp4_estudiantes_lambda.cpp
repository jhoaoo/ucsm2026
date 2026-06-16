#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

constexpr int CODIGO_MINIMO = 1;
constexpr int CICLO_MINIMO = 1;
constexpr double PROMEDIO_APROBATORIO = 11.0;

class Estudiante {
private:
    int codigo;
    std::string nombre;
    double promedio;
    int ciclo;

public:
    Estudiante(int codigoEstudiante, const std::string& nombreEstudiante, double promedioEstudiante, int cicloEstudiante)
        : codigo(codigoEstudiante), nombre(nombreEstudiante), promedio(promedioEstudiante), ciclo(cicloEstudiante) {}

    int getCodigo() const { return codigo; }
    std::string getNombre() const { return nombre; }
    double getPromedio() const { return promedio; }
    int getCiclo() const { return ciclo; }

    void mostrar() const {
        std::cout << codigo << " | " << nombre
                  << " | Promedio: " << promedio
                  << " | Ciclo: " << ciclo << '\n';
    }
};

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

void mostrarEstudiantes(const std::vector<Estudiante>& estudiantes, const std::string& titulo) {
    std::cout << "\n" << titulo << "\n";
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes registrados.\n";
        return;
    }

    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        it->mostrar();
    }
}

int main() {
    std::vector<Estudiante> estudiantes{
        Estudiante(1001, "Ana Torres", 17.5, 1),
        Estudiante(1002, "Luis Ramos", 10.8, 2),
        Estudiante(1003, "Maria Flores", 18.2, 1),
        Estudiante(1004, "Carlos Diaz", 13.4, 3),
        Estudiante(1005, "Sofia Medina", 9.6, 2),
        Estudiante(1006, "Jorge Salas", 15.1, 3)
    };

    mostrarEstudiantes(estudiantes, "Listado completo de estudiantes");

    std::sort(
        estudiantes.begin(),
        estudiantes.end(),
        [](const Estudiante& a, const Estudiante& b) {
            return a.getNombre() < b.getNombre();
        }
    );
    mostrarEstudiantes(estudiantes, "Listado ordenado alfabeticamente por nombre");

    const int codigoBuscado = leerEnteroMinimo("Codigo a buscar: ", CODIGO_MINIMO);
    const auto encontrado = std::find_if(
        estudiantes.begin(),
        estudiantes.end(),
        [codigoBuscado](const Estudiante& estudiante) {
            return estudiante.getCodigo() == codigoBuscado;
        }
    );

    if (encontrado != estudiantes.end()) {
        std::cout << "Estudiante encontrado:\n";
        encontrado->mostrar();
    } else {
        std::cout << "No existe un estudiante con ese codigo.\n";
    }

    const auto aprobados = std::count_if(
        estudiantes.begin(),
        estudiantes.end(),
        [](const Estudiante& estudiante) {
            return estudiante.getPromedio() >= PROMEDIO_APROBATORIO;
        }
    );
    std::cout << "Cantidad de estudiantes aprobados: " << aprobados << '\n';

    const int cicloBuscado = leerEnteroMinimo("Ciclo academico a filtrar: ", CICLO_MINIMO);
    const auto cantidadCiclo = std::count_if(
        estudiantes.begin(),
        estudiantes.end(),
        [cicloBuscado](const Estudiante& estudiante) {
            return estudiante.getCiclo() == cicloBuscado;
        }
    );

    if (cantidadCiclo == 0) {
        std::cout << "No hay estudiantes registrados en ese ciclo.\n";
    } else {
        std::cout << "Estudiantes del ciclo " << cicloBuscado << ":\n";
        std::for_each(
            estudiantes.begin(),
            estudiantes.end(),
            [cicloBuscado](const Estudiante& estudiante) {
                if (estudiante.getCiclo() == cicloBuscado) {
                    estudiante.mostrar();
                }
            }
        );
    }

    const auto mejor = std::max_element(
        estudiantes.begin(),
        estudiantes.end(),
        [](const Estudiante& a, const Estudiante& b) {
            return a.getPromedio() < b.getPromedio();
        }
    );

    if (mejor != estudiantes.end()) {
        std::cout << "Estudiante con promedio mas alto:\n";
        mejor->mostrar();
    }

    return 0;
}

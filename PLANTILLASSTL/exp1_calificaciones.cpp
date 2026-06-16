#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

constexpr int NOTA_MINIMA = 0;
constexpr int NOTA_MAXIMA = 20;
constexpr int NOTA_APROBATORIA = 11;
constexpr int NOTA_ELIMINACION = 6;
constexpr int CANTIDAD_MINIMA = 1;
constexpr int CANTIDAD_MAXIMA = 1000;

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

void mostrarCalificaciones(const std::vector<int>& calificaciones, const std::string& titulo) {
    std::cout << "\n" << titulo << ": ";
    if (calificaciones.empty()) {
        std::cout << "[sin calificaciones]";
    } else {
        for (auto it = calificaciones.begin(); it != calificaciones.end(); ++it) {
            std::cout << *it << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    const int cantidad = leerEntero(
        "Cantidad de calificaciones a registrar: ",
        CANTIDAD_MINIMA,
        CANTIDAD_MAXIMA
    );

    std::vector<int> calificaciones;
    calificaciones.reserve(static_cast<std::size_t>(cantidad));

    for (int i = 0; i < cantidad; ++i) {
        const int nota = leerEntero(
            "Ingrese calificacion " + std::to_string(i + 1) + " [0-20]: ",
            NOTA_MINIMA,
            NOTA_MAXIMA
        );
        calificaciones.push_back(nota);
    }

    mostrarCalificaciones(calificaciones, "Calificaciones registradas");

    const int suma = std::accumulate(calificaciones.begin(), calificaciones.end(), 0);
    const double promedio = static_cast<double>(suma) / static_cast<double>(calificaciones.size());
    const auto minimoMaximo = std::minmax_element(calificaciones.begin(), calificaciones.end());
    const auto aprobatorias = std::count_if(
        calificaciones.begin(),
        calificaciones.end(),
        [](int nota) { return nota >= NOTA_APROBATORIA; }
    );

    std::cout << "Suma: " << suma << '\n';
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Promedio: " << promedio << '\n';
    std::cout << "Minima: " << *minimoMaximo.first << '\n';
    std::cout << "Maxima: " << *minimoMaximo.second << '\n';
    std::cout << "Cantidad de aprobatorias: " << aprobatorias << '\n';

    std::sort(calificaciones.begin(), calificaciones.end());
    mostrarCalificaciones(calificaciones, "Calificaciones ordenadas ascendentemente");

    calificaciones.erase(
        std::remove_if(
            calificaciones.begin(),
            calificaciones.end(),
            [](int nota) { return nota < NOTA_ELIMINACION; }
        ),
        calificaciones.end()
    );

    mostrarCalificaciones(calificaciones, "Contenido final del vector");
    return 0;
}

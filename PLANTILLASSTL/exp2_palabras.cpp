#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <list>
#include <string>

constexpr int CANTIDAD_MINIMA = 1;
constexpr int CANTIDAD_MAXIMA = 1000;

bool contieneTextoReal(const std::string& texto) {
    return texto.find_first_not_of(" \t\n\r\f\v") != std::string::npos;
}

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

std::string leerPalabra(const std::string& mensaje) {
    std::string palabra;
    do {
        std::cout << mensaje;
        std::getline(std::cin >> std::ws, palabra);
        if (!contieneTextoReal(palabra)) {
            std::cout << "La palabra no puede estar vacia ni contener solo espacios.\n";
        }
    } while (!contieneTextoReal(palabra));

    return palabra;
}

void mostrarDirecto(const std::list<std::string>& palabras, const std::string& titulo) {
    std::cout << "\n" << titulo << "\n";
    for (auto it = palabras.begin(); it != palabras.end(); ++it) {
        std::cout << *it << '\n';
    }
}

void mostrarInverso(const std::list<std::string>& palabras, const std::string& titulo) {
    std::cout << "\n" << titulo << "\n";
    for (auto it = palabras.rbegin(); it != palabras.rend(); ++it) {
        std::cout << *it << '\n';
    }
}

std::string convertirMayusculas(std::string palabra) {
    std::transform(
        palabra.begin(),
        palabra.end(),
        palabra.begin(),
        [](unsigned char caracter) { return static_cast<char>(std::toupper(caracter)); }
    );
    return palabra;
}

int main() {
    const int cantidad = leerEntero(
        "Cantidad de palabras a registrar: ",
        CANTIDAD_MINIMA,
        CANTIDAD_MAXIMA
    );

    std::list<std::string> palabras;

    for (int i = 0; i < cantidad; ++i) {
        palabras.push_back(leerPalabra("Ingrese palabra " + std::to_string(i + 1) + ": "));
    }

    mostrarDirecto(palabras, "Palabras registradas mediante iteradores directos:");

    palabras.sort();
    mostrarDirecto(palabras, "Palabras ordenadas alfabeticamente con list::sort():");

    const std::string buscada = leerPalabra("Palabra a contar: ");
    const auto apariciones = std::count(palabras.begin(), palabras.end(), buscada);
    std::cout << "La palabra \"" << buscada << "\" aparece "
              << apariciones << " vez/veces.\n";

    std::transform(
        palabras.begin(),
        palabras.end(),
        palabras.begin(),
        [](const std::string& palabra) { return convertirMayusculas(palabra); }
    );

    mostrarInverso(palabras, "Contenido final en mayusculas y orden inverso:");
    return 0;
}

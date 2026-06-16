// Utilidades.cpp
#include "Utilidades.h"
#include <iostream>
#include <limits>

int leerEntero(const std::string& mensaje, int minimo) {
    int valor;

    while (true) {
        std::cout << mensaje;

        if (std::cin >> valor && valor >= minimo) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }

        std::cout << "Entrada invalida. Intente nuevamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double leerDouble(const std::string& mensaje, double minimo) {
    double valor;

    while (true) {
        std::cout << mensaje;

        if (std::cin >> valor && valor > minimo) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }

        std::cout << "Entrada invalida. Intente nuevamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string leerTextoNoVacio(const std::string& mensaje) {
    std::string texto;

    do {
        std::cout << mensaje;
        std::getline(std::cin, texto);

        if (texto.empty()) {
            std::cout << "El texto no puede estar vacio.\n";
        }
    } while (texto.empty());

    return texto;
}

int leerOpcionMenu() {
    return leerEntero("Seleccione una opcion: ", 1);
}
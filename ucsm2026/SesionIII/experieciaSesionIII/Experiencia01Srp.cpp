#include <iostream>
#include <string>
#include <limits>

#ifndef EXPERIENCIA_01_SRP_CPP
#define EXPERIENCIA_01_SRP_CPP

// Clase encargada UNICAMENTE de la validacion de entrada de datos (Evita errores de flujo)
class ValidadorEntrada {
public:
    static int leerEntero(std::string mensaje) {
        int valor;
        while (true) {
            std::cout << mensaje;
            if (std::cin >> valor) return valor;
            std::cout << "Error: Ingrese un numero entero valido." << std::endl;
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        }
    }

    static std::string leerCadena(std::string mensaje) {
        std::string texto;
        std::cout << mensaje;
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        std::getline(std::cin, texto);
        return texto;
    }
};

#endif
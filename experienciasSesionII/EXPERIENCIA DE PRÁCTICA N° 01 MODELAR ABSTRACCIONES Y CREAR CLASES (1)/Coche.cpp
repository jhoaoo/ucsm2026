#include "Coche.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Coche::Coche(string m, int a) {
    if (a < 1900) throw invalid_argument("Año invalido");
    modelo = m;
    anio = a;
    velocidad = 0;
}

void Coche::acelerar(float v) {
    velocidad += v;
    cout << "Velocidad: " << velocidad << endl;
}

void Coche::frenar(float v) {
    velocidad -= v;
    if (velocidad < 0) velocidad = 0;
    cout << "Velocidad: " << velocidad << endl;
}

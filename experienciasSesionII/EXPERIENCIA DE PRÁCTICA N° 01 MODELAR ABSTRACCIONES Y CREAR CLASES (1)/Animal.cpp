#include "Animal.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Animal::Animal(string n, int e, string t) {
    if (e < 0) throw invalid_argument("Edad invalida");
    nombre = n;
    edad = e;
    tipo = t;
}

void Animal::alimentar() {
    cout << nombre << " esta siendo alimentado\n";
}

void Animal::hacerSonido() {
    if (tipo == "perro") cout << nombre << " dice: Guau!\n";
    else if (tipo == "gato") cout << nombre << " dice: Miau!\n";
    else cout << nombre << " hace un sonido\n";
}

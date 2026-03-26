#include <iostream>
#include "Animal.h"
#include "Coche.h"

using namespace std;

int main() {
    try {
        Animal a("Firulais", 3, "perro");
        a.alimentar();
        a.hacerSonido();

        Coche c("Toyota", 2020);
        c.acelerar(50);
        c.frenar(20);

    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

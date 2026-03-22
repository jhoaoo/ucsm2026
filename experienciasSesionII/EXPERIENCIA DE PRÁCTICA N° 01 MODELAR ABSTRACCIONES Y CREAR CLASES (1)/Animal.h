#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std;

class Animal {
private:
    string nombre;
    int edad;
    string tipo;

public:
    Animal(string n, int e, string t);
    void alimentar();
    void hacerSonido();
};

#endif

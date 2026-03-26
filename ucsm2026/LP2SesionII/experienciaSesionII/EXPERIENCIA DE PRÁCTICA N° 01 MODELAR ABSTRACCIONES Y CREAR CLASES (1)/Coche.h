#ifndef COCHE_H
#define COCHE_H
#include <string>
using namespace std;

class Coche {
private:
    string modelo;
    int anio;
    float velocidad;

public:
    Coche(string m, int a);
    void acelerar(float v);
    void frenar(float v);
};

#endif

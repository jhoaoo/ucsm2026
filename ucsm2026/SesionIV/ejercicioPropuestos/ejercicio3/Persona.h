#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona {
protected:
    std::string nombre;
    std::string direccion;
public:
    Persona(std::string n, std::string d) : nombre(n), direccion(d) {}
    virtual ~Persona() {}
    std::string getNombre() const { return nombre; }
};
#endif
#ifndef PROFESOR_H
#define PROFESOR_H
#include "Persona.h"

class Profesor : public Persona {
private:
    std::string numeroTelefono;
public:
    Profesor(std::string n, std::string d, std::string t) 
        : Persona(n, d), numeroTelefono(t) {}
};
#endif
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Persona.h"

class Estudiante : public Persona {
private:
    std::string numeroMatricula;
public:
    Estudiante(std::string n, std::string d, std::string m) 
        : Persona(n, d), numeroMatricula(m) {}
    
    std::string getMatricula() const { return numeroMatricula; }
};
#endif
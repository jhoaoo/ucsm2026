#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include <string>
#include "Profesor.h"

class Asignatura {
private:
    std::string codigo;
    std::string nombre;
    std::string descripcion;
    Profesor* profesorAsignado;
public:
    Asignatura(std::string c, std::string n, std::string d, Profesor* p = nullptr) 
        : codigo(c), nombre(n), descripcion(d), profesorAsignado(p) {}
    
    std::string getNombre() const { return nombre; }
};
#endif
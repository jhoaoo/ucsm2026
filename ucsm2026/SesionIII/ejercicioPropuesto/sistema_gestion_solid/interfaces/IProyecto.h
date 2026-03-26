#ifndef IPROYECTO_H
#define IPROYECTO_H

#include <string>
using namespace std;

class IProyecto {
public:
    virtual int obtenerId() = 0;
    virtual string obtenerNombre() = 0;
    virtual ~IProyecto() {}
};

#endif
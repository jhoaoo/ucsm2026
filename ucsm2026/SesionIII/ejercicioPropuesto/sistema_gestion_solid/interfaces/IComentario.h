#ifndef ICOMENTARIO_H
#define ICOMENTARIO_H

#include <string>
using namespace std;

class IComentario {
public:
    virtual int obtenerId() = 0;
    virtual string obtenerTexto() = 0;
    virtual ~IComentario() {}
};

#endif
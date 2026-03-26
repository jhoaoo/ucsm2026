#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include "../interfaces/IArchivo.h"
using namespace std;

class Archivo : public IArchivo {
protected:
    string nombreArchivo;

public:
    Archivo(string nombreArchivo);
    virtual void abrir() override;
    virtual ~Archivo() {}
};

#endif
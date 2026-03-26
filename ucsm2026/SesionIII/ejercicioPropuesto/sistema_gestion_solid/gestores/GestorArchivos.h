#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

#include <vector>
#include "../interfaces/IArchivo.h"
using namespace std;

class GestorArchivos {
private:
    vector<IArchivo*> archivos;

public:
    void agregarArchivo(IArchivo* archivo);
    void mostrarArchivos();
};

#endif
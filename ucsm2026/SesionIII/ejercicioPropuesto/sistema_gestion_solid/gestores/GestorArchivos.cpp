#include <iostream>
#include "GestorArchivos.h"
using namespace std;

void GestorArchivos::agregarArchivo(IArchivo* archivo) {
    archivos.push_back(archivo);
}

void GestorArchivos::mostrarArchivos() {
    cout << "\nARCHIVOS:\n";
    for (int i = 0; i < archivos.size(); i++) {
        archivos[i]->abrir();
    }
}
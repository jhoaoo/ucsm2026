#include <iostream>
#include "Archivo.h"
using namespace std;

Archivo::Archivo(string nombreArchivo) {
    this->nombreArchivo = nombreArchivo;
}

void Archivo::abrir() {
    cout << "Abriendo archivo: " << nombreArchivo << endl;
}
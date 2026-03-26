#include <iostream>
#include "ArchivoImagen.h"
using namespace std;

ArchivoImagen::ArchivoImagen(string nombreArchivo) : Archivo(nombreArchivo) {
}

void ArchivoImagen::abrir() {
    cout << "Abriendo archivo de imagen: " << nombreArchivo << endl;
}
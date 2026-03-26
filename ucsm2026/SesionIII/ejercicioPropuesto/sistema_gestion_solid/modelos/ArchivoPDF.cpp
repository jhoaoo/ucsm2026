#include <iostream>
#include "ArchivoPDF.h"
using namespace std;

ArchivoPDF::ArchivoPDF(string nombreArchivo) : Archivo(nombreArchivo) {
}

void ArchivoPDF::abrir() {
    cout << "Abriendo archivo PDF: " << nombreArchivo << endl;
}
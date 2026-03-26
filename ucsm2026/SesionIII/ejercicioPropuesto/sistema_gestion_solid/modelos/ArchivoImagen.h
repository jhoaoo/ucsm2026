#ifndef ARCHIVOIMAGEN_H
#define ARCHIVOIMAGEN_H

#include "Archivo.h"

class ArchivoImagen : public Archivo {
public:
    ArchivoImagen(string nombreArchivo);
    void abrir() override;
};

#endif
#ifndef ARCHIVOPDF_H
#define ARCHIVOPDF_H

#include "Archivo.h"

class ArchivoPDF : public Archivo {
public:
    ArchivoPDF(string nombreArchivo);
    void abrir() override;
};

#endif
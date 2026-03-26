#ifndef IARCHIVO_H
#define IARCHIVO_H

class IArchivo {
public:
    virtual void abrir() = 0;
    virtual ~IArchivo() {}
};

#endif
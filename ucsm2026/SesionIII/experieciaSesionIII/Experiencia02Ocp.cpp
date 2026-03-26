#include <string>

#ifndef EXPERIENCIA_02_OCP_CPP
#define EXPERIENCIA_02_OCP_CPP

// Interfaz base: Abierta a la extension (nuevas tareas) pero cerrada a modificacion
class IBaseTarea {
public:
    virtual ~IBaseTarea() = default;
    virtual void ejecutarTarea() = 0;
    virtual std::string obtenerDetalles() const = 0;
};

#endif
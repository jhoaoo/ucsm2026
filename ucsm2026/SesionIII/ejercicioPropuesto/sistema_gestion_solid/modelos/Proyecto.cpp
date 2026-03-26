#include "Proyecto.h"

Proyecto::Proyecto(int id, string nombre) {
    this->id = id;
    this->nombre = nombre;
}

int Proyecto::obtenerId() {
    return id;
}

string Proyecto::obtenerNombre() {
    return nombre;
}
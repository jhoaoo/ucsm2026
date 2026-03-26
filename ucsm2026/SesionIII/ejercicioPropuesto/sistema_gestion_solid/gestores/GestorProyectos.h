#ifndef GESTORPROYECTOS_H
#define GESTORPROYECTOS_H

#include <vector>
#include "../modelos/Proyecto.h"
using namespace std;

class GestorProyectos {
private:
    vector<Proyecto> proyectos;

public:
    void agregarProyecto(Proyecto proyecto);
    void mostrarProyectos();
};

#endif
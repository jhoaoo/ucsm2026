#include <iostream>
#include "GestorProyectos.h"
using namespace std;

void GestorProyectos::agregarProyecto(Proyecto proyecto) {
    proyectos.push_back(proyecto);
}

void GestorProyectos::mostrarProyectos() {
    cout << "\nPROYECTOS:\n";
    for (int i = 0; i < proyectos.size(); i++) {
        cout << "ID: " << proyectos[i].obtenerId()
             << " - Nombre: " << proyectos[i].obtenerNombre() << endl;
    }
}
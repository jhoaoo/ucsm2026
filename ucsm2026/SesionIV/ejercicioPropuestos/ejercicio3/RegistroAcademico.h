#ifndef REGISTRO_H
#define REGISTRO_H
#include "Estudiante.h"
#include "Asignatura.h"

class RegistroAcademico {
private:
    Estudiante* estudiante;
    Asignatura* asignatura;
    float nota;
    int faltas;

public:
    RegistroAcademico(Estudiante* e, Asignatura* a);
    void setNota(float n);
    void registrarFalta();
    void mostrarResumen();
};
#endif
#include "../include/RegistroAcademico.h"
#include <iostream>

RegistroAcademico::RegistroAcademico(Estudiante* e, Asignatura* a) 
    : estudiante(e), asignatura(a), nota(0.0f), faltas(0) {}

void RegistroAcademico::setNota(float n) { 
    nota = n; 
}

void RegistroAcademico::registrarFalta() { 
    faltas++; 
}

void RegistroAcademico::mostrarResumen() {
    std::cout << "--- Registro Academico ---" << std::endl;
    std::cout << "Estudiante: " << estudiante->getNombre() << " [" << estudiante->getMatricula() << "]" << std::endl;
    std::cout << "Asignatura: " << asignatura->getNombre() << std::endl;
    std::cout << "Nota Final: " << nota << std::endl;
    std::cout << "Inasistencias: " << faltas << std::endl;
    std::cout << "--------------------------" << std::endl;
}
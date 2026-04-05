#include <iostream>
#include "Estudiante.h"
#include "Profesor.h"
#include "Asignatura.h"
#include "RegistroAcademico.h"

int main() {
    // 1. Crear Profesor
    Profesor* docente = new Profesor("Ing. Perez", "Calle Real 123", "999888777");

    // 2. Crear Asignatura vinculada al profesor
    Asignatura* curso = new Asignatura("SYS03", "Sistemas I", "Analisis y Modelado", docente);

    // 3. Crear Estudiante
    Estudiante* alumno = new Estudiante("Jhoao Sebastian", "Arequipa", "2026-UCSM");

    // 4. Crear Registro (Clase de asociacion Many-to-Many)
    RegistroAcademico* miRegistro = new RegistroAcademico(alumno, curso);
    
    // Simular actividad
    miRegistro->setNota(19.5);
    miRegistro->registrarFalta();
    miRegistro->registrarFalta();

    // Mostrar resultados
    miRegistro->mostrarResumen();

    // Limpieza de memoria (Buena practica en C++)
    delete docente;
    delete curso;
    delete alumno;
    delete miRegistro;

    return 0;
}
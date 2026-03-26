#include <iostream>
#include "Experiencia02Ocp.cpp"

#ifndef EXPERIENCIA_03_LSP_CPP
#define EXPERIENCIA_03_LSP_CPP

class TareaSimple : public IBaseTarea {
protected:
    std::string titulo;
public:
    TareaSimple(std::string t) : titulo(t) {}
    void ejecutarTarea() override { 
        std::cout << "Ejecutando tarea comun: " << titulo << std::endl; 
    }
    std::string obtenerDetalles() const override { 
        return "[Comun] " + titulo; 
    }
};

class TareaUrgente : public TareaSimple {
public:
    TareaUrgente(std::string t) : TareaSimple(t) {}
    // LSP: Sustituye a TareaSimple manteniendo la integridad del programa
    void ejecutarTarea() override { 
        std::cout << "ATENCION PRIORITARIA: " << titulo << std::endl; 
    }
    std::string obtenerDetalles() const override { 
        return "[URGENTE] " + titulo; 
    }
};

#endif
#include <iostream>
#include "Experiencia02Ocp.cpp"

#ifndef EXPERIENCIA_04_ISP_CPP
#define EXPERIENCIA_04_ISP_CPP

// Interfaz especifica solo para seguimiento de porcentaje (Segregacion)
class ISeguimientoProgreso {
public:
    virtual ~ISeguimientoProgreso() = default;
    virtual void actualizarProgreso(int porcentaje) = 0;
};

class TareaProyecto : public IBaseTarea, public ISeguimientoProgreso {
private:
    std::string nombreProyecto;
    int avance = 0;
public:
    TareaProyecto(std::string n) : nombreProyecto(n) {}
    
    void ejecutarTarea() override { 
        std::cout << "Proyecto '" << nombreProyecto << "' en curso." << std::endl; 
    }
    
    std::string obtenerDetalles() const override { 
        return "[Proyecto] " + nombreProyecto + " | Avance: " + std::to_string(avance) + "%"; 
    }

    void actualizarProgreso(int p) override { 
        avance = p; 
        std::cout << "Progreso de proyecto actualizado." << std::endl;
    }
};

#endif
#include <vector>
#include <memory>
#include "Experiencia01Srp.cpp"
#include "Experiencia02Ocp.cpp"
#include "Experiencia03Lsp.cpp"
#include "Experiencia04Isp.cpp"

// Modulo de Alto Nivel: No conoce clases concretas, solo IBaseTarea (DIP)
class GestorTareas {
private:
    std::vector<std::shared_ptr<IBaseTarea>> listaTareas;
public:
    void agregarTarea(std::shared_ptr<IBaseTarea> t) { 
        if (t) listaTareas.push_back(t); 
    }

    void mostrarSeguimiento() {
        std::cout << "\n--- REPORTE DE PROGRESO SOLID ---" << std::endl;
        for (const auto& t : listaTareas) {
            std::cout << t->obtenerDetalles() << std::endl;
            t->ejecutarTarea();
            std::cout << "---------------------------------" << std::endl;
        }
    }
};

int main() {
    GestorTareas miGestor;
    int opcion = 0;

    while (opcion != 4) {
        std::cout << "\n1. Crear Tarea Simple\n2. Crear Tarea Urgente\n3. Crear Tarea Proyecto\n4. Ver Progreso y Salir" << std::endl;
        opcion = ValidadorEntrada::leerEntero("Seleccione una opcion: ");

        if (opcion == 1) {
            miGestor.agregarTarea(std::make_shared<TareaSimple>(ValidadorEntrada::leerCadena("Nombre de tarea: ")));
        } 
        else if (opcion == 2) {
            miGestor.agregarTarea(std::make_shared<TareaUrgente>(ValidadorEntrada::leerCadena("Nombre de urgencia: ")));
        } 
        else if (opcion == 3) {
            auto proy = std::make_shared<TareaProyecto>(ValidadorEntrada::leerCadena("Nombre del proyecto: "));
            proy->actualizarProgreso(ValidadorEntrada::leerEntero("Avance inicial (%): "));
            miGestor.agregarTarea(proy);
        }
    }

    miGestor.mostrarSeguimiento();
    return 0;
}
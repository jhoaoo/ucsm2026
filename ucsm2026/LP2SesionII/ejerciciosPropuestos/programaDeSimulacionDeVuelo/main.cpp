#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

/**
 * @class Avion
 * @brief Gestiona los recursos técnicos de la aeronave.
 */
class Avion {
private:
    std::string modelo;
    double combustibleActual; // Litros
    double consumoPorHora;    // Litros/Hora
    int capacidadTripulacion;

public:
    Avion(std::string _mod, double _comb, double _cons, int _cap)
        : modelo(_mod), combustibleActual(_comb), consumoPorHora(_cons), capacidadTripulacion(_cap) {}

    // Getters necesarios para la validación de la misión
    std::string getModelo() const { return modelo; }
    double getCombustible() const { return combustibleActual; }
    double getConsumo() const { return consumoPorHora; }
    int getCapacidadTripulacion() const { return capacidadTripulacion; }

    void consumirCombustible(double cantidad) {
        combustibleActual -= cantidad;
        if (combustibleActual < 0) combustibleActual = 0;
    }
};

/**
 * @class Mision
 * @brief Planificador que vincula un destino con un avión específico.
 */
class Mision {
private:
    std::string destino;
    double duracionHoras;
    int tripulacionRequerida;

public:
    Mision(std::string _dest, double _dur, int _trip)
        : destino(_dest), duracionHoras(_dur), tripulacionRequerida(_trip) {}

    /**
     * @brief Valida los recursos y ejecuta la simulación de vuelo.
     * @param nave Referencia al objeto Avion que realizará la misión.
     */
    void simularMision(Avion& nave) {
        std::cout << "\n=== PLAN DE VUELO: DESTINO " << destino << " ===\n";
        std::cout << "Avion asignado: " << nave.getModelo() << "\n";

        // 1. Validar Tripulación
        if (nave.getCapacidadTripulacion() < tripulacionRequerida) {
            std::cout << "[ERROR] Mision abortada: El avion no tiene espacio para la tripulacion necesaria.\n";
            return;
        }

        // 2. Validar Combustible (Extra: Margen de seguridad del 10%)
        double combustibleNecesario = duracionHoras * nave.getConsumo();
        double reservaSeguridad = combustibleNecesario * 0.10;
        double totalRequerido = combustibleNecesario + reservaSeguridad;

        std::cout << "Combustible requerido (con reserva): " << totalRequerido << " L\n";
        std::cout << "Combustible disponible: " << nave.getCombustible() << " L\n";

        if (nave.getCombustible() >= totalRequerido) {
            std::cout << "[EXITO] Despegue autorizado. Volando a " << destino << "...\n";
            nave.consumirCombustible(combustibleNecesario);
            std::cout << "Mision completada con exito. Combustible restante: " << nave.getCombustible() << " L\n";
        } else {
            std::cout << "[FALLO] Combustible insuficiente. Se requieren " << (totalRequerido - nave.getCombustible()) << " L adicionales.\n";
        }
    }
};

int main() {
    // Crear aeronaves
    Avion boeing("Boeing 747", 5000.0, 1200.0, 15);
    Avion cesna("Cessna 172", 200.0, 40.0, 2);

    // Crear misiones
    Mision internacional("Madrid", 12.5, 12);
    Mision local("Cuzco", 1.5, 2);

    // Ejecutar simulaciones
    std::cout << "--- PRUEBA DE MISION 1 ---\n";
    internacional.simularMision(boeing);

    std::cout << "\n--- PRUEBA DE MISION 2 ---\n";
    local.simularMision(cesna);

    std::cout << "\n--- PRUEBA DE MISION 3 (Error de combustible) ---\n";
    Mision largaDistancia("Tokyo", 20.0, 10);
    largaDistancia.simularMision(boeing);

    return 0;
}
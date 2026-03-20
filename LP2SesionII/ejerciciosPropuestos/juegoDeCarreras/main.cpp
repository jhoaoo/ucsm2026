#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

/**
 * @class Auto
 * @brief Gestiona el estado físico y mecánico de cada competidor.
 */
class Auto {
private:
    std::string nombre;
    double distanciaRecorrida;
    int potenciaMotor;
    int cargasNitro;

public:
    Auto(std::string _nombre, int _potencia) 
        : nombre(_nombre), distanciaRecorrida(0.0), potenciaMotor(_potencia), cargasNitro(3) {}

    // Getters y Setters con encapsulamiento
    std::string getNombre() const { return nombre; }
    double getDistancia() const { return distanciaRecorrida; }
    int getCargasNitro() const { return cargasNitro; }

    /**
     * @brief Lógica de movimiento.
     * @param usarNitro Si es verdadero y tiene cargas, duplica el avance.
     * @param bonoDificultad Ajuste para la IA del oponente.
     */
    void avanzar(bool usarNitro, int bonoDificultad = 0) {
        int avanceBase = (rand() % potenciaMotor) + 1 + bonoDificultad;
        
        if (usarNitro && cargasNitro > 0) {
            avanceBase *= 2;
            cargasNitro--;
            std::cout << "[NITRO ACTIVADO] ";
        }
        
        distanciaRecorrida += avanceBase;
    }

    void mostrarProgreso(double meta) const {
        int barra = (int)((distanciaRecorrida / meta) * 20);
        if (barra > 20) barra = 20;

        std::cout << std::left << std::setw(12) << nombre << " [";
        for(int i=0; i<20; ++i) std::cout << (i < barra ? "=" : " ");
        std::cout << "] " << (int)distanciaRecorrida << "m (" << cargasNitro << " Nitro)\n";
    }
};

/**
 * @class JuegoCarrera
 * @brief Orquestador de la competencia y las reglas de negocio.
 */
class JuegoCarrera {
private:
    double meta;
    int dificultad;
    std::vector<Auto> pilotos;

public:
    JuegoCarrera(double _meta, int _dif) : meta(_meta), dificultad(_dif) {
        srand(time(0));
    }

    void registrarPilotos(const Auto& p1, const Auto& p2) {
        pilotos.push_back(p1);
        pilotos.push_back(p2);
    }

    void ejecutar() {
        bool alguienGano = false;
        
        while (!alguienGano) {
            system("clear || cls"); // Limpiar pantalla para efecto de animación
            std::cout << "=== GRAN PREMIO C++ === Meta: " << meta << "m\n\n";
            
            // Turno del Jugador
            char op;
            pilotos[0].mostrarProgreso(meta);
            pilotos[1].mostrarProgreso(meta);
            
            std::cout << "\n¿Usar Nitro? (s/n) [" << pilotos[0].getCargasNitro() << " restantes]: ";
            std::cin >> op;
            
            // Procesar avances
            pilotos[0].avanzar(op == 's' || op == 'S');
            
            // IA: Usa nitro aleatoriamente si está atrás y según dificultad
            bool nitroIA = (dificultad > 1 && (rand() % 10 < 3));
            pilotos[1].avanzar(nitroIA, dificultad * 3);

            // Verificar ganadores
            if (pilotos[0].getDistancia() >= meta || pilotos[1].getDistancia() >= meta) {
                alguienGano = true;
            }
        }
        mostrarPodio();
    }

private:
    void mostrarPodio() {
        std::cout << "\n--- RESULTADOS FINALES ---\n";
        pilotos[0].mostrarProgreso(meta);
        pilotos[1].mostrarProgreso(meta);

        if (pilotos[0].getDistancia() >= pilotos[1].getDistancia()) {
            std::cout << "\n¡HAS GANADO! Dominaste la pista.\n";
        } else {
            std::cout << "\nLA COMPUTADORA GANA. Necesitas más práctica.\n";
        }
    }
};

int main() {
    std::string nick;
    double m;
    int d;

    std::cout << "Ingresa tu nombre de piloto: ";
    std::getline(std::cin, nick);
    std::cout << "Longitud de la pista (ej. 100): ";
    std::cin >> m;
    std::cout << "Nivel de dificultad (1-Fácil, 2-Normal, 3-Experto): ";
    std::cin >> d;

    Auto p1(nick, 15);
    Auto cpu("CPU_Bot", 15);

    JuegoCarrera carrera(m, d);
    carrera.registrarPilotos(p1, cpu);
    carrera.ejecutar();

    return 0;
}
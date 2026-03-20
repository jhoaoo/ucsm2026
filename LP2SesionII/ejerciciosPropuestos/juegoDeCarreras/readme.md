# Simulador de Carrera POO (C++)

Este proyecto es un simulador de carreras basado en consola que utiliza los principios fundamentales de la Programación Orientada a Objetos (Encapsulamiento, Abstracción y Modularidad).

## Características (Requisitos + Extras)
- **Clase Auto**: Gestiona estadísticas, distancia y lógica de movimiento.
- **Clase Carrera**: Controla el flujo del juego, la meta y la dificultad.
- **IA del Oponente**: La computadora ajusta su velocidad según el nivel de dificultad elegido.
- **Sistema de Nitro (Extra)**: El jugador dispone de 3 cargas de Nitro para duplicar su avance en turnos críticos, añadiendo una capa de estrategia.

## Estructura del Código
- `Auto`: Atributos privados (`distancia`, `velocidad`) con métodos de acceso controlados.
- `Carrera`: Atributos de configuración (`distanciaMeta`, `dificultad`).

## Cómo ejecutar
1. Compilar con: `g++ main.cpp -o carrera`
2. Ejecutar: `./carrera`
3. Sigue las instrucciones en pantalla para configurar tu piloto y la dificultad.
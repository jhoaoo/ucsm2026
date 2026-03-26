# Simulador de Misiones de Vuelo (C++)

Este software permite la planificación y ejecución de misiones aéreas, validando criterios de seguridad y logística.

## Componentes del Sistema
- **Clase Avion**: Controla el consumo de combustible por hora, la capacidad de tripulación y el estado del motor.
- **Clase Mision**: Define el plan de vuelo (destino, duración, personal requerido).
- **Lógica de Simulación**: Calcula el éxito de la misión basándose en la autonomía de vuelo y la disponibilidad de tripulantes.

## Extras Agregados
- **Sistema de Consumo Dinámico**: El consumo de combustible varía según la duración del vuelo.
- **Reporte de Estado Final**: Un resumen detallado de por qué una misión falló o tuvo éxito.
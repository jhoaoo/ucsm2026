#include <iostream>
#include "Handlers.cpp"
#include "TaskModels.cpp"

int main() {
    TaskManager engine;
    int option = 0;

    while (option != 4) {
        std::cout << "\n--- GESTOR DE TAREAS UCSM ---" << std::endl;
        std::cout << "1. Tarea Simple\n2. Tarea Urgente\n3. Tarea de Proyecto\n4. Ejecutar y Salir" << std::endl;
        option = Input::getInt("Seleccione una opcion: ");

        if (option == 1) {
            std::string t = Input::getString("Nombre de la tarea: ");
            std::string d = Input::getString("Fecha (dd/mm): ");
            engine.addTask(std::make_shared<SimpleTask>(t, d));
        } 
        else if (option == 2) {
            std::string t = Input::getString("Nombre de la urgencia: ");
            engine.addTask(std::make_shared<UrgentTask>(t));
        } 
        else if (option == 3) {
            std::string n = Input::getString("Nombre del proyecto: ");
            int p = Input::getInt("Porcentaje de avance: ");
            engine.addTask(std::make_shared<ProjectTask>(n, p));
        }
    }

    engine.processAll();
    return 0;
}
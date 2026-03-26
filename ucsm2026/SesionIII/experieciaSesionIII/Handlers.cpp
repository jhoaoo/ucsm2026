#include <vector>
#include <memory>
#include <iostream>
#include <limits>
#include "Interfaces.cpp"

#ifndef HANDLERS_CPP
#define HANDLERS_CPP

class TaskManager {
private:
    std::vector<std::shared_ptr<ITask>> tasks;
public:
    void addTask(std::shared_ptr<ITask> t) { 
        if (t) tasks.push_back(t); 
    }
    void processAll() {
        if (tasks.empty()) {
            std::cout << "No hay tareas registradas." << std::endl;
            return;
        }
        for (const auto& t : tasks) {
            std::cout << t->getDetails() << std::endl;
            t->execute();
            std::cout << "-----------------------------------" << std::endl;
        }
    }
};

class Input {
public:
    static int getInt(std::string prompt) {
        int val;
        while (true) {
            std::cout << prompt;
            if (std::cin >> val) return val;
            std::cout << "Error: Ingrese un numero valido." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    static std::string getString(std::string prompt) {
        std::string str;
        std::cout << prompt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, str);
        return str;
    }
};

#endif
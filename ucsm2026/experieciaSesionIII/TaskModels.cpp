#include <iostream>
#include <string>
#include "Interfaces.cpp"

#ifndef TASKMODELS_CPP
#define TASKMODELS_CPP

class SimpleTask : public ITask {
private:
    std::string title;
    std::string date;
public:
    SimpleTask(std::string t, std::string d) : title(t), date(d) {}
    void execute() override { 
        std::cout << "Estado: Tarea '" << title << "' procesada con exito." << std::endl; 
    }
    std::string getDetails() const override { 
        return "[TAREA COMUN] " + title + " | Limite: " + date; 
    }
};

class UrgentTask : public ITask, public INotifiable {
private:
    std::string title;
public:
    UrgentTask(std::string t) : title(t) {}
    void execute() override { 
        std::cout << "ATENCION: Ejecucion prioritaria de '" << title << "'." << std::endl; 
        sendAlert();
    }
    void sendAlert() override { 
        std::cout << "NOTIFICACION: Alerta de urgencia enviada al sistema." << std::endl; 
    }
    std::string getDetails() const override { 
        return "[URGENTE] " + title; 
    }
};

class ProjectTask : public ITask {
private:
    std::string projectName;
    int progress;
public:
    ProjectTask(std::string n, int p) : projectName(n), progress(p) {}
    void execute() override { 
        std::cout << "Seguimiento: Proyecto '" << projectName << "' actualizado." << std::endl; 
    }
    std::string getDetails() const override { 
        return "[PROYECTO] " + projectName + " | Avance: " + std::to_string(progress) + "%"; 
    }
};

#endif
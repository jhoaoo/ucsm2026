#include <iostream>
#include <vector>
#include "Libro.h"
#include "Persona.h" 

using namespace std;


void agregarLibro(vector<Libro>& lista, Libro nuevoLibro) {
    lista.push_back(nuevoLibro);
}

void imprimirListaLibros(vector<Libro>& lista) {
    if (lista.empty()) {
        cout << "La lista esta vacia.\n";
        return;
    }
    for (size_t i = 0; i < lista.size(); i++) {
        lista[i].mostrarInfoLibro();
    }
}

void actualizarGeneroLibro(vector<Libro>& lista, string tituloBuscado, string nuevoGenero) {
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].getTitulo() == tituloBuscado) {
            lista[i].setGenero(nuevoGenero);
            cout << "[EXITO] Genero de '" << tituloBuscado << "' actualizado a " << nuevoGenero << ".\n";
            return; 
        }
    }
    cout << "[ERROR] Libro no encontrado.\n";
}

void eliminarLibro(vector<Libro>& lista, string tituloBuscado) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (it->getTitulo() == tituloBuscado) {
            lista.erase(it);
            cout << "[EXITO] Libro '" << tituloBuscado << "' eliminado de la lista.\n";
            return;
        }
    }
    cout << "[ERROR] Libro no encontrado para eliminar.\n";
}

// main
int main() {
    cout << "=== E) CREACION DE OBJETOS ===\n";
    Persona profe("Mary Duenas", "00000000", 35, 'F');
    Libro libroBase("C++ Basico", "Juan Perez", "Educacion", 2020);
    
    cout << "Persona creada: " << profe.nombre << "\n";
    libroBase.mostrarInfoLibro();
    cout << "\n";

    cout << "=== F) ARREGLOS / LISTAS ===\n";
    vector<Libro> miBiblioteca;

    agregarLibro(miBiblioteca, Libro("El Quijote", "Miguel de Cervantes", "Novela", 1605));
    agregarLibro(miBiblioteca, Libro("Fundamentos POO", "Ada Lovelace", "Tecnologia", 2021));
    agregarLibro(miBiblioteca, Libro("Calculo I", "James Stewart", "Matematicas", 2015));

    cout << "Lista inicial:\n";
    imprimirListaLibros(miBiblioteca);
    cout << "\n";

    cout << "=== G) ACTUALIZAR Y ELIMINAR ===\n";
    cout << "-> Actualizando genero de 'Fundamentos POO'...\n";
    actualizarGeneroLibro(miBiblioteca, "Fundamentos POO", "Programacion Avanzada");
    
    cout << "-> Eliminando 'El Quijote'...\n";
    eliminarLibro(miBiblioteca, "El Quijote");

    cout << "\nLista despues de los cambios:\n";
    imprimirListaLibros(miBiblioteca);
    cout << "\n";

    cout << "=== H) COMPARACION DE OBJETOS ===\n";
    Libro libro1("Estructuras de Datos", "Luis Joyanes", "Ingenieria", 2010);
    Libro libro2("Estructuras de Datos", "Luis Joyanes", "Informatica", 2012);
    Libro libro3("Redes", "Andrew Tanenbaum", "Tecnologia", 2011);

    cout << "Comparando Libro 1 y Libro 2 (mismo titulo y autor, distinto genero/anio):\n";
    if (libro1.esIgualA(libro2)) {
        cout << "-> Son el 'mismo' libro segun nuestra logica.\n";
    } else {
        cout << "-> Son libros diferentes.\n";
    }

    cout << "Comparando Libro 1 y Libro 3:\n";
    if (libro1.esIgualA(libro3)) {
        cout << "-> Son el 'mismo' libro.\n";
    } else {
        cout << "-> Son libros diferentes.\n";
    }

    return 0;
}   
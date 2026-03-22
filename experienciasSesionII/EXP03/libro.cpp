#include "Libro.h"
#include <iostream>

Libro::Libro(std::string tit, std::string aut, std::string gen, int anio) {
    titulo = tit;
    autor = aut;
    genero = gen;
    anioPublicacion = anio;
}

std::string Libro::getTitulo() { return titulo; }
void Libro::setTitulo(std::string tit) { titulo = tit; }

std::string Libro::getAutor() { return autor; }
void Libro::setAutor(std::string aut) { autor = aut; }

std::string Libro::getGenero() { return genero; }
void Libro::setGenero(std::string gen) { genero = gen; }

void Libro::mostrarInfoLibro() {
    std::cout << "- " << titulo << " | Autor: " << autor 
              << " | Genero: " << genero << " | Anio: " << anioPublicacion << "\n";
}

// Implementación de la comparación (Inciso h)
bool Libro::esIgualA(Libro otro) {
    // Retorna true solo si el título y el autor son exactamente iguales
    if (this->titulo == otro.getTitulo() && this->autor == otro.getAutor()) {
        return true;
    }
    return false;
}
#ifndef LIBRO_H
#define LIBRO_H
#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string genero;
public:
    int anioPublicacion;
    
    Libro(std::string tit, std::string aut, std::string gen, int anio);
    
    std::string getTitulo();
    void setTitulo(std::string tit); // Agregado para poder actualizar
    
    std::string getAutor();
    void setAutor(std::string aut);
    
    std::string getGenero();
    void setGenero(std::string gen);
    
    void mostrarInfoLibro();
    
    // Método nuevo requerido en el inciso h
    bool esIgualA(Libro otro); 
};

#endif
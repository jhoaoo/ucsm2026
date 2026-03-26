#ifndef GESTORCOMENTARIOS_H
#define GESTORCOMENTARIOS_H

#include <vector>
#include "../modelos/Comentario.h"
using namespace std;

class GestorComentarios {
private:
    vector<Comentario> comentarios;

public:
    void agregarComentario(Comentario comentario);
    void mostrarComentarios();
};

#endif
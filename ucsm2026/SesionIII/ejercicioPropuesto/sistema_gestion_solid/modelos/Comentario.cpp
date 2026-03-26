#include "Comentario.h"

Comentario::Comentario(int id, string texto) {
    this->id = id;
    this->texto = texto;
}

int Comentario::obtenerId() {
    return id;
}

string Comentario::obtenerTexto() {
    return texto;
}
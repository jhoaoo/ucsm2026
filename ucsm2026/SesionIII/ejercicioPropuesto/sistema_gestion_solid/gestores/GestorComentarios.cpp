#include <iostream>
#include "GestorComentarios.h"
using namespace std;

void GestorComentarios::agregarComentario(Comentario comentario) {
    comentarios.push_back(comentario);
}

void GestorComentarios::mostrarComentarios() {
    cout << "\nCOMENTARIOS:\n";
    for (int i = 0; i < comentarios.size(); i++) {
        cout << "ID: " << comentarios[i].obtenerId()
             << " - Texto: " << comentarios[i].obtenerTexto() << endl;
    }
}
#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include "../interfaces/IComentario.h"
using namespace std;

class Comentario : public IComentario {
private:
    int id;
    string texto;

public:
    Comentario(int id, string texto);
    int obtenerId() override;
    string obtenerTexto() override;
};

#endif
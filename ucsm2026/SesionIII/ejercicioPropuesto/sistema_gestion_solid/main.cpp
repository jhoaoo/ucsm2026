#include <iostream>
#include "gestores/GestorProyectos.h"
#include "gestores/GestorComentarios.h"
#include "gestores/GestorArchivos.h"
#include "modelos/ArchivoPDF.h"
#include "modelos/ArchivoImagen.h"
using namespace std;

void usarArchivo(IArchivo* archivo) {
    archivo->abrir();
}

int main() {
    GestorProyectos gestorProyectos;
    gestorProyectos.agregarProyecto(Proyecto(1, "Proyecto Final"));
    gestorProyectos.agregarProyecto(Proyecto(2, "Proyecto Web"));
    gestorProyectos.mostrarProyectos();

    GestorComentarios gestorComentarios;
    gestorComentarios.agregarComentario(Comentario(1, "Buen trabajo"));
    gestorComentarios.agregarComentario(Comentario(2, "Falta mejorar"));
    gestorComentarios.mostrarComentarios();

    ArchivoPDF archivoPdf("documento.pdf");
    ArchivoImagen archivoImagen("foto.png");

    GestorArchivos gestorArchivos;
    gestorArchivos.agregarArchivo(&archivoPdf);
    gestorArchivos.agregarArchivo(&archivoImagen);
    gestorArchivos.mostrarArchivos();

    cout << "\nPRUEBA LSP:\n";
    usarArchivo(&archivoPdf);
    usarArchivo(&archivoImagen);

    return 0;
}
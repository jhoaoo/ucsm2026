// Utilidades.h
#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>

int leerEntero(const std::string& mensaje, int minimo);
double leerDouble(const std::string& mensaje, double minimo);
std::string leerTextoNoVacio(const std::string& mensaje);
int leerOpcionMenu();

#endif
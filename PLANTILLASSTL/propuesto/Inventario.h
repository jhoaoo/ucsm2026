// Inventario.h
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Producto.h"
#include <set>
#include <vector>

void registrarProducto(std::vector<Producto>& inventario, std::set<std::string>& codigos);
void mostrarInventario(const std::vector<Producto>& inventario);
void buscarProducto(const std::vector<Producto>& inventario);
void actualizarStock(std::vector<Producto>& inventario);
void eliminarProducto(std::vector<Producto>& inventario, std::set<std::string>& codigos);
void ordenarPorDescripcion(std::vector<Producto>& inventario);
void mostrarPorCategoria(const std::vector<Producto>& inventario);
void mostrarStockBajo(const std::vector<Producto>& inventario);
void mostrarProductoMayorPrecio(const std::vector<Producto>& inventario);
void mostrarValorTotal(const std::vector<Producto>& inventario);

#endif
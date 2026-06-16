// Producto.h
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

class Producto {
private:
    std::string codigo;
    std::string descripcion;
    std::string categoria;
    double precioUnitario;
    int stock;

public:
    Producto(
        const std::string& codigo,
        const std::string& descripcion,
        const std::string& categoria,
        double precioUnitario,
        int stock
    ) : codigo(codigo),
        descripcion(descripcion),
        categoria(categoria),
        precioUnitario(precioUnitario),
        stock(stock) {}

    std::string getCodigo() const { return codigo; }
    std::string getDescripcion() const { return descripcion; }
    std::string getCategoria() const { return categoria; }
    double getPrecioUnitario() const { return precioUnitario; }
    int getStock() const { return stock; }

    void actualizarStock(int nuevoStock) {
        if (nuevoStock >= 0) {
            stock = nuevoStock;
        }
    }

    double calcularValorParcial() const {
        return precioUnitario * stock;
    }

    void mostrar() const {
        std::cout << codigo << " | "
                  << descripcion << " | "
                  << categoria << " | S/ "
                  << precioUnitario << " | Stock: "
                  << stock << '\n';
    }
};

#endif
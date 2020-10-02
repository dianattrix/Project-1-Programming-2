//
//  Created by mafef on 21/08/2020.
//

#include "Producto.h"

Producto::Producto() {
    cantidad = 0;
    precio = 0;
    nombre = "";
}

Producto::Producto(string nombre, int precio, int cantidad) {
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
}

string Producto::getNombre() {
    return nombre;
}

int Producto::getPrecio() {
    return precio;
}

int Producto::getCantidad() {
    return cantidad;
}

void Producto::setPrecio(int precio) {
    this->precio = precio;

}

void Producto::setNombre(string nombre) {
    this->nombre = nombre;

}

void Producto::setCantidad(int cantidadNueva) {
    cantidad += cantidadNueva;

}

string Producto::toString() {
    stringstream salida;
    salida << "Nombre del producto: " << nombre << endl;
    salida << "Precio del producto: " << precio << endl;
    salida << "Cantidad disponible: " << cantidad << endl;
    return salida.str();
}




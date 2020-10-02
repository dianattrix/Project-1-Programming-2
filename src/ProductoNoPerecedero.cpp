//
//  Created by mafef on 21/08/2020.
//

#include "ProductoNoPerecedero.h"


ProductoNoPerecedero::ProductoNoPerecedero() {

}

ProductoNoPerecedero::ProductoNoPerecedero(string nombre, int precio, int cantidad) : Producto(nombre, precio,
                                                                                               cantidad) {

}

int ProductoNoPerecedero::getPrecio() {
    return Producto::getPrecio() - (Producto::getPrecio() * porcentajeDescuento);
}

float ProductoNoPerecedero::getPorcentajeDescuento() {
    return porcentajeDescuento;
}

string ProductoNoPerecedero::toString() {
    stringstream salida;
    salida << Producto::toString();
    return salida.str();
}

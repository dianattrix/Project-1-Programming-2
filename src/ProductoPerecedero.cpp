//
//  Created by mafef on 21/08/2020.
//

#include "ProductoPerecedero.h"


ProductoPerecedero::ProductoPerecedero() {
    fechaVencimiento = 0;
}

ProductoPerecedero::ProductoPerecedero(string nombre, int precio, int cantidad, Fecha fechaVencimiento) : Producto(
        nombre, precio, cantidad) {
    this->fechaVencimiento = fechaVencimiento;
}

int ProductoPerecedero::getPrecio() {
    if (fechaVencimiento.dif_dias(fechaVencimiento.fechaActual(), fechaVencimiento) < 11) {
        return Producto::getPrecio() - (Producto::getPrecio() * porcentajeDescuento);
    } else return Producto::getPrecio();
}

string ProductoPerecedero::toString() {
    stringstream salida;
    salida << Producto::toString();
    salida << "Fecha de vencimiento: " << fechaVencimiento.imprimeFecha() << endl;
    return salida.str();
}

float ProductoPerecedero::getPorcentajeDescuento() {
    return porcentajeDescuento;
}

Fecha ProductoPerecedero::getFechaVencimiento() {
    return fechaVencimiento;
}




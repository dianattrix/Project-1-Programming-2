//
//  Created by mafef on 21/08/2020.
//

#ifndef PROYECTO1_PRODUCTOPERECEDERO_H
#define PROYECTO1_PRODUCTOPERECEDERO_H

#include"Producto.h"
#include"Fecha.h"

//Clase que respeta el principio de Abierto/Cerrado
//y Sustitucion Liskov
class ProductoPerecedero : public Producto {
private:
    float porcentajeDescuento = 0.50;
    Fecha fechaVencimiento;

public:
    ProductoPerecedero();

    ProductoPerecedero(string nombre, int precio, int cantidad, Fecha fechaVencimiento);

    int getPrecio() override;

    float getPorcentajeDescuento();

    Fecha getFechaVencimiento();

    string toString() override;

};

#endif //PROYECTO1_PRODUCTOPERECEDERO_H

//
//  Created by mafef on 21/08/2020.
//

#ifndef PROYECTO1_PRODUCTONOPERECEDERO_H
#define PROYECTO1_PRODUCTONOPERECEDERO_H

#include"Producto.h"

//Clase que respeta el principio de Abierto/Cerrado
//y Sustitucion Liskov
class ProductoNoPerecedero : public Producto {
private:
    float porcentajeDescuento = 0.15;

public:
    ProductoNoPerecedero();

    ProductoNoPerecedero(string nombre, int precio, int cantidad);

    int getPrecio() override;
    float getPorcentajeDescuento();
    string toString();
};

#endif //PROYECTO1_PRODUCTONOPERECEDERO_H

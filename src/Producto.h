//
//  Created by mafef on 21/08/2020.
//

#ifndef PROYECTO1_PRODUCTO_H
#define PROYECTO1_PRODUCTO_H

#include<iostream>
#include<sstream>

using namespace std;

class Producto {
private:
    string nombre;
    int precio, cantidad;

public:
    Producto();

    Producto(string, int, int);

    virtual ~Producto() {}

    string getNombre();

    virtual int getPrecio() = 0;

    int getCantidad();

    void setPrecio(int precio);

    void setNombre(string nombre);

    void setCantidad(int cantidad);

    virtual string toString();
};

#endif //PROYECTO1_PRODUCTO_H

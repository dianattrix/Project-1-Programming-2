//
// Created by diana on 24/8/2020.
//

#ifndef PROYECTO1_IMAQUINAVENDEDORA_H
#define PROYECTO1_IMAQUINAVENDEDORA_H

#include<iostream>
#include<sstream>
#include"Producto.h"

using namespace std;

//Clase que respeta el principio de Segregacion de Interfaces
class IMaquinaVendedora {
public:
    virtual void setNombre(string) = 0;

    virtual string realizarCompra(string id, int cantidad, int montoPago, int dinero) = 0;

    virtual string toString() = 0;

    virtual Producto *consultar(string id) = 0;
};

#endif //PROYECTO1_IMAQUINAVENDEDORA_H

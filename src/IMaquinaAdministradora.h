//
// Created by diana on 24/8/2020.
//

#ifndef PROYECTO1_IMAQUINAADMINISTRADORA_H
#define PROYECTO1_IMAQUINAADMINISTRADORA_H

using namespace std;

#include<sstream>
#include<iostream>
#include"Producto.h"

//Clase que respeta el principio de Segregacion de Interfaces
class IMaquinaAdministradora {
public:
    virtual int getCapital() = 0;

    virtual string toString() = 0;

    virtual void insertar(Producto *) = 0;

    virtual void agregarProvisiones(string idProducto, int cantidad) = 0;

    virtual void disminuirProvisiones(string idProducto, int cantidad) = 0;

    virtual void borrar(string id) = 0;

    virtual Producto *consultar(string id) = 0;

    virtual void ingresarDinero(int dinero) = 0;

    virtual void retirarDinero(int cantidad) = 0;

};

#endif //PROYECTO1_IMAQUINAADMINISTRADORA_H

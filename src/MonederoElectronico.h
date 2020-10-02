//
// Created by diana on 24/8/2020.
//

#ifndef PROYECTO1_MONEDEROELECTRONICO_H
#define PROYECTO1_MONEDEROELECTRONICO_H

#include<sstream>
#include<iostream>
//Clase que respeta el principio de Responsabilidad Unica
using namespace std;

class MonederoElectronico {
private:
    int dinero;
public:
    MonederoElectronico();

    explicit MonederoElectronico(int);

    string desgloceVuelto(int);

    void setDinero(int);

    int getDinero();

    int devuelveCambio(int montoPago, int dinero);

    int *distribuir(int contador, int monedas[], int monto);

    string toString();

    virtual ~MonederoElectronico() = default;

};


#endif //PROYECTO1_MONEDEROELECTRONICO_H

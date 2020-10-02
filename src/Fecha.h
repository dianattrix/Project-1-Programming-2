//
// Created by fabiana on 25/08/2020.
//

#ifndef PROYECTO1_FECHA_H
#define PROYECTO1_FECHA_H

#include<ctime>
#include<iostream>
#include<sstream>

using namespace std;

//Esta clase aplica el principio de Resposabilidad Unica
class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int dia = 0, int mes = 0, int annio = 0);

    bool fechaValida(int ndia, int nmes, int nanio);

    int getDia();

    int getMes();

    int getAnio();

    string imprimeFecha();

    int dif_dias(Fecha fechaA, Fecha fechaB);

    Fecha fechaActual();
};

#endif //PROYECTO1_FECHA_H

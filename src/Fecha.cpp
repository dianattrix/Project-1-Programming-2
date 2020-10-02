//
// Created by fabiana on 25/08/2020.
//

#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anio) {
    // Constructor
    if(fechaValida(dia,mes,anio)){
        this->dia=dia;
        this->mes=mes;
        this->anio=anio;
    }
}
bool Fecha::fechaValida(int _dia, int _mes, int _anio){
    if(_dia<1 || _dia>31) return false;
    else if (_mes<1 || _mes>12) return false;
    else switch(_mes)
        {
            case 4: case 6: case 9: case 11:
                if(_dia>30) return false;
                break;
            case 2:
                if (_dia>28)return false;
                break;
        }
    return true;
}
int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

string Fecha::imprimeFecha(){
    stringstream salida;
    salida << getDia() << "-" << getMes() << "-" << getAnio() << endl;
    return salida.str();
}


int Fecha::dif_dias(Fecha fecha1, Fecha fecha2){
    int dia, mes, anio, diferencia =0;

    if(fecha1.anio > fecha1.anio) return -1;
    else if(fecha1.anio == fecha2.anio && fecha1.mes > fecha2.mes) return -1;
    else if(fecha1.anio == fecha2.anio && fecha1.mes == fecha2.mes && fecha1.dia > fecha2.dia) return -1;

    if(fecha1.anio == fecha2.anio) {
        if(fecha1.mes == fecha2.mes) return fecha2.dia-fecha1.dia;
        for(anio=fecha1.mes+1; anio<fecha2.mes  ; anio++)
        {
            switch(anio) {
                case 4: case 6: case 9: case 11:
                    diferencia+=30;
                    break;
                case 2:
                    diferencia+=28;
                    break;
                default:
                    diferencia+= 31;
            }
        }

        switch(fecha1.mes) {
            case 4: case 6: case 9: case 11:
                diferencia+=30-fecha1.dia;
                break;
            case 2:
                diferencia+=28-fecha1.dia;
                break;
            default:
                diferencia+= 31-fecha1.dia;
        }
        diferencia+=fecha2.dia;

        return diferencia;
    }

    else diferencia = (fecha2.anio - (fecha1.anio+1)) * 365;
    for(anio=fecha1.mes+1; anio<=12  ; anio++)
    {
        switch(anio) {
            case 4: case 6: case 9: case 11:
                diferencia+=30;
                break;
            case 2:
                diferencia+=28;
                break;
            default:
                diferencia+= 31;
        }
    }

    for(anio=1; anio<fecha2.mes  ; anio++)
    {
        switch(anio) {
            case 4: case 6: case 9: case 11:
                diferencia+=30;
                break;
            case 2:
                diferencia+=28;
                break;
            default:
                diferencia+= 31;
        }
    }

    switch(anio) {
        case 4: case 6: case 9: case 11:
            diferencia+=30-fecha1.dia;
            break;
        case 2:
            diferencia+=28-fecha1.dia;
            break;
        default:
            diferencia+= 31-fecha1.dia;
    }
    diferencia+=fecha2.dia;

    return diferencia;
}

Fecha Fecha::fechaActual() {
    time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);

    Fecha fechaActual(ti->tm_mday, ti->tm_mon + 1, ti->tm_year);
    return fechaActual;
}


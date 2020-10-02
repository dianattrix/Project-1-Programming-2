//
// Created by diana on 1/9/2020.
//

#include "MonederoElectronico.h"
#include <iomanip>

MonederoElectronico::MonederoElectronico() {
    dinero = 0;
}

MonederoElectronico::MonederoElectronico(int dinero) {
    this->dinero = dinero;
}

int MonederoElectronico::devuelveCambio(int montoPago, int dinero) {
    int cambio = dinero - montoPago;
    return cambio;
}

string MonederoElectronico::desgloceVuelto(int cambioAdesglozar) {
    int monedas = 5;
    int tipoMoneda[] = {
            5000,
            2000,
            1000,
            500,
            100
    };

    bool continuar = true;
    stringstream salida;
    while (continuar) {
        int *distribucion = distribuir(monedas, tipoMoneda, cambioAdesglozar);

        salida << endl;
        salida << setw(4) << cambioAdesglozar << " se pueden distribuir:" << endl;
        salida << endl;

        for (int i = 0; i < monedas; i++) {
            if (distribucion[i] > 0) {
                salida << setw(8) << distribucion[i] << " unidad(es) de ";
                salida << setw(8) << tipoMoneda[i] << " colones";
                salida << endl;
            }
        }
        if (distribucion[monedas] > 0) {
            salida << endl;
            salida << "Quedan " << distribucion[monedas];
            salida << " que no se pueden pagar." << endl;
            continuar = false;
        }

        delete[] distribucion;
    }
    setDinero(0);
    return salida.str();

}

void MonederoElectronico::setDinero(int dinero) {
    this->dinero = dinero;
}

int MonederoElectronico::getDinero() {
    return dinero;
}

string MonederoElectronico::toString() {
    stringstream salida;
    salida << "Dinero disponible: " << dinero << endl;
    return salida.str();
}

int *MonederoElectronico::distribuir(int contador, int monedas[], int monto) {
    int *almacen = new int[contador + 1];
    almacen[contador] = monto;

    for (int inicio = 0; inicio < contador; inicio++) {
        almacen[inicio] = 0;
        if (almacen[contador] >= monedas[inicio]) {
            almacen[inicio] = almacen[contador] / monedas[inicio];
            almacen[contador] -= almacen[inicio] * monedas[inicio];
        }
    }

    return almacen;
}


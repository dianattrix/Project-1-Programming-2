//
// Created by fabiana on 01/09/2020.
//

#ifndef PROYECTO1_MENUCOBRO_H
#define PROYECTO1_MENUCOBRO_H

#include"MenuAdministrador.h"
#include"IMaquinaVendedora.h"
#include "Maquina.h"
#include"Utiles.h"

class MenuCobro {
private:
    IMaquinaVendedora *maquina;
//Clase que respeta el principio de Inversion de Dependencias
//ademas, se aplica el principio de Segregacion de Interfaces
public:
    MenuCobro(IMaquinaVendedora *maquina);

    void mostrar();

    void mostrarProducto();

    void seleccionarProducto();

    void realizarCompra();

    virtual ~MenuCobro();
};

#endif //PROYECTO1_MENUCOBRO_H

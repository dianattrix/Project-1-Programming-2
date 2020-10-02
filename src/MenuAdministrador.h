//
// Created by diana on 3/9/2020.
//

#ifndef PROYECTO1_MENUADMINISTRADOR_H
#define PROYECTO1_MENUADMINISTRADOR_H


#include"Maquina.h"
#include"ProductoPerecedero.h"
#include"ProductoNoPerecedero.h"
#include"Fecha.h"
#include"MenuCobro.h"

//Clase que respeta el principio de Inversion de Dependencias
//ademas, se aplica el principio de Segregacion de Interfaces
class MenuAdministrador {
private:
    IMaquinaAdministradora *maquina;
    Producto *producto;
public:
    MenuAdministrador(IMaquinaAdministradora *maquina);

    virtual ~MenuAdministrador();

    virtual IMaquinaAdministradora *getMaquina();

    void mostrar();

    void insertarProducto();

    void eliminarProducto();

    void agregarProvisiones();

    void eliminarProvisiones();

    void ingresarDineroMaquina();

    void retirarDineroMaquina();

    void consultarCapital();
};

#endif //PROYECTO1_MENUADMINISTRADOR_H

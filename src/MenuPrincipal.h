//
// Created by diana on 7/9/2020.
//

#ifndef PROYECTO1_MENUPRINCIPAL_H
#define PROYECTO1_MENUPRINCIPAL_H

#include"MenuAdministrador.h"
#include"MenuCobro.h"
#include"Maquina.h"
#include"Utiles.h"

class MenuPrincipal {
protected:
    Maquina *maquina = new Maquina();
    MenuAdministrador *admin = new MenuAdministrador(maquina);
    MenuCobro *cobro = new MenuCobro(maquina);

public:

    void menuPrincipal();

    virtual ~MenuPrincipal();
};

#endif //PROYECTO1_MENUPRINCIPAL_H


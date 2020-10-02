//
// Created by diana on 24/8/2020.
//

#ifndef PROYECTO1_MAQUINA_H
#define PROYECTO1_MAQUINA_H

#include"MonederoElectronico.h"
#include"IMaquinaAdministradora.h"
#include"IMaquinaVendedora.h"
#include"Coleccion.h"


class Maquina : public IMaquinaVendedora, public IMaquinaAdministradora {
private:
    int identificador, capital;
    string nombre;
    Coleccion<Producto *> listaProductos;
    MonederoElectronico monederoElectronico;
public:
    Maquina();

    Maquina(int identificador, string nombre, Coleccion<Producto *> listaProductos,
            MonederoElectronico monederoElectronico, int capital);


    int getCapital() override;

    int getIdentificador();

    MonederoElectronico getMonederoElectronico();

    string getNombre();

    Coleccion<Producto *> getListaProductos();

    void setCapital(int capital);

    void setNombre(string nombre) override;

    void setListaProductos(Coleccion<Producto *> listaProductos);

    string toString() override;

    void insertar(Producto *producto) override;

    void agregarProvisiones(string idProducto, int cantidad) override;

    void disminuirProvisiones(string idProducto, int cantidad) override;

    void borrar(string id) override;

    Producto *consultar(string id) override;

    void ingresarDinero(int dinero) override;

    void retirarDinero(int cantidad) override;

    string realizarCompra(string id, int cantidad, int montoPago, int dinero) override;

    Coleccion<Producto *> retornaProductosMaquinaAdmin();

    virtual ~Maquina();
};

#endif //PROYECTO1_MAQUINA_H

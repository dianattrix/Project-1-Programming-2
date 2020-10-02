//
// Created by fabiana on 25/08/2020.
//
#include "Maquina.h"


Maquina::Maquina() {
    this->identificador = 0;
    this->nombre = "";
    this->capital = 0;
}

Maquina::Maquina(int identificador, string nombre, Coleccion<Producto *> listaProductos,
                 MonederoElectronico monederoElectronico, int capital) {
    this->identificador = identificador;
    this->nombre = nombre;
    this->monederoElectronico = monederoElectronico;
    this->listaProductos = listaProductos;
    this->capital = capital;
}

void Maquina::setNombre(string nombre) {
    this->nombre = nombre;
}

string Maquina::toString() {
    stringstream salida;
    salida << "Nombre de la maquina: " << nombre << endl;
    salida << "Identificador: " << identificador << endl;
    for (int inicio = 0; inicio < listaProductos.getColeccion().size(); inicio++) {
        salida << "Producto numero " << inicio << ":" << listaProductos.getColeccion().at(inicio)->toString();
    }
    return salida.str();
}

void Maquina::insertar(Producto *producto) {
    listaProductos.agregar(producto);
}

void Maquina::agregarProvisiones(string idProducto, int cantidad) {
    if (listaProductos.getColeccion().empty()) {
        cerr << "No se pueden agregar provisiones porque no hay productos registrados" << endl;
    } else {
        for (int inicio = 0; inicio < listaProductos.getColeccion().size(); inicio++) {
            if (listaProductos.getColeccion().at(inicio)->getNombre() == idProducto) {
                listaProductos.getColeccion().at(inicio)->setCantidad(cantidad);
            }
        }
    }

}

void Maquina::disminuirProvisiones(string idProducto, int cantidad) {
    if (listaProductos.getColeccion().empty()) {
        cerr << "No se pueden disminuir provisiones porque no hay productos registrados" << endl;
    } else {
        for (int inicio = 0; inicio < listaProductos.getColeccion().size(); inicio++) {
            if (listaProductos.getColeccion().at(inicio)->getNombre() == idProducto) {
                if (listaProductos.getColeccion().at(inicio)->getCantidad() >= cantidad) {
                    listaProductos.getColeccion().at(inicio)->setCantidad(-cantidad);
                }
            }
        }
    }
}

void Maquina::borrar(string id) {
    if (listaProductos.getColeccion().empty()) {
        cerr << "No se pueden eliminar productos porque no hay registrados" << endl;
    } else {
        for (int inicio = 0; inicio < listaProductos.getColeccion().size(); inicio++) {
            if (listaProductos.getColeccion().at(inicio)->getNombre() == id) {
                listaProductos.eliminar(inicio);
            }
        }
    }
}

Producto *Maquina::consultar(string id) {
    if (listaProductos.getColeccion().empty()) {
        cerr << "No se pueden mostrar productos porque no hay registrados" << endl;
    } else {
        for (int inicio = 0; inicio < listaProductos.getColeccion().size(); inicio++) {
            if (listaProductos.getColeccion().at(inicio)->getNombre() == id) {
                return listaProductos.getColeccion().at(inicio);
            }
        }
    }
    return nullptr;
}

void Maquina::ingresarDinero(int dinero) {
    setCapital(dinero);
}

void Maquina::retirarDinero(int cantidad) {
    if (monederoElectronico.getDinero() >= cantidad) {
        setCapital(-cantidad);
    }
}

Maquina::~Maquina() {
    for (int inicio = 0; inicio < listaProductos.getColeccion().size(); inicio++) {
        if (listaProductos.getColeccion().empty()) {
            listaProductos.getColeccion().erase(listaProductos.getColeccion().begin() + inicio);
        }
    }
}

string Maquina::realizarCompra(string id, int cantidad, int montoPago, int dinero) {
    stringstream salida;
    if (listaProductos.getColeccion().empty()) {
        cerr << "No se puede realizar la compra ya que no existen productos registrados en el sistema" << endl;
    } else {
        monederoElectronico.setDinero(dinero);
        if (consultar(id)) {
            if (consultar(id)->getCantidad() >= cantidad) {
                consultar(id)->setCantidad(-cantidad);
                salida << "Su compra ha sido exitosa, detalle de su vuelto: " << endl;
                salida << monederoElectronico.desgloceVuelto(monederoElectronico.devuelveCambio(montoPago, dinero));
                setCapital(montoPago);
                ingresarDinero(montoPago);
            } else {
                cerr << "Lo sentimos, el producto que necesita esta agotado o la cantidad es insuficiente" << endl;
            }

        }
    }
    return salida.str();
}

Coleccion<Producto *> Maquina::retornaProductosMaquinaAdmin() {
    return listaProductos;
}

void Maquina::setCapital(int capital) {
    this->capital += capital;
}

int Maquina::getCapital() {
    return capital;
}

int Maquina::getIdentificador() {
    return identificador;
}

string Maquina::getNombre() {
    return nombre;
}

Coleccion<Producto *> Maquina::getListaProductos() {
    return listaProductos;
}

MonederoElectronico Maquina::getMonederoElectronico() {
    return monederoElectronico;
}

void Maquina::setListaProductos(Coleccion<Producto*> listaProductos) {
    this->listaProductos = listaProductos;
}


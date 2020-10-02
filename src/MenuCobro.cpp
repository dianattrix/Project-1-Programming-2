//
// Created by fabiana on 01/09/2020.
//

#include "MenuCobro.h"

MenuCobro::MenuCobro(IMaquinaVendedora *maquina) {
    this->maquina = maquina;
}

MenuCobro::~MenuCobro() {
    delete maquina;
}

void MenuCobro::mostrar() {
    bool ciclo = true;
    while (ciclo) {
        cout << "Menu cobro" << endl;
        cout << "Digite la opcion que desea ejecutar: " << endl;
        cout << "[1] Mostrar Producto\n[2] Seleccionar Productos\n[3] Realizar compra\n[4] Salir del Menu Cobro"
             << endl;
        int opcion;
        opcion = leerEntero();
        switch (opcion) {
            default:
                cerr << "Opcion invalida" << endl;
                system("pause");
                system("cls");
                break;
            case 1:
                mostrarProducto();
                system("pause");
                system("cls");
                break;
            case 2:
                seleccionarProducto();
                system("pause");
                system("cls");
                break;
            case 3:
                realizarCompra();
                system("pause");
                system("cls");
                break;
            case 4:
                ciclo = false;
                system("cls");
                break;
        }
    }
}

void MenuCobro::mostrarProducto() {
    cout << "Lista de productos: " << endl;
    maquina->setNombre("Maquina del tiempo");
    cout << maquina->toString();
}

void MenuCobro::seleccionarProducto() {
    cout << "Digite el nombre del producto: " << endl;
    string nombre;
    nombre = leerCadena();
    if (maquina->consultar(nombre)->getNombre() == nombre) {
        cout << "El producto esta disponible en nuestro inventario " << endl;
    } else {
        cerr << "El producto no existe en inventario" << endl;
    }

}

void MenuCobro::realizarCompra() {
    cout << "Digite el nombre del producto: " << endl;
    string nombre;
    nombre = leerCadena();
    if (maquina->consultar(nombre) == nullptr) {
        cout << "El producto no existe en inventario"
             << endl;
    } else if (maquina->consultar(nombre)->getNombre() == nombre) {
        cout << "El producto esta disponible en nuestro inventario " << endl;
        cout << "Digite la cantidad que desea de " << maquina->consultar(nombre)->getNombre() << " :" << endl;
        int cantidad;
        cantidad = leerEntero();
        if (maquina->consultar(nombre)->getNombre() == nombre) {
            cout << "Se puede realizar la compra " << endl;
            int montoPago;
            montoPago = (maquina->consultar(nombre)->getPrecio() * cantidad);
            cout << "Monto a pagar: " << montoPago << endl;
            cout << "Digite la suma de dinero " << endl;
            int dinero;
            dinero = leerEntero();
            cout << maquina->realizarCompra(nombre, cantidad, montoPago, dinero) << endl;
        }
    }


}
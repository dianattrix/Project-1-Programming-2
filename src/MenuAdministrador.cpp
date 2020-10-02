//
// Created by diana on 3/9/2020.
//



#include "MenuAdministrador.h"
#include"Utiles.h"

void MenuAdministrador::mostrar() {
    bool ciclo = true;
    while (ciclo) {
        cout << "Menu administrador" << endl;
        cout << "Digite la opcion que desea ejecutar: " << endl;
        cout
                << "[1] Insertar producto\n[2] Eliminar producto\n[3] Agregar provisiones\n[4] Eliminar provisiones\n[5] Ingresar dinero\n";
        cout << "[6] Retirar dinero\n[7] Consultar saldo\n[8] Salir del menu Administrador" << endl;
        int opcion;
        opcion = leerEntero();

        switch (opcion) {
            default:
                cerr << "Opcion invalida" << endl;
                system("pause");
                system("cls");
                break;
            case 1:
                insertarProducto();
                system("pause");
                system("cls");
                break;
            case 2:
                eliminarProducto();
                system("pause");
                system("cls");
                break;
            case 3:
                agregarProvisiones();
                system("pause");
                system("cls");
                break;
            case 4:
                eliminarProvisiones();
                system("pause");
                system("cls");
                break;
            case 5:
                ingresarDineroMaquina();
                system("pause");
                system("cls");
                break;
            case 6:
                retirarDineroMaquina();
                system("pause");
                system("cls");
                break;
            case 7:
                consultarCapital();
                system("pause");
                system("cls");
                break;
            case 8:
                ciclo = false;
                system("cls");
                break;
        }
    }
}

void MenuAdministrador::insertarProducto() {
    cout << "Digite el nombre del producto: " << endl;
    string nombre;
    nombre = leerCadena();
    cout << "Digite el precio del producto: " << endl;
    int precio;
    precio = leerEntero();
    cout << "Digite la cantidad de productos disponibles: " << endl;
    int cantidad;
    cantidad = leerEntero();
    cout << "Digite\n[1] Producto perecedero\n[2] Producto no perecedero\n";
    int perecedero;
    perecedero = leerEntero();
    if (perecedero == 1) {
        cout
                << "Digite la fecha de vencimiento del producto\nTome en cuenta que esta debe ser en orden dia-mes-anio y estos deben ser en formato numerico:"
                << endl;
        int dia, mes, anio;
        cout << "Dia: ";
        dia = leerEntero();
        cout << endl;
        cout << "Mes: ";
        mes = leerEntero();
        cout << endl;
        cout << "Anio: ";
        anio = leerEntero();
        cout << endl;
        Fecha fechaVencimiento(dia, mes, anio);
        producto = new ProductoPerecedero(nombre, precio, cantidad,
                                          fechaVencimiento);  //se aplica el principio de sustitucion Liskov
        maquina->insertar(producto);
    }
    if (perecedero == 2) {
        producto = new ProductoNoPerecedero(nombre, precio, cantidad);  //se aplica el principio de sustitucion Liskov
        maquina->insertar(producto);
    } else {
        cerr << "Opcion invalida" << endl;
    }
}

void MenuAdministrador::eliminarProducto() {
    cout << "Digite el nombre del producto: " << endl;
    string nombre;
    cin >> nombre;
    if (maquina->consultar(nombre) != nullptr && maquina->consultar(nombre)->getNombre() == nombre) {
        maquina->borrar(nombre);
    } else {
        cout << "El producto no existe en inventario" << endl;
    }
}

void MenuAdministrador::agregarProvisiones() {
    cout << "Digite el nombre del producto: " << endl;
    string nombre;
    nombre = leerCadena();
    if (maquina->consultar(nombre)->getNombre() == nombre) {
        cout << "Digite la cantidad de productos a agregar para " << maquina->consultar(nombre)->getNombre() << " :"
             << endl;
        int cantidad;
        cantidad = leerEntero();
        maquina->consultar(nombre)->setCantidad(cantidad);
        cout << "Ahora hay " << maquina->consultar(nombre)->getCantidad() << " unidades de "
             << maquina->consultar(nombre)->getNombre() << endl;
    } else {
        cerr << "El producto no existe en inventario" << endl;
    }
}

void MenuAdministrador::eliminarProvisiones() {
    cout << "Digite el nombre del producto: " << endl;
    string nombre;
    nombre = leerCadena();
    if (maquina->consultar(nombre)->getNombre() == nombre) {
        cout << "Digite la cantidad de productos a eliminar para " << maquina->consultar(nombre)->getNombre() << " :"
             << endl;
        int cantidad;
        cantidad = leerEntero();
        maquina->consultar(nombre)->setCantidad(-cantidad);
        cout << "Ahora hay " << maquina->consultar(nombre)->getCantidad() << " unidades de "
             << maquina->consultar(nombre)->getNombre() << endl;
    } else {
        cerr << "El producto no existe en inventario" << endl;
    }
}

void MenuAdministrador::ingresarDineroMaquina() {
    cout << "Ingrese la cantidad de dinero para ingresar a la maquina: " << endl;
    int dinero;
    dinero = leerEntero();
    maquina->ingresarDinero(dinero);
}

void MenuAdministrador::retirarDineroMaquina() {
    cout << "Ingrese la cantidad de dinero para retirar de la maquina: " << endl;
    int dinero;
    dinero = leerEntero();
    maquina->retirarDinero(dinero);
}

MenuAdministrador::~MenuAdministrador() {
    delete producto;
    delete maquina;
}

IMaquinaAdministradora *MenuAdministrador::getMaquina() {
    return maquina;
}

MenuAdministrador::MenuAdministrador(IMaquinaAdministradora *maquina) {
    this->maquina = maquina;
}

void MenuAdministrador::consultarCapital() {
    cout << "El capital de la maquina es: " << maquina->getCapital() << endl;
}








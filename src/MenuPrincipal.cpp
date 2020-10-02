//
// Created by diana on 7/9/2020.
//

#include"MenuPrincipal.h"
#include"Utiles.h"

void MenuPrincipal::menuPrincipal() {
    bool ciclo = true;
    string cont;

    while (ciclo) {
        cout << "Menu Principal" << endl;
        cout << "Digite la opcion que desea ejecutar: " << endl;
        cout << "[1] Menu Administrador\n[2] Menu Cobro\n[3] Salir del sistema" << endl;
        int opcion;
        opcion = leerEntero();

        switch (opcion) {
            default:
                cerr << "Opcion invalida" << endl;
                system("pause");
                system("cls");
                break;
            case 1:
                cout << "Digite la contrasennia \n";
                cin >> cont;
                if (cont == "admin") {
                    admin->mostrar();
                } else {
                    cout << "Contrasennia Incorrecta \n Ingrese de nuevo" << endl << endl;
                    system("pause");
                    system("cls");
                    break;
                }
                system("pause");
                system("cls");
                break;
            case 2:
                cobro->mostrar();
                break;

            case 3:
                ciclo = false;
                system("cls");
                break;
        }
    }
}

MenuPrincipal::~MenuPrincipal() {
    delete maquina;
    delete admin;
    delete cobro;
};
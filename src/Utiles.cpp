#include "Utiles.h"

void imprimeCadena(string cadena) {
    cout << cadena;
}

void imprimeError(string cadena) {
    cerr << cadena;
}

string leerCadena() {
    string x;
    getline(cin, x);
    return x;
}

int leerEntero() {
    int n;
    bool continuar = true;
    while (true) {
        if (cin >> n) {
            cin.clear();
            cin.ignore(1024, '\n');
            return n;
        } else {
            cerr << "Valor incorrecto.. digita UN NUMERO" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }

}

double leerDouble() {
    double n;
    bool continuar = true;
    while (true) {
        if (cin >> n) {
            cin.clear();
            cin.ignore(1024, '\n');
            return n;
        } else {
            cerr << "Valor incorrecto.. digita UN NUMERO" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }

}

void limpiaPantalla() {
    system("cls");
}

void esperandoEnter() {
    cin.get();
}

char leerChar() {
    char n;
    bool continuar = true;
    while (true) {
        if (cin >> n) {
            cin.clear(); // Limpia el estado del flujo..
            cin.ignore(1024, '\n');
            return n;
        } else {
            cerr << "Valor incorrecto.. digita UNA LETRA" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}

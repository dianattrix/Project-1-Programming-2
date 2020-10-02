//
// Created by fabiana on 08/09/2020.
//

#ifndef PROYECTO1_COLECCION_H
#define PROYECTO1_COLECCION_H
#include<cassert>
#include <vector>
using namespace std;

template <class Template>
class Coleccion {
public:
    vector<Template> coleccion;
public:

    virtual ~Coleccion();
    virtual void agregar(Template temp);
    virtual vector<Template> getColeccion();
    virtual void eliminar(int posicion);

};

template<class Template>
Coleccion<Template>::~Coleccion() {

}

template<class Template>
void Coleccion<Template>::agregar(Template temp) {
    coleccion.push_back(temp);
}

template<class Template>
vector<Template> Coleccion<Template>::getColeccion() {
    return coleccion;
}

template<class Template>
void Coleccion<Template>::eliminar(int posicion) {
    assert(!coleccion.empty());
    coleccion.erase(coleccion.begin() + posicion);

}



#endif //PROYECTO1_COLECCION_H

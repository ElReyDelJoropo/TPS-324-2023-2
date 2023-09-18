#include "arbol.hpp"
#include <iostream>

Arbol::Arbol() : _raiz(nullptr) {}
Arbol::~Arbol() { _limpiar(_raiz); }

void Arbol::insertar(int dato) { _insertarHelper(_raiz, dato); }

void Arbol::imprimir() { _imprimirHelper(_raiz); }

void Arbol::talar() { _limpiar(_raiz); }

void Arbol::_insertarHelper(NodoArbol *&nodo, int dato)
{
    if (!nodo) {
        nodo = new NodoArbol(dato);
    }

    if (dato > nodo->dato) {
        _insertarHelper(nodo->derecha, dato);
    } else if (dato < nodo->dato) {
        _insertarHelper(nodo->izquierda, dato);
    }
}

void Arbol::_imprimirHelper(NodoArbol *&nodo)
{
    if (!nodo)
        return;

    // Para imprimir el arbol en orden realizamos un recorrido infijo
    _imprimirHelper(nodo->izquierda);
    std::cout << nodo->dato << ' ';
    _imprimirHelper(nodo->derecha);
}

void Arbol::_limpiar(NodoArbol *&nodo)
{
    // Para limpiar el arbol hacemos un recorrido postfijo
    if (!nodo)
        return;

    _limpiar(nodo->derecha);
    _limpiar(nodo->izquierda);

    delete nodo;
    nodo = nullptr;
}

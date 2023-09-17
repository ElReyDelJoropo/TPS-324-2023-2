#include "listas.hpp"
#include <iostream>

Lista::Lista() : _cabeza(nullptr) {}

Lista::~Lista() noexcept
{
    auto temp = _cabeza;

    if (!_cabeza)
        return;

    while (_cabeza->next) {
        temp = _cabeza;
        _cabeza = _cabeza->next;
        delete temp;
    }

    delete _cabeza;
}

void Lista::insertar(int dato)
{
    auto temp = _cabeza;

    if (!_cabeza) {
        _cabeza = new Nodo(dato);
        return;
    }

    // Avanzamos en la lista, se podria crear otro puntero hacia la cola para
    // mejorar el rendimiento
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = new Nodo(dato);
}

void Lista::imprimir()
{
    auto temp = _cabeza;

    while (temp) {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
}

void unir(Lista &lhs, Lista &rhs) {}

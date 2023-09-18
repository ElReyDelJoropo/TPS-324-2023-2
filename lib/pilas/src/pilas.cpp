#include "pilas.hpp"
#include <iostream>

void inicializar(Tconjunto *conjunto) { conjunto->clear(); }

void introducir(Tconjunto *conjunto, Tdigitos digito)
{
    conjunto->push_back(digito);
}

void eliminar(Tconjunto *conjunto, Tdigitos digito)
{
    auto iter = conjunto->begin();
    auto end = conjunto->end();

    while (iter != end) {
        if (*iter == digito) {
            conjunto->erase(iter++);
        }
    }
}

bool pertenece(Tconjunto *conjunto, Tdigitos digito)
{
    for (auto elemento : *conjunto) {
        if (elemento == digito)
            return true;
    }
    return false;
}

int Pila::introducirElemento(Tdigitos digito)
{
    if (!pertenece(&_conjunto, digito)) {
        _elementos.push_back(digito);
        introducir(&_conjunto, digito);

        return _elementos.back();
    }

    return -1;
}

void Pila::mostrarPila()
{
    std::cout << "Desde el tope hacia el fondo:\n";
    for (auto iter = _elementos.rbegin(); iter != _elementos.rend(); ++iter) {

        std::cout << *iter << '\n';
    }
}

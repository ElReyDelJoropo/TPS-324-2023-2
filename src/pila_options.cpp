#include "pila_options.hpp"
#include "menu.hpp"
#include "pilas.hpp"

#include <iostream>

void pila_opcion_1(Pila &pila)
{
    int elemento = leerOpcion(
        "Escriba el numero (de un digito) que quiere añadir: ", std::cout);

    if (elemento < 0 || elemento >= 10) {
        std::cerr << "Elemento no valido, (" << elemento
                  << "), no se anadira a la lista\n";
        return;
    }

    if (pila.introducirElemento(elemento) == -1) {
        std::cerr
            << "El digito ya existe en la pila, intente con otro numero\n";
    }
}

void pila_opcion_2(Pila &pila) { pila.mostrarPila(); }

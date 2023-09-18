#include "arbol_options.hpp"
#include "menu.hpp"
#include <iostream>

void arbol_opcion_1(Arbol &arbol)
{
    int valor =
        leerOpcion("Ingrese el valor que quiere añadir al arbol", std::cout);

    arbol.insertar(valor);

    std::cout << "Valor ingresado satisfactoriamente\n";
}

void arbol_opcion_2(Arbol &arbol)
{
    arbol.imprimir();
    std::cout << '\n';
}

void arbol_opcion_3(Arbol &arbol)
{
    arbol.talar();
    std::cout << "Arbol talado satisfactoriamente";
}

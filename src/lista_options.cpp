#include "menu.hpp"
#include <iostream>
using std::cout;

#include "lista_options.hpp"

void lista_opcion_1(Lista &lista)
{
    int dato =
        leerOpcion("Escriba el numero que desea insertar en la lista: ", cout);

    lista.insertar(dato);

    cout << "\nElemento insertado satisfactoriamente!\n";
}

void lista_opcion_2(Lista &lista) { cout << "TODO"; }

void lista_opcion_3(Lista &lista)
{
    cout << "Lista:\n";
    lista.imprimir();
    cout << '\n';
}

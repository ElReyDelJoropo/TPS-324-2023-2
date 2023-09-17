#include "heladeria.hpp"
#include "menu.hpp"

#include <iostream>
using std::cout;

void heladeria_opcion_1(Heladeria &heladeria)
{
    int sabor = crear_menu({"Vainilla", "Fresa"}, "Escoja el sabor");
    int cantidad =
        leerOpcion("Escriba la cantidad en gramos a aumentar:", cout);

    if (cantidad <= 0)
        throw std::invalid_argument(
            "Usted ingreso una cantidad de helado nula o negativa");

    heladeria.incrementaHelado(static_cast<Sabores>(sabor - 1), cantidad);
    cout << "Helado aumentado satisfactoriamente\n";
}

void heladeria_opcion_2(Heladeria &heladeria)
{
    cout << "Sabores de helado:\n";
    for (int i = 0; i != Heladeria::CantidadDeSabores; ++i)
        cout << i + 1 << " - " << static_cast<Sabores>(i) << '\n';
    cout << "\nEscriba los sabores que desea separado por espacios: ";

    std::string input;

    std::getline(std::cin, input, '\n');

    auto sabores = Heladeria::parsearSabores(input);

    if (heladeria.esPosibleCono(sabores)) {
        cout << "Felicidades, es posible hacer un cono con esos "
                "helados, aqui tienes!\n";
    } else {
        cout << "Oh no, no hay suficiente helado para hacer un cono "
                "asi :(, intente en otra ocasion\n";
    }
}

void heladeria_opcion_3(Heladeria &heladeria) {}

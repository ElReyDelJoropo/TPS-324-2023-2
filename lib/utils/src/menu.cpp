
#include "menu.hpp"
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
using std::cin;
#include <ostream>
#include <string_view>
using std::string_view;
#include <vector>
using std::vector;

int crear_menu(std::vector<std::string_view> opciones, std::string_view header,
               std::ostream &out)
{
    out << header << '\n';
    for (std::size_t i = 0; i != opciones.size(); ++i) {
        out << i + 1 << " - " << opciones.at(i) << '\n';
    }

    int opcion = 0;

    while (opcion < 1 || opcion > opciones.size()) {
        opcion = leerOpcion("Escoja una opcion valida:", out);
    }

    return opcion;
}

int leerOpcion(string_view prompt, std::ostream &out)
{
    std::string input;

    out << prompt << ' ';
    std::getline(cin, input, '\n');
    out << '\n';

    return std::stoi(input);
}

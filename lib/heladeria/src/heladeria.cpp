#include "heladeria.hpp"
#include <array>
using std::array;

#include <ostream>
using std::ostream;

#include <sstream>
using std::istringstream;

#include <stdexcept>
#include <string>
using std::string;

ostream &operator<<(ostream &out, Sabores sabor)
{
    static array<string, Heladeria::CantidadDeSabores> nombre_sabores = {
        "chocolate", "vainilla", "fresa", "limon", "pistacho", "menta"};

    return out << nombre_sabores.at(sabor);
}

Heladeria::Heladeria() { _sabores.fill(100); }

void Heladeria::incrementaHelado(Sabores sabor, int cantidad)
{
    _sabores.at(sabor) += cantidad;
}

bool Heladeria::esPosibleCono(std::array<Sabores, 3> sabores)
{
    for (auto sabor : sabores) {
        if (_sabores.at(sabor) < 25)
            return false;
        _sabores.at(sabor) -= 25;
    }
    return true;
}

array<Sabores, 3> Heladeria::parsearSabores(string input)
{
    array<Sabores, 3> ret;
    string token;
    istringstream tokenizer;

    tokenizer.str(input);

    for (std::size_t i = 0, sabor = 0; tokenizer >> token && i != 3; ++i) {
        sabor = std::stoi(token);

        if (sabor <= 0 || sabor > Heladeria::CantidadDeSabores) {
            throw std::invalid_argument("Sabores de helado fuera de rango");
        }

        ret.at(i) = static_cast<Sabores>(sabor - 1);
    }

    return ret;
}

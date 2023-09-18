#include "heladeria.hpp"

#include <array>
#include <iostream>
#include <vector>
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
        if (_sabores.at(sabor) < 25) {
            _sabores.at(sabor) -= 25;
            return false;
        }
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

void Heladeria::conoDisponibles()
{
    std::array<int, 3> grupo;
    std::vector<std::array<int, 3>> combinaciones;
    std::array<int, 3> combinacion_actual;

    _combinacionesSaboresHelper(combinaciones, combinacion_actual, 3, 0);

    std::cout << "Sabores:()" << combinaciones.size() << '\n';
    for (auto &combinacion : combinaciones) {
        for (auto sabor : combinacion) {
            std::cout << static_cast<Sabores>(sabor) << ", ";
            // std::cout << sabor << ' ';
        }
        std::cout << '\n';
    }
}

void Heladeria::_combinacionesSaboresHelper(
    std::vector<std::array<int, 3>> &combinaciones,
    std::array<int, 3> &combinacion_actual, int tamano_grupo, int inicio)
{
    // El algoritmo se basa en lo siguiente: dado un conjunto de n elementos y
    // quiero seleccionar m elementos de ese grupo, de forma que el orden de los
    // mismos no afecta el resultado (es decir, es una combinacion), hallar los
    // k elementos que se forman, para este caso particular m = 3
    if (tamano_grupo == 0) {
        combinaciones.push_back(combinacion_actual);
        return;
    }

    for (int i = inicio; i != _sabores.size(); ++i) {
        if (_sabores[i] >= 25) {
            combinacion_actual.at(tamano_grupo - 1) = i;
            _combinacionesSaboresHelper(combinaciones, combinacion_actual,
                                        tamano_grupo - 1, i + 1);
        }
    }
}

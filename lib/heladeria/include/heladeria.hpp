#pragma once
#include <array>
#include <ostream>
#include <vector>

enum Sabores { chocolate, vainilla, fresa, limon, pistacho, menta };

extern std::ostream &operator<<(std::ostream &out, Sabores sabor);

class Heladeria {
  public:
    Heladeria();

    void incrementaHelado(Sabores sabor, int cantidad);
    bool esPosibleCono(std::array<Sabores, 3> sabores);
    void conoDisponibles();

    static std::array<Sabores, 3> parsearSabores(std::string input);

    static constexpr int CantidadDeSabores = 6;

  private:
    // Para representar los helados estoy usando un arreglo comun y corriente
    // de manera que cada elemento corresponde a un sabor, utilize una
    // enumeracion para indexar el arreglo para mejor claridad
    std::array<int, 6> _sabores;

    void
    _combinacionesSaboresHelper(std::vector<std::array<int, 3>> &combinaciones,
                                std::array<int, 3> &combinacion_actual,
                                int tamano_grupo, int inicio);
};

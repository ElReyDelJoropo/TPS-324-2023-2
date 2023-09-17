#pragma once
#include <array>
#include <ostream>

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
    std::array<int, 6> _sabores;
};

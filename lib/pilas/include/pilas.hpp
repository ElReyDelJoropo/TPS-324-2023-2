#pragma once

#include <vector>

using Tdigitos = int;
using Tconjunto = std::vector<Tdigitos>;

extern void inicializar(Tconjunto *conjunto);
extern void introducir(Tconjunto *conjunto, Tdigitos digito);
extern void eliminar(Tconjunto *conjunto, Tdigitos digito);
extern bool pertenece(Tconjunto *conjunto, Tdigitos digito);

class Pila {
  public:
    int introducirElemento(Tdigitos digito);
    void mostrarPila();

  private:
    std::vector<Tdigitos> _elementos;
    Tconjunto _conjunto;
};

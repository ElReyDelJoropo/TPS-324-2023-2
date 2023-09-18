#pragma once

/**
 * @class Lista
 * @brief Una lista enlazada simple
 *
 */
class Lista {
    friend void unir(Lista &lhs, Lista &rhs);

  public:
    Lista();
    ~Lista() noexcept;

    void insertar(int dato);
    void imprimir();

  private:
    struct Nodo {
        Nodo(int dato) : data(dato), next(nullptr) {}
        Nodo *next;
        int data;
    };

    // Lista enlazada simple
    Nodo *_cabeza;
};

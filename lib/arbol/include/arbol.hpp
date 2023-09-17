#pragma once

class Arbol {
  public:
    Arbol();
    ~Arbol();

    void insertar(int dato);
    void imprimir();

  private:
    struct NodoArbol {
        NodoArbol(int d) : dato(d), izquierda(nullptr), derecha(nullptr) {}
        NodoArbol *izquierda;
        NodoArbol *derecha;
        int dato;
    };
    void _recorridoInfijo(NodoArbol *raiz);
    void _recorridoPostfijo(NodoArbol *raiz);
    void _recorridoPrefijo(NodoArbol *raiz);

    void _insertarHelper(NodoArbol *&nodo, int dato);
    void _imprimirHelper(NodoArbol *&nodo);

    void _limpiar(NodoArbol *&nodo);

    NodoArbol *_raiz;
};

#include "arbol.hpp"
#include "arbol_options.hpp"
#include "heladeria.hpp"
#include "heladeria_options.hpp"
#include "lista_options.hpp"
#include "listas.hpp"
#include "menu.hpp"
#include "pila_options.hpp"
#include "pilas.hpp"

#include <array>
#include <cstring>
#include <iostream>
using std::cerr;
using std::cout;

#include <stdexcept>
#include <string>

using menu_fn = int (*)();

int heladeria_main();
int listas_main();
int pilas_main();
int arbol_main();

int main(int argc, char *argv[])
{
    if (argc != 2 || strcmp(argv[1], "--help") == 0) {
        cerr << "Usage: TPS_UNA_2023_2 <opcion>\nopcion: el ejercicio que "
                "desea ejecutar\nPara este caso contamos con los siguientes "
                "ejercicios:\n1 - Heladeria\n2 - Listas\n3 - Pilas 4 - Arboles";
        return 1;
    }

    int opcion = 0;

    try {
        opcion = std::stoi(argv[1]);
    } catch (std::invalid_argument const &err) {
        cerr << "Error: Argumento no valido, tiene que ser un alguno de los "
                "siguientes numero: 1,2,3\n";
        return 1;
    } catch (std::out_of_range const &err) {
        cerr << err.what();
        return 1;
    }

    if (opcion > 4 || opcion < 1) {
        cerr << "Error: Argumento no valido, tiene que ser un alguno de los "
                "siguientes numeros: 1,2,3\n";
        return 1;
    }

    std::array<menu_fn, 4> menu_dispatcher = {&heladeria_main, &listas_main,
                                              &pilas_main, &arbol_main};
    return menu_dispatcher.at(opcion - 1)();
}

int heladeria_main()
{
    cout << "Bienvenido a la heladeria de Gustavo Serrano\n";
    int result = 0;

    while (result != 4) {
        result =
            crear_menu({"Incrementar helado", "Ver si cierto cono es posible",
                        "Ver conos disponibles", "Salir"});

        Heladeria heladeria = Heladeria();

        switch (result) {
        case 1:
            heladeria_opcion_1(heladeria);
            break;
        case 2:
            heladeria_opcion_2(heladeria);
            break;
        case 3:
            heladeria_opcion_3(heladeria);
            break;
        default:
            break;
        }
    }

    return 0;
}

int listas_main()
{
    cout << "Bienvenido al programa de las listas\n";
    int result = 0;
    Lista lista = Lista();

    while (result != 4) {
        result = crear_menu(
            {"Insertar elemento", "Unir listas", "Imprimir lista", "Salir"});

        switch (result) {
        case 1:
            lista_opcion_1(lista);
            break;
        case 2:
            lista_opcion_2(lista);
            break;
        case 3:
            lista_opcion_3(lista);
            break;
        default:
            break;
        }
    }

    return 0;
}

int pilas_main()
{
    cout << "Bienvenido a las pilas mas pro del mundo\n";

    int result = 0;
    Pila pila = Pila();

    while (result != 3) {
        result = crear_menu({"Insertar elemento", "Mostrar pila", "Salir"});

        switch (result) {
        case 1:
            pila_opcion_1(pila);
            break;
        case 2:
            pila_opcion_2(pila);
            break;
        default:
            break;
        }
    }

    return 0;
}

int arbol_main()
{
    cout << "Bienvenido al programa de los arboles\n";
    int result = 0;

    Arbol arbol = Arbol();

    while (result != 4) {
        result = crear_menu(
            {"Insertar elemento", "Visualizar arbol", "Talar?", "Salir"});

        switch (result) {
        case 1:
            arbol_opcion_1(arbol);
            break;
        case 2:
            arbol_opcion_2(arbol);
            break;
        case 3:
            arbol_opcion_3(arbol);
            break;
        default:
            break;
        }
    }
    return 0;
}

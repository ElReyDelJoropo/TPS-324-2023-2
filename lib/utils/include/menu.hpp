#pragma once

#include <iostream>
#include <ostream>
#include <string_view>
#include <vector>

extern int crear_menu(std::vector<std::string_view> opciones,
                      std::string_view header = "Escoja una opcion",
                      std::ostream &out = std::cout);

extern int leerOpcion(std::string_view prompt, std::ostream &out);

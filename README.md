# TPS UNA 2023-2

<!--toc:start-->
- [TPS UNA 2023-2](#tps-una-2023-2)
  - [Ejercicios](#ejercicios)
    - [Ejercicio 1](#ejercicio-1)
    - [Ejercicio 2](#ejercicio-2)
    - [Ejercicio 3](#ejercicio-3)
    - [Ejercicio 4](#ejercicio-4)
  - [Como compilar el proyecto](#como-compilar-el-proyecto)
    - [Clonar el repositorio](#clonar-el-repositorio)
    - [Crear la carpeta build y ejecutar cmake para que se configure](#crear-la-carpeta-build-y-ejecutar-cmake-para-que-se-configure)
    - [Compilar el proyecto](#compilar-el-proyecto)
<!--toc:end-->

## Ejercicios

1. ### Ejercicio 1
Una heladería ofrece conos con bolas de 25 gramos de 3 sabores distintos a escoger
(chocolate, vainilla, fresa, limón, pistacho, menta). Construir un TAD que almacene la cantidad
disponible de cada sabor con: 

- IncrementaHelado: añade una cantidad de helado a un sabor
- EsPosibleCono: recibe como entrada 3 sabores e indica si hay helado suficiente para
el cono
- ConoDisponible: Imprime por pantalla que tipos de conos pueden confeccionarse con
Los helados disponibles

2. ### Ejercicio 2
Realice un programa en C++ que permita insertar elementos en una lista, unir las listas,
mostrar los elementos de la lista y poder salir del programa. Para ingresar el programa se
debe pedir que el usuario ingrese el número de opción que desea conocer.

3. ### Ejercicio 3
Construir un TAD pila en el que se van a introducir números enteros positivos de un dígito.
Para ello se dispone del TAD conjunto, de enteros de dos dígitos en el que se han definido las
siguientes operaciones:
- Tdigitos = 0..99
- Tconjunto = 10..99
- `void Inicializar(Tconjunto *conjunto)`
- `void Introducir(Tconjunto *conjunto, Tdígitos dígito)`
- `void Eliminar(Tcojunto *conjunto)`
- `bool Pertenece (Tconjunto conjunto, Tdígitos dígito)` Se pide implementar la operación introducir un elemnto en la pila usando el TAD conjunto.

4. ### Ejercicio 4
Hacer un programa en C++ que permita mostrar todos los elementos de un árbol (ABB) y
talar el árbol (ABB). El programa contiene un menú de 4 opciones: Ingresar elementos,
visualizar árbol, talar y salir.

---

## Como compilar el proyecto
El proyecto usa [Cmake](https://cmake.org/) como build system, asi que asegurense de tenerlo instalado antes de iniciar con los pasos

1. ### Clonar el repositorio
```bash
git clone https://github.com/ElReyDelJoropo/TPS-324-2023-2.git
cd TPS-324-2023-2
```

2. ### Crear la carpeta build y ejecutar cmake para que se configure
```bash
mkdir build
cd build
cmake ..
```

3. ### Compilar el proyecto
```bash
cd ..
cmake --build build
```
Con eso obtendriamos nuestro ejecutable en la carpeta build/

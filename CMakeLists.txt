cmake_minimum_required(VERSION 3.17)
project(Proyecto1)

##project(progra2-project-01-python)

set(CMAKE_CXX_STANDARD 14)
add_executable(Proyecto1 src/main.cpp src/IMaquinaAdministradora.h src/MonederoElectronico.h src/Maquina.h src/IMaquinaVendedora.h src/Fecha.cpp src/Fecha.h src/Maquina.cpp src/MonederoElectronico.cpp src/Producto.h src/Producto.cpp src/ProductoPerecedero.h src/ProductoPerecedero.cpp src/ProductoNoPerecedero.h src/ProductoNoPerecedero.cpp src/MenuCobro.cpp src/MenuCobro.h src/MenuAdministrador.h src/MenuAdministrador.cpp src/MenuPrincipal.h src/MenuPrincipal.cpp src/Coleccion.h src/Utiles.h src/Utiles.cpp)


## Use next line if you are going to use Google Test


##include_directories(src)
##add_subdirectory(src)
##add_subdirectory(tst)

## Use next line if you are going to use Google Test

##add_subdirectory(lib/googletest)

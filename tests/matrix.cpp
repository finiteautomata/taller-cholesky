#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include "catch.hpp"
#include "../src/matrix.h"

using namespace std;

TEST_CASE( "Si creo una matriz con constructor por defecto", "[Matrix]" ) {
    auto matrix = Matriz(3, 3);

    SECTION("todos sus valores deben ser cero") {
        for (int i = 0; i < 3; ++i)
            for (int j= 0; j < 3; ++j)
                REQUIRE(matrix(i, j) == Approx(0));
    }
}


TEST_CASE( "Si creo una matriz con un vector de vectores", "[Matrix]" ) {
    SECTION(" y es correcta debe asignar los valores correspondientes") {
        auto matrix = Matriz({
            {1.0, 0.0},
            {0.0, 1.0}
        });
        REQUIRE(matrix(0, 0) == Approx(1));
        REQUIRE(matrix(0, 1) == Approx(0));
        REQUIRE(matrix(1, 0) == Approx(0));
        REQUIRE(matrix(1, 1) == Approx(1));
    }

    SECTION("y es una matriz inválida debe tirar excepcion") {
        REQUIRE_THROWS(Matriz({{1.0, 0.0}, {0.0}}));
    }
}

TEST_CASE( "Si creo una matriz por copia", "[Matrix]" ) {
    SECTION("debe asignar los mismos valores") {
        Matriz id({
            {1.0, 0.0},
            {0.0, 1.0}
        });

        auto matrix(id);

        REQUIRE(matrix(0, 0) == Approx(1));
        REQUIRE(matrix(0, 1) == Approx(0));
        REQUIRE(matrix(1, 0) == Approx(0));
        REQUIRE(matrix(1, 1) == Approx(1));
    }
}


TEST_CASE( "Igualdad entre matrices", "[Matrix]" ) {
    Matriz mat1({
        {1.0, 0.0},
        {0.0, 1.0}
    });

    SECTION("de distinta dimensión debe dar falso") {

        Matriz mat2({
            {1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0},
        });

        REQUIRE(!(mat1 == mat2));
    }
}

TEST_CASE( "Asignando un valor", "[Matrix]" ) {
    Matriz mat({
        {1.0, 0.0},
        {0.0, 1.0}
    });

    SECTION("tengo que poder accederlo luego") {
        mat(0, 1) = 3;

        REQUIRE(mat(0, 1) == Approx(3));
    }
}

TEST_CASE("Probar esCuadrada", "[Matrix]") {

    SECTION("si la matriz es cuadrada, debe dar verdadero") {
        Matriz mat({
            {1.0, 0.0},
            {0.0, 0.0}
        });

        REQUIRE(mat.esCuadrada());
    }


    SECTION("si la matriz no es cuadrada, debe dar falso") {
        Matriz mat({
            {1.0, 0.0, 0.0},
            {0.0, 0.0, 1.0}
        });

        REQUIRE(!mat.esCuadrada());
    }
}

#include "catch.hpp"
#include "../src/cholesky.h"


TEST_CASE("esSimetrica", "") {

    SECTION("Matriz Diagonal Positiva") {
        Matriz M1({
            {4.0, 0.0},
            {0.0, 9.0},
        });

        REQUIRE(esSimetrica(M1));
    }
}


TEST_CASE( "Cholesky ", "" ) {
    SECTION("Matriz diagonal positiva") {

        Matriz M1({
            {4.0, 0.0},
            {0.0, 9.0},
        });


        Matriz L({
            {2.0, 0.0},
            {0.0, 3.0},
        });

        auto res = cholesky(M1);

        REQUIRE(res == L);
    }

    SECTION("Segundo test") {
        Matriz A1_test({
            {5.99246,   0.45174,   0.50921,   0.45632,   0.41578},
            {0.45174,   5.02065,   0.40611,   0.52172,   0.11483},
            {0.50921,   0.40611,   5.25767,   0.78430,   0.24938},
            {0.45632,   0.52172,   0.78430,   5.98219,   0.45188},
            {0.41578,   0.11483,   0.24938,   0.45188,   5.28701}
        });

        Matriz L1_test({
            {2.44795,   0.00000,   0.00000,   0.00000,   0.00000},
            {0.18454,   2.23307,   0.00000,   0.00000,   0.00000},
            {0.20802,   0.16467,   2.27756,   0.00000,   0.00000},
            {0.18641,   0.21823,   0.31156,   2.40889,   0.00000},
            {0.16985,   0.03739,   0.09128,   0.15925,   2.28540}
        });

        Matriz L1 = cholesky(A1_test);

        REQUIRE(L1 == L1_test);
    }

    SECTION("Matriz no es simétrica") {
        Matriz A3_test({
          {0.066076,   0.181880},
          {1.181880,   0.624953}
        });

        REQUIRE_THROWS(cholesky(A3_test));
    }

    SECTION("Matriz no SDP") {
        Matriz A4_test({
          {-0.066076,   0.181880},
          { 0.181880,   0.624953}
        });

        REQUIRE_THROWS(cholesky(A4_test));
    }
}

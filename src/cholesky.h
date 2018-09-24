#include "matrix.h"


/// 1) esSimetrica
// Completar la función esSimetrica.
// Recibe una matriz A y devuelve un booleano.
// Devuelve true si y solo si la matriz es simétrica.
// Tratar de minimizar la cantidad de comparaciones.

bool esSimetrica(const Matriz& A);

/// 2) Cholesky
// Completar la función que calcula la factorización de cholesky.
// Recibe una matriz A y debe devolver una nueva matriz con la L de cholesky.
// Debe chequear que la matriz sea cuadrada, simétrica, y luego
// durante el algoritmo agregar los chequeos necesarios donde haga falta.
// En cualquier caso que falle, debe lanzar una excepción con el mensaje
// "Matriz no SDP."
Matriz cholesky(const Matriz &A);

/// 3) Multiplica A por A'
// Completar la función multiplicarPorTraspuesta.
// Toma una matriz A y devuelve una nueva matriz con
// el resultad de hacer A * A'.
// Tratar de minimizar la cantidad de operaciones.
// Considerar que (A * A')' = A'' * A' = A * A'
Matriz multiplicarPorTraspuesta(const Matriz& A);

#include "matrix.h"
#include <stdexcept>
#include <iomanip>
#include <cmath>

using namespace std;



Matriz::Matriz(int n, int m): values(n, vector<float>(m, .0)) {
}

Matriz::Matriz(const vector< vector<float>>& mat): values(mat) {
    // Chequear que es una matriz válida

    if (values.size() > 1) {
        unsigned M = values[0].size();

        for (unsigned j=1; j < values.size(); ++j) {
            if (values[j].size() != M)
                throw runtime_error("Matriz Invalida!");
        }
    }
}
Matriz::Matriz(const Matriz&mat): values(mat.values) {}

const float& Matriz::operator()(unsigned i, unsigned j) const {
    return values[i][j];
}


float& Matriz::operator()(unsigned i, unsigned j) {
    return values[i][j];
}

bool Matriz::esCuadrada() const {
    return false;
}


bool Matriz::operator==(const Matriz& mat) const{
    if (filas() !=  mat.filas() || columnas() != mat.columnas())
        return false;

    for (unsigned i = 0; i < filas(); ++i)
        for (unsigned j = 0; j < columnas(); ++j)
            if (!eq(values[i][j], mat(i, j)))
                return false;
    return true;
}


ostream& operator<<(ostream& os, const Matriz& A) {
  for(unsigned i=0; i< A.filas(); i++) {
    for(unsigned j=0; j< A.columnas(); j++) {
      os << setprecision(4) << A(i, j) << "\t";
    }
    os << "\n";
  }
  return os;
}

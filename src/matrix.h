#ifndef __MATRIX_H
#define __MATRIX_H
#include <vector>
#include <iostream>
#include <iomanip>


const double eps = 1e-5;

inline bool eq(double a, double b) { return abs(a-b)<eps; }


class Matriz {
public:
    Matriz(int n, int m);
    Matriz(const std::vector< std::vector<float>>& );
    Matriz(const Matriz&);

    float& operator()(unsigned i, unsigned j);
    const float& operator()(unsigned i, unsigned j) const;

    bool operator==(const Matriz&) const;

    bool esCuadrada() const;

    unsigned filas() const { return values.size(); }
    unsigned columnas() const { return values[0].size(); }
private:
    std::vector< std::vector<float>> values;

};

std::ostream& operator<<(std::ostream& os, const Matriz& A);

#endif

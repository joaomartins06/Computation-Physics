//
// Created by joao_martins on 14-06-2023.
//

#include "Xvar.h"

Xvar :: Xvar(vector<double> vetor): x(vetor){;}

Xvar ::Xvar(initializer_list<double> & inicializador){
    x = inicializador;
}

Xvar ::Xvar(const Xvar& ponto): x(ponto.x){;}

vector <double>& Xvar ::X() {
    return x;
}

Xvar& Xvar :: operator= (const Xvar& ponto){
    if (this != &ponto){
        x = ponto.x;
    }
    return *this;
}

Xvar Xvar :: operator+(const Xvar& other){
    Xvar resultado(*this);
    for (int i = 0; i < x.size(); i++){
        resultado[i] += other.x[i];
    }
    return resultado;
}

double& Xvar :: operator[](int i){
    return x[i];
}

Xvar operator*(double scalar, const Xvar& other){
    Xvar resultado(other);
    for (int i = 0; i < resultado.X().size(); i++){
        resultado.X()[i] *= scalar;
    }
    return resultado;
}

ostream& operator<<(ostream& os, const Xvar& obj) {
    os << "[ ";
    for (const double& value : obj.x) {
        os << value << " ";
    }
    os << "]" << endl;
    return os;
}




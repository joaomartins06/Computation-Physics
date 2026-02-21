//
// Created by joao_martins on 14-06-2023.
//

#ifndef HW5_XVAR_H
#define HW5_XVAR_H
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Xvar {
protected:
    vector <double> x;

public:
    Xvar() = default;
    Xvar(int);
    Xvar(vector <double>);
    Xvar(initializer_list<double>&);
    ~Xvar() = default;
    vector <double>& X();
    Xvar(const Xvar&);
    Xvar& operator=(const Xvar&);
    Xvar operator+ (const Xvar&);
    double& operator[](int);
    friend Xvar operator*(double, const Xvar&);
    friend ostream& operator<< (ostream&, const Xvar&);

};


#endif //HW5_XVAR_H

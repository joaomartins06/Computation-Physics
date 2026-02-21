//
// Created by joao_martins on 14-06-2023.
//

#ifndef HW5_ODEPOINT_H
#define HW5_ODEPOINT_H

#include <iostream>
#include "Xvar.h"
#include <functional>
#include <vector>

using namespace std;

class ODEpoint: public Xvar{
private:
    double time;

public:
    ODEpoint();
    ODEpoint(double, Xvar);
    ODEpoint(double, const vector<double>&);
    ODEpoint(double, const initializer_list<double>&);
    void SetODEpoint(double, Xvar&);
    void SetODEpoint(double, const initializer_list<double>&);
    void SetODEpoint(double, const vector<double>);
    double& T();
    friend ostream& operator << (ostream&, const ODEpoint&);
};


#endif //HW5_ODEPOINT_H

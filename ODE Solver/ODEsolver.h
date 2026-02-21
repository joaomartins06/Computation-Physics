//
// Created by joao_martins on 14-06-2023.
//

#ifndef HW5_ODESOLVER_H
#define HW5_ODESOLVER_H
#include "ODEpoint.h"
#include <iostream>
#include <functional>
#include <map>

class ODEsolver {
protected:
    vector <function<double(ODEpoint)>> F;
    map <string, vector<ODEpoint>> MS;

public:
    ODEsolver(const vector<function<double(ODEpoint)>>&);
    ~ODEsolver() = default;

    void SetODEfunc(const vector<function<double(ODEpoint)>>&);

    const vector<ODEpoint>& Euler(ODEpoint, double, double);
    const vector<ODEpoint>& PredictorCorrector(ODEpoint, double, double);
    const vector<ODEpoint>& LeapFrog(ODEpoint, double, double);
    const vector<ODEpoint>& RK2(ODEpoint, double, double);
    const vector<ODEpoint>& RK4(ODEpoint, double, double);
};


#endif //HW5_ODESOLVER_H

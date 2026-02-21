//
// Created by joao_martins on 14-06-2023.
//

#include "ODEpoint.h"

ODEpoint ::ODEpoint() {time = -1;}

ODEpoint ::ODEpoint(double t, Xvar a): time(t), Xvar(a){;}

ODEpoint ::ODEpoint(double t, const vector <double>& v):time(t), Xvar(v){;}

ODEpoint ::ODEpoint(double t, const initializer_list<double>& v): time(t), Xvar(v){;}

void ODEpoint ::SetODEpoint(double t, Xvar& a){
    time = t;
    x = a.X();
}

void ODEpoint ::SetODEpoint(double t, const initializer_list<double>& v){
    time = t;
    x = v;
}

void ODEpoint ::SetODEpoint(double t, const vector<double> v){
    time = t;
    x = v;
}

double& ODEpoint :: T(){
    return time;
}






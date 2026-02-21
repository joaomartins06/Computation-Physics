//
// Created by joao_martins on 14-06-2023.
//

#include "ODEsolver.h"

ODEsolver ::ODEsolver(const vector<function<double(ODEpoint)>>& funcs):F(funcs){}

void ODEsolver ::SetODEfunc(const vector<function<double(ODEpoint)>>& funcs){
    F = funcs;
}

const vector<ODEpoint>& ODEsolver :: Euler (ODEpoint i, double step, double T){

    double t = i.T();
    vector <ODEpoint> V;
    V.push_back(i);
    while (t < T){
        ODEpoint Pcurr = V.back();
        //V.push_back(ODEpoint(t+step, {Pcurr.X()[0]+ step * F[0](Pcurr), Pcurr.X()[1] + step * F[1](Pcurr)}));
        vector <double> vetor;
        for (int j = 0; j < F.size(); j++){
            vetor.push_back(Pcurr.X()[j] + step*F[j](Pcurr));
        }
        V.push_back(ODEpoint(t+step, vetor));
        t+= step;
    }
    MS["Euler"] = V;
    return MS["Euler"];
}

const vector<ODEpoint>& ODEsolver :: PredictorCorrector(ODEpoint i, double step, double T){
    double t = i.T();
    vector<ODEpoint> V;
    V.push_back(i);
    while (t < T){
        ODEpoint Pcurr = V.back();
        vector <double> vetor1;
        for (int j = 0; j < F.size(); j++){
            vetor1.push_back(Pcurr.X()[j] + step*F[j](Pcurr));
        }
        ODEpoint Pnext (t+step, vetor1);
        vector <double> vetor2;
        for (int j = 0; j < F.size(); j++){
            vetor2.push_back(Pcurr.X()[j] + 0.5*step*(F[j](Pcurr)+ F[j](Pnext)));
        }
        V.push_back(ODEpoint(t+step, vetor2));
        t += step;
    }
    MS["PredictorCorrector"] = V;
    return MS["PredictorCorrector"];
}

const vector<ODEpoint>& ODEsolver :: LeapFrog(ODEpoint i, double step, double T){
    double t = i.T();
    vector <ODEpoint> V;
    V.push_back(i);
    vector <double> vetor1;
    for (int j = 0; j < F.size(); j++){
        vetor1.push_back(i.X()[j] + step*F[j](i));
    }
    t+=step;
    V.push_back(ODEpoint(t, vetor1));
    while (t < T){
        ODEpoint P1 = V.back();
        ODEpoint P2 = V[V.size()-2];
        vector <double> vetor2;
        for (int j = 0; j < F.size(); j++){
            vetor2.push_back(P2.X()[j] + 2*step*F[j](P1));
        }
        V.push_back(ODEpoint(t+step, vetor2));
        t += step;
    }
    MS["LeapFrog"] = V;
    return MS["LeapFrog"];
}

const vector<ODEpoint>& ODEsolver :: RK2(ODEpoint i, double step, double T){
    double t = i.T();
    vector <ODEpoint> V;
    V.push_back(i);
    while (t < T){
        ODEpoint Pcurr = V.back();
        vector <double> vetor1;
        for (int j = 0; j < F.size(); j++){
            vetor1.push_back(Pcurr.X()[j] + 0.5*step*F[j](Pcurr));
        }
        ODEpoint intermidate(t+step*0.5, vetor1);
        vector <double> vetor2;
        for(int j = 0; j < F.size(); j++){
            vetor2.push_back(Pcurr.X()[j] + step*F[j](intermidate));
        }
        V.push_back(ODEpoint(t+step, vetor2));
        t += step;
    }
    MS["RK2"] = V;
    return MS["RK2"];
}

const vector<ODEpoint>& ODEsolver :: RK4(ODEpoint i, double step, double T){
    double t = i.T();
    vector <ODEpoint> V;
    V.push_back(i);

    while (t < T){
        ODEpoint Pcurr = V.back();

        vector <double> vetor1;
        for (int j = 0; j < F.size(); j++){
            double K1 = step*F[j](Pcurr);
            vetor1.push_back(Pcurr.X()[j] + K1/2);
        }
        ODEpoint intermediate2(t + step*0.5, vetor1);

        vector <double> vetor2;
        for (int j = 0; j < F.size(); j++){
            double K2 = step*F[j](intermediate2);
            vetor2.push_back(Pcurr.X()[j]+K2/2);
        }
        ODEpoint intermediate3 (t+step/2, vetor2);

        vector <double> vetor3;
        for (int j = 0; j < F.size(); j++){
            double K3 = step * F[j](intermediate3);
            vetor3.push_back(Pcurr.X()[j] + K3);
        }
        ODEpoint intermediate4 (t+step, vetor3);

        vector <double> vetor4;
        for (int j = 0; j < F.size(); j++){
            double K1 = step*F[j](Pcurr);
            double K2 = step * F[j](intermediate2);
            double K3 = step * F[j](intermediate3);
            double K4 = step * F[j](intermediate4);
            vetor4.push_back(Pcurr.X()[j] + (K1+2*K2+2*K3+K4)/6);
        }
        V.push_back(ODEpoint(t+step, vetor4));
        t += step;
    }
    MS["RK4"] = V;
    return MS["RK4"];
}




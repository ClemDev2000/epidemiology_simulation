#include <iostream>
#include <fstream>

#include "graphe.hpp"
#include "modele.hpp"
#include "sir.hpp"
#include "seir.hpp"
#include "solveur.hpp"
#include "euler_ex.hpp"
#include "rk2.hpp"

using namespace std;

void display(valarray<double> va)
{
    int size = va.size();
    cout << "[ ";
    for (int i = 0; i < size; ++i)
        cout << va[i] << " ";
    cout << "]" << endl;
}

int main() {
    double beta = 0.6;
    double gamma = 0.2;
    double dt = 1;
    int njour = 200;

    valarray<double> X0(3);
    double S0 = 0.999;
    double I0 = 1-S0;
    double R0 = 0;
    X0[0] = S0;
    X0[1] = I0;
    X0[2] = R0;

    sir SIRModele(beta, gamma, 0, 0, 0);
    SIRModele.setX(X0);

    euler_ex solv;
    solv.setModele(&SIRModele);
    solv.setDt(dt);
    solv.initSolutions();

    for (int i = 0; i < njour; ++i)
    {
        solv.applique();
    }
    display(solv.getVector());
    return 0;
}

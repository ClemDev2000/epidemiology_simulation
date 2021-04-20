#ifndef SEIR_HPP
#define SEIR_HPP

#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <valarray>
#include "modele.hpp"
using namespace std;

class seir: public modele
{
private:
    double beta;
    double gamma;
    double alpha;
    double nu;
    double mu;
    double g;
public:
    seir();
    seir(double be, double ga, double al, double n, double m, double g1);
    valarray<double> computeFlux(valarray<double> vec) override;
};

seir::seir() : modele(4)
{
    beta = 0;
    gamma = 0;
    alpha = 0;
    nu = 0;
    mu = 0;
    g = 0;
}

seir::seir(double be, double ga, double al, double n, double m, double g1) : modele(4)
{
    beta = be;
    gamma = ga;
    alpha = al;
    nu = n;
    mu = m;
    g = g1;
}

valarray<double> seir::computeFlux(valarray<double> vec)
{
    valarray<double> res(4);
    double S = vec[0];
    double E = vec[1];
    double I = vec[2];
    double R = vec[3];
    res[0] = (-beta*S*E-(nu+g)*S+mu*(S+I+R));
    res[1] = (beta*S*E-alpha*E-(g+nu)*E);
    res[2] = (alpha*E-gamma*I-(nu+g)*I);
    res[3] = (gamma*I-(nu+g)*R);
    return res;
}

#endif
#ifndef SIR_HPP
#define SIR_HPP

#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <valarray>
#include "modele.hpp"
using namespace std;

class sir: public modele
{
private:
    double beta;
    double gamma;
    double mu;
    double nu;
    double g;
public:
    sir();
    sir(double be, double ga, double m, double n, double g1);
    valarray<double> computeFlux(valarray<double> vec) override;
};

sir::sir() : modele(3)
{
    beta = 0;
    gamma = 0;
    mu = 0;
    nu = 0;
    g = 0;
}

sir::sir(double be, double ga, double m, double n, double g1) : modele(3)
{
    beta = be;
    gamma = ga;
    mu = m;
    nu = n;
    g = g1;
}

valarray<double> sir::computeFlux(valarray<double> vec)
{
    valarray<double> res(3);
    double S = vec[0];
    double I = vec[1];
    double R = vec[2];
    res[0] = (-beta*S*I-(nu+g)*S+mu*(S+I+R));
    res[1] = (beta*S*I-gamma*I-(nu+g)*I);
    res[2] = (gamma*I-(nu+g)*R);
    return res;
}

#endif
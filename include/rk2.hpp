#ifndef RK2_HPP
#define RK2_HPP

#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <valarray>
#include "modele.hpp"
#include "rk2.hpp"
using namespace std;

class rk2 : public solveur
{
public:
    rk2();
    void applique() override;
};

rk2::rk2() : solveur()
{
}

void rk2::applique()
{
    valarray<double> Xn = variables.back();
    valarray<double> fluxXn = mod->computeFlux(Xn);

    valarray<double> Xnp12 = 0.5 * fluxXn * dt + Xn;

    valarray<double> fluxXnp12 = mod->computeFlux(Xnp12);
    valarray<double> Xnp1 = 0.5 * fluxXnp12 * dt + Xn;

    variables.push_back(Xnp1);
}

#endif
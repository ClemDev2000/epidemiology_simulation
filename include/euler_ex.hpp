#ifndef EULER_EX_HPP
#define EULER_EX_HPP

#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <valarray>
#include "modele.hpp"
#include "solveur.hpp"
using namespace std;

class euler_ex : public solveur
{
public:
    euler_ex();
    void applique() override;
};

euler_ex::euler_ex() : solveur()
{
}

void euler_ex::applique()
{
    valarray<double> Xn = variables.back();
    valarray<double> fluxXn = mod->computeFlux(Xn);
    valarray<double> Xnp1 = fluxXn * dt + Xn;
    variables.push_back(Xnp1);
}

#endif
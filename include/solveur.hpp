#ifndef SOLVEUR_HPP
#define SOLVEUR_HPP

#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <valarray>
#include "modele.hpp"
using namespace std;

class solveur
{
protected:
    double dt;
    vector<valarray<double>> variables;
    modele *mod;

public:
    solveur();
    void setModele(modele *m);
    void setDt(double t);
    virtual void applique() = 0;
    void initSolutions();
    valarray<double> getVector();
    double getCurrentTime();
};

solveur::solveur()
{
    dt = 0;
    mod = nullptr;
}

void solveur::setModele(modele *m)
{
    mod = m;
}

void solveur::setDt(double t)
{
    dt = t;
}

void solveur::initSolutions()
{
    variables.push_back(mod->getX());
}

valarray<double> solveur::getVector()
{
    return variables.back();
}

double solveur::getCurrentTime()
{
    return variables.size();
}

#endif
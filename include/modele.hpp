#ifndef MODELE_HPP
#define MODELE_HPP

#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <valarray>
using namespace std;

class modele
{
protected:
    int n;
    valarray<double> X;
public:
    modele();
    modele(int si);
    valarray<double> getX();
    void setX(valarray<double> X0);
    virtual valarray<double> computeFlux(valarray<double> vec)=0;
};

modele::modele()
{
    n = 0;
    X.resize(n);
}

modele::modele(int si)
{
    n = si;
    X.resize(n);
}

valarray<double> modele::getX()
{
    return X;
}

void modele::setX(valarray<double> X0)
{
    X = X0;
}

#endif
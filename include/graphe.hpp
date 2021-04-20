#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include <cmath>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class voisin
{
  int number;
  double poids;

public:
  voisin()
  {
    poids = 0.0;
    number = 0;
  };
  voisin(const voisin &n)
  {
    poids = n.poids;
    number = n.number;
  };
  ~voisin(){};
  int num()
  {
    return number;
  }
  double p()
  {
    return poids;
  }
  void set_num(int a)
  {
    number = a;
  }
  void set_p(double a)
  {
    poids = a;
  }
};

template <class T>
class noeud
{
  T val;
  int number;
  vector<voisin> voisins;

public:
  noeud()
  {
    val = T();
    number = 0;
  };
  noeud(const noeud &n)
  {
    val = n.val;
    number = n.number;
    voisins = n.voisins;
  };
  ~noeud()
  {
    voisins.clear();
  };
  void ajout_val(T x)
  {
    val = x;
  }
  void ajout_num(int n)
  {
    number = n;
  }

  vector<voisin> get_voisins()
  {
    return voisins;
  }

  T get_val()
  {
    return val;
  }

  int num()
  {
    return number;
  }
  void ajout_voisin(int nbnoeud, double p)
  {
    voisin v;
    v.set_num(nbnoeud);
    v.set_p(p);
    voisins.push_back(v);
  }
  void supprime_voisin(int nbnoeud)
  {
    vector<voisin>::iterator pos;

    for (pos = voisins.begin(); pos != voisins.end(); pos++)
    {
      if (pos->num() == nbnoeud)
        break;
    }
    if (pos != voisins.end())
    {
      voisins.erase(pos);
    }
  }
  noeud &operator=(const noeud &n)
  {
    if (this != &n)
    {
      voisins.clear();
      val = n.val;
      voisins = n.voisins;
      number = n.number;
    }
    return *this;
  }
  bool operator==(const noeud &n)
  {
    bool res = false;
    res = (val == n.val) && (n.number == number);
    return res;
  }

  template <class U>
  friend ostream &operator<<(ostream &out, noeud<U> &x);
};

template <class T>
class graphe
{
  vector<noeud<T> *> noeuds;
  int nbnodes;

public:
  graphe()
  {
    nbnodes = 0;
  };
  graphe(const graphe &a)
  {
    noeuds = a.noeuds;
    nbnodes = a.nbnodes;
  };
  ~graphe()
  {
    noeuds.clear();
  };

  int get_nbnodes()
  {
    return nbnodes;
  }

  noeud<T> *get_noeud(int i)
  {
    return noeuds[i];
  }

  void ajout_noeud(noeud<T> *n)
  {
    n->ajout_num(nbnodes);
    noeuds.push_back(n);
    nbnodes++;
  }
  void supprime_noeud(noeud<T> &n)
  {
    typename vector<noeud<T> *>::iterator pos;

    for (int i = 0; i < noeuds.size(); i++)
    {
      noeuds[i]->supprime_voisin(n.num());
    }

    pos = find(noeuds.begin(), noeuds.end(), &n);
    if (pos != noeuds.end())
    {
      noeuds.erase(pos);
    }
    nbnodes--;
  }
  template <class U>
  friend ostream &operator<<(ostream &out, graphe<U> &x);
};

template <class T>
ostream &operator<<(ostream &out, noeud<T> &x)
{
  vector<voisin>::iterator ii;
  int nvoisins = 0;

  out << " noeuf numero: " << x.number << "  de valeur " << x.val << endl;
  if (x.voisins.size() != 0)
  {
    out << ">>>>> liste des voisins:" << endl;
    for (ii = x.voisins.begin(); ii != x.voisins.end(); ii++)
    {
      out << " voisins n" << nvoisins << " :" << ii->num() << endl;
      nvoisins++;
    }
  }
  return out;
}

template <class T>
ostream &operator<<(ostream &out, graphe<T> &x)
{
  int nnoeud = 0;
  int i = 0;

  if (x.noeuds.size() != 0)
  {
    cout << ">>>> list des noeuds" << endl;
    for (i = 0; i < x.noeuds.size(); i++)
    {
      out << " node n" << x.noeuds[i]->num() << " :" << *x.noeuds[i] << endl;
      nnoeud++;
    }
  }
  else
  {
    cout << ">>>>  graphe nul" << endl;
  }

  return out;
}

#endif

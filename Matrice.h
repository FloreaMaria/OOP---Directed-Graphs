#pragma once
#include <iostream>
#include <vector>
#include "Graf.h"



class Matrice
{
    bool ** matrice;
    int n, m;
    std::pair<int, int> V[1000];
public:

    Matrice();                                          ///constructor
    Matrice(int, int, std::pair<int, int>[]);            /// constructor parametri
    Matrice(const Matrice&);                            /// copy-constructor
    virtual ~Matrice();                             /// destructor

    void Afisare();

    bool ** getStart() const
    {
        return this -> matrice;
    }

    void  setStart(bool ** ptr)
    {
        this -> matrice = ptr;
    }

    int getNode() const
    {
        return this -> n;
    }

    void setNode(int const& nod)
    {
        this -> n = nod;
    }

    int getEdge() const
    {
        return this -> m;
    }

    void setEdge(int const& muchie)
    {
        this -> m = muchie;
    }

   void setEdges(std::pair<int, int> K[1000])
    {
        for(int i = 1; i <= m; i++)
        {

            V[i].first = K[i].first;
            V[i].second = K[i].second;

        }
    }
    void getEdges()
    {

         for(int i = 1; i <= m; i++)
        {
            std:: cout << V[i].first << " " << V[i].second << "\n";
        }

    }


    friend std::istream& operator >> (std::istream&, Matrice&);
    friend std::ostream& operator << (std::ostream&, Matrice&);
    Matrice& operator = (Matrice&);

};



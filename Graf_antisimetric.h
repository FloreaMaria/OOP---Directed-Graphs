#pragma once
#include "Graf.h"
#include "Matrice.h"
#include <iostream>


class Graf_antisimetric : virtual public Graf
{
    Matrice M;

public:

    Graf_antisimetric();
    Graf_antisimetric(Matrice M);
    Graf_antisimetric(const Graf_antisimetric&);

    Matrice getM()
    {
        return M;
    }

    void setM(Matrice A)
    {
        this -> M = A;
    }

    void display()
    {
        std :: cout << getNod() << " " << M.getEdge() << "\n";
        std :: cout << M;

    }

    void AfisareArce();

    friend std :: istream& operator >> (std :: istream&, Graf_antisimetric*);
    friend std :: ostream& operator << (std :: ostream&, Graf_antisimetric*);
    Graf_antisimetric& operator = (Graf_antisimetric&);

    virtual ~Graf_antisimetric();


};


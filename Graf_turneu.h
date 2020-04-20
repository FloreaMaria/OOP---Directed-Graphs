#pragma once
#include "Graf_complet.h"
#include "Graf_antisimetric.h"
#include <iostream>

class Graf_turneu :  public Graf_complet, public Graf_antisimetric
{

    public:

        Graf_turneu();
        Graf_turneu(Matrice A);
        Graf_turneu(const Graf_turneu&);

        void display()
        {
            std :: cout << getNod() << " " << getMuchii() << "\n";
            Matrice A = getM();
            std :: cout << A;
        }


        Graf_turneu& operator = (Graf_turneu &);
        friend std :: istream& operator >> (std :: istream&, Graf_turneu*);
        friend std :: ostream& operator << (std :: ostream&, Graf_turneu*);
        virtual ~Graf_turneu();

};



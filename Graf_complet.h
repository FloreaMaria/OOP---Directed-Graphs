#pragma once
#include "Graf.h"



class Graf_complet : virtual public Graf
{
    int  nr_muchii;

public:

    Graf_complet();
    Graf_complet(int noduri);
    Graf_complet(const Graf_complet&);

    int getMuchii(){
        return this -> nr_muchii;
    }
    void setMuchii(int m){
        this -> nr_muchii = m;
    }

    void display(){
        std:: cout << getNod() << " " << nr_muchii << "\n";
    }

    ~Graf_complet();

    Graf_complet& operator = (Graf_complet&);
    friend std :: istream& operator >> (std :: istream&, Graf_complet*);
    friend std :: ostream& operator << (std :: ostream&, Graf_complet*);

};


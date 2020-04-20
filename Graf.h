
#pragma once
#include "Matrice.h"
#include <iostream>
#include "Exceptions.h"
#include "Invalid.h"

class Graf
{
        int nr_noduri;

public:

    Graf() ;
    Graf(int nr_noduri);
    Graf(const Graf&);
    Graf& operator = (const Graf&);

    int getNod(){
        return nr_noduri;
    }
    void setNod(int n){
        this -> nr_noduri = n;
    }

    friend std :: istream& operator >> (std :: istream&, Graf*);
    friend std :: ostream& operator << (std :: ostream&, Graf*);
    virtual ~Graf();
    virtual void display() = 0;


};

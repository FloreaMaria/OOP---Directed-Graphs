#include <iostream>
#include "Matrice.h"
#include "Graf.h"
#include <vector>
#include "Graf_complet.h"
#include "Graf_antisimetric.h"
#include "Graf_turneu.h"
#include <exception>

using namespace std;

void Citire()
{
    int n;
    std :: cin >> n;
    vector <Graf*> Grafuri;
    for(int i = 0; i < n; i++)
    {
        string p;
        std :: cin >> p;
        if(p == "complet")
        {

            try
            {
                Graf_complet *A = new Graf_complet;
                cin >> A;
                Grafuri.push_back(A);
            }
            catch(std::exception&e)
            {
                std:: cout << e.what();
            }

        }
        else if(p == "antisimetric")
        {
            try
            {

                Graf_antisimetric * B = new Graf_antisimetric;
                cin >> B;
                Grafuri.push_back(B);
            }
            catch(std :: exception & e)
            {
                std :: cout << e.what();
            }
        }
        else if(p == "turneu")
        {
            try
            {
                Graf_turneu *C = new Graf_turneu;
                cin >> C;
                Grafuri.push_back(C);
            }
            catch(std :: exception & e)
            {
                std :: cout << e.what();
            }
        }


        for(unsigned i = 0; i < Grafuri.size(); i++)
            Grafuri[i] -> display();

        for(int i = Grafuri.size() - 1; i >= 0; i--)
            delete Grafuri[i];

    }
}

int main()

{

    /**
    try{
    Graf_turneu *D = new Graf_turneu;
    cin >> D;
    D -> AfisareArce();
    }
    catch(std :: exception & e)
    {
        std :: cout << e.what();
    }


    try
    {
        Matrice A;
        cin >> A;
        Graf_antisimetric B(A);

    }
    catch(std :: exception& e)
    {
        std :: cout << e.what() << "\n";
    }
    */
    Graf_complet A;
    Graf_antisimetric B;







    return 0;
}

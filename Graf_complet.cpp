
#include "Graf_complet.h"


Graf_complet :: Graf_complet() : Graf(), nr_muchii(0)
{
}

Graf_complet :: Graf_complet(int noduri) : Graf(noduri), nr_muchii((noduri * (noduri - 1))/2)
{
    if(noduri <= 0)
        throw (Exceptions());
}

Graf_complet :: Graf_complet(const Graf_complet &H) : Graf(H), nr_muchii(H.nr_muchii)
{
    //std :: cout << "Copy Graf complet\n\n";
}


Graf_complet :: ~Graf_complet()
{
    //std :: cout << "Adio Graf complet!\n";
    //dtor
}



Graf_complet& Graf_complet :: operator = (Graf_complet &H)
{

    if(this != &H)
        {
            this -> Graf :: operator = (H);
            this -> nr_muchii = H.nr_muchii;
        }
    return *this;
}

std :: istream& operator >> (std :: istream &f, Graf_complet *G)
{
    int nod, muchii;
    f >> nod;
    if (nod < 0)
        throw Exceptions();

    f >> muchii;
    if(muchii > (nod * (nod - 1))/2)
        throw Exceptions();

    G -> setMuchii(muchii);
    G -> setNod(nod);

    return f;
}

std :: ostream& operator << (std :: ostream &d, Graf_complet *G)
{
    d << G -> getNod() << " " << G -> getMuchii() << "\n";
    return d;
}

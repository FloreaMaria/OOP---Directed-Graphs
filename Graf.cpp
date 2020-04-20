#include "Graf.h"


Graf :: Graf() : nr_noduri(0)
{

}

Graf :: Graf(int noduri) : nr_noduri(noduri)
 {

 }


Graf :: Graf(const Graf& G) : nr_noduri(G.nr_noduri)
{
    //std :: cout << "Copy-Graf\n\n";
}


Graf :: ~Graf()
{
    //std :: cout << "Adio Graf!\n";
}


Graf& Graf :: operator = (const Graf& ob)
{
    if (this != &ob)
    {
        nr_noduri = ob.nr_noduri;
    }
    return *this;
}
std :: istream& operator >> (std :: istream& f, Graf* G)
{
    int n;
    f >> n;
    G -> setNod(n);
    return f;
}
std :: ostream& operator << (std :: ostream& d, Graf* G)
{
    d << G -> nr_noduri;
    return d;
}

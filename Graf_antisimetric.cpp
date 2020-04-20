#include "Graf_antisimetric.h"


Graf_antisimetric :: Graf_antisimetric() : Graf(), M()
{

}

Graf_antisimetric :: Graf_antisimetric(Matrice A) : Graf(A.getNode()), M(A)
{

    int dim =  A.getNode();
    bool ** p =  A.getStart();
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            if(i == j && p[i][j] == 1)
                throw Invalid();
            if(i != j && p[i][j] == 1)
                if(p[j][i] == p[i][j])
                throw Invalid();
        }
    }
    /// std :: cout << "Graf_antisimetric!\n";
}

Graf_antisimetric :: Graf_antisimetric(const Graf_antisimetric& A) : Graf(A),  M(A.M)
{
    /// std :: cout << "Graf_antisimetric Copy\n";
}


Graf_antisimetric :: ~Graf_antisimetric()
{
    std :: cout << "Adio Graf_antimetric!\n";
}

std :: istream& operator >> (std :: istream& f, Graf_antisimetric *L)
{

    f >> L -> M;
    int dim = L -> M.getNode();

    bool ** p =L -> M.getStart();
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            if(i == j && p[i][j] == 1)
                throw Invalid();
            if(i != j && p[i][j] == 1)
                if(p[j][i] == p[i][j])
                throw Invalid();
        }
    }
    int nod = L -> M.getNode();
    L -> setNod(nod);

    return f;
}

std :: ostream& operator << (std :: ostream& d, Graf_antisimetric *A)
{
    d << A -> getNod() << " " << A -> M.getEdge() << "\n";
    d << A -> M << "\n";
    return d;
}


Graf_antisimetric &Graf_antisimetric :: operator = (Graf_antisimetric& A)
{
    std :: cout << "s-a apelat!\n";
    if(this != &A)
    {
        this -> Graf :: operator = (A);
        this -> M = A.M;
    }
    return *this;
}



void Graf_antisimetric :: AfisareArce()
{
    M.getEdges();
}

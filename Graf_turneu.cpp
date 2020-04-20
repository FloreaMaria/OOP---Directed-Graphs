#include "Graf_turneu.h"

Graf_turneu :: Graf_turneu() : Graf_complet(), Graf_antisimetric()
{

}

Graf_turneu :: Graf_turneu(Matrice A) : Graf(A.getNode()), Graf_complet(A.getNode()),  Graf_antisimetric(A)
{
    int dim = A.getNode();
    bool **p = A.getStart();

    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            if(i == j && p[i][j] == 1)
                throw Invalid();
            if(i != j && p[j][i] == p[i][j])
                throw Invalid();

        }
    }

}

Graf_turneu :: Graf_turneu(const Graf_turneu& A) : Graf(A), Graf_complet(A), Graf_antisimetric(A)
{
}


Graf_turneu :: ~Graf_turneu()
{
    std :: cout << "Adio graf_turneu!\n\n";
}




std :: istream& operator >> (std :: istream& f, Graf_turneu* A)
{

    Matrice M;
    f >> M;
    int dim = M.getNode();
    bool **p = M.getStart();

    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            if(i == j && p[i][j] == 1)
                throw Invalid();
            if(i != j && p[j][i] == p[i][j])
                throw Invalid();
        }
    }

    A -> setM(M);
    int m = M.getEdge();
    A -> setMuchii(m);

    int n = M.getNode();
    A -> setNod(n);
    return f;

}

std :: ostream& operator << (std :: ostream& d, Graf_turneu* A)
{
    Matrice B = A -> getM();
    d << B << "\n";
    return d;

}

Graf_turneu& Graf_turneu :: operator = (Graf_turneu & A)
{
    if(this != &A)
    {
        this -> Graf_complet :: operator = (A);
        this -> Graf_antisimetric :: operator = (A);
    }
    return *this;
}

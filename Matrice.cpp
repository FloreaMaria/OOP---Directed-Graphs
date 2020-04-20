#include "Matrice.h"


Matrice :: Matrice()
{

    this -> n = 0;
    this -> m = 0;
    matrice = new bool*[n];
    for(int i = 0; i <= n; i++)
        matrice[i] = new bool[n+1];

}


Matrice :: Matrice(int nod, int muchie, std :: pair<int, int> Muchii[1000])
{

    this -> n = nod;
    this -> m = muchie;

        if(m > (n * (n - 1)))
            throw Exceptions();

    for(int i = 0; i < m; i++)
        this -> V[i] = Muchii[i];

    matrice = new bool*[nod+1];

    for(int i = 0; i <= nod; i++)
        matrice[i] = new bool[nod+1];


    for(int i = 0; i < m; i++)
    {
        /**try{
        if(Muchii[i].first > n || Muchii[i].second > n)
            throw 3;}
        catch(int x)
        {
            std :: cout << "ERROR! Arch " << Muchii[i].first << " -> " << Muchii[i].second << " does not exist!\n\n";
            std :: exit(x);
        }
        */
        matrice[Muchii[i].first][Muchii[i].second] = 1;
    }
}

Matrice :: Matrice(const Matrice& Obiect)
{


    n = Obiect.getNode();
    m = Obiect.getEdge();
    bool **p = Obiect.getStart();

    matrice = new bool*[n+1];

    for(int i = 0; i <= m ; i++)
        V[i] = Obiect.V[i];

    for(int i = 0; i <= n; i++)
        matrice[i] = new bool[n+1];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            matrice[i][j] = p[i][j];


}

Matrice :: ~Matrice()
{
    for(int i = 0; i <= n; i++)
        delete[]  matrice[i];
    delete[] matrice;
}

void Matrice :: Afisare()
{

    n = getNode();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << matrice[i][j] << " ";
        }

        std::cout << "\n";
    }


}

std::istream& operator >> (std::istream& F, Matrice& M)
{

    int nod, m = 0;

    std::pair<int, int> Q[1000];

    F >> nod;
    if(nod < 0)
        throw Exceptions();

    M.setNode(nod);

    bool ** a = new bool * [nod + 1];
    for(int i = 0; i <= nod; i++)
        a[i] = new bool [nod + 1];


    for(int i = 1; i <= nod; i++)
        for(int j = 1; j <= nod; j++)
            {
                F >> a[i][j];

                if(a[i][j])
                {
                    m++;
                    Q[m].first = i;
                    Q[m].second = j;
                }
            }

    M.setEdge(m);
    M.setEdges(Q);
    M.setStart(a);
    return F;
}

std :: ostream& operator << (std::ostream& D, Matrice& A)
{
    bool **a = A.getStart();
    int n = A.getNode();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            D << a[i][j] <<" ";
        D << "\n";
    }
    return D;
}

Matrice& Matrice::operator = (Matrice& A)
{

    n = A.getNode();
    m = A.getEdge();

    for(int i = 1; i <= m; i++)
        V[i] = A.V[i];

    matrice = new bool*[n+1];
    for(int i = 0; i <= n; i++)
        matrice[i] = new bool[n+1];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            matrice[i][j] = A.matrice[i][j];
    return *this;


}


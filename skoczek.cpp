#include <stdio.h>
#include <stdlib.h>

const int PUSTE = 0;
const int N = 5;
int **tab;  //szachownica-tablica dwuwymiarowa NxN
int ruch_po_wierszu[] = {2, 1, -1, -2, -2, -1, 1, 2};
int ruch_po_kolumnie[] = {1, 2, 2, 1, -1, -2, -2, -1};  //tablice z kazda z 8 opcji ruchu po L

void wypisz()
{
    for (int w = 0; w < N; ++w)
    {
        for (int k = 0; k < N; ++k)
        {
            printf("%4d", tab[w][k]);
        }
        printf("\n");
    }
}

int skacz(int w, int k, int nr)
{
    printf("k: %d, w: %d, nr: %d\n", w, k, nr);
    wypisz();

    for (int i = 0; i < 8; ++i)  //petla dla skoku w kazda mozliwa strone (8 opcji)
    {
        if(nr>N*N)  //koniec-tablica zapelniona
            return 1;

        int new_w=w+ruch_po_wierszu[i];
        int new_k=k+ruch_po_kolumnie[i];  //stworzenie kazdej mozliwej opcji ruchu

        if(new_k>=0 && new_w>=0 && new_k<N && new_w<N && tab[new_w][new_k]==PUSTE)  //warunki aby nie wyjsc za tablice i pustego pola
        {
            tab[new_w][new_k] = nr;  //spelnione - robimy skok
            if (skacz(new_w, new_k, nr+1))  //szukamy kolejnego miejsca na skok w ten sam sposob zaczynajac od drugiego pola
            {
                return 1;
            }
            tab[new_w][new_k] = PUSTE;  //cofamy skok i szukamy kolejnych mozliwosci
        }
    }
    return 0;
}

int main()
{
    tab=(int**)malloc(N*sizeof(int*));
    for(int i=0;i<N;i++)
    {
        tab[i]=(int*)malloc(N*sizeof(int));
        for(int j=0;j<N;j++)
        {
            tab[i][j]=0;
        }
    }  //tworze wyzerowana szachownice

    tab[0][0]=1;  //ustawiam skoczka
    //wypisz();
    skacz(0, 0, 2);
    return 0;
}
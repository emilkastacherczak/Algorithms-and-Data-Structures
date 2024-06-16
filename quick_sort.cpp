#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz (int *tab, int N)
{
    for(int i=0; i<N; ++i)
    {
        //cout << tab[i] << '\t';
        printf("%4d", tab[i]);
    }
    //cout << endl;
    printf("\n");
}

int SL(int *tab, int N)
{
    int suma =0;
    for(int i=0; i<N; ++i){
        suma = suma + tab[i];
    }
    return suma;
}

int SWBR(int *tab, int N)
{
    int suma=0;
    for(int i=0; i<N-1; ++i){
        suma = suma + abs(tab[i+1]-tab[i]);
    }
    return suma;
}

void szybkie(int *tab, int left_index, int right_index)
{
    int granica=left_index;  //ustawiam granice na poczatku tablicy
    int p=tab[right_index];  //ustawiam piwota na koncu tablicy
    int t, j;
    for(j=left_index; j<right_index; j++)  //petla szukajaca miejsca podzialu wzgledem piwota
    {
        if(tab[j]<p)
        {
            t=tab[j];
            tab[j]=tab[granica];  //wstawiam liczbe przed granice(zamiana)
            tab[granica]=t;
            granica++;  //przesuwam granice
        }
    }

    tab[right_index]=tab[granica];  //wstawienie piwota w odpowiednie miejsce
    tab[granica]=p;

    if(granica-1 > left_index)  //posortowanie liczb<piwota
    {
        szybkie(tab, left_index, granica-1);
    }
    if(granica+1 < right_index)  //posortowanie liczb>piwota
    {
        szybkie(tab, granica+1, right_index);
    }
}

int main()
{
    int N = 10;
    int *tab;
    tab=(int*)malloc(N*sizeof(int));

    for(int i=0; i<N; ++i)  //wylosowanie tablicy liczb
    {
        tab[i] = rand() % 100;
    }

    printf("Przed sortowniem:\n");
    wypisz(tab, N);
    printf("SL: %d\n", SL(tab, N));
    printf("SWBR: %d\n", SWBR(tab, N));

    double czas;
    clock_t start, end;

    start = clock();
    szybkie(tab, 0, N-1);
    end = clock();
    czas = (double)(end - start)/CLOCKS_PER_SEC * 1000.0;

    printf("Po sortowaniu:\n");
    wypisz(tab, N);
    printf("SL: %d\n", SL(tab, N));
    printf("SWBR: %d\n", SWBR(tab, N));
    printf("Czas: %fms", czas);

    free(tab);

    return 0;
}

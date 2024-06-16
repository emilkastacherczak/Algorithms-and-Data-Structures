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
    for(int i=0; i<N; ++i)
    {
        suma = suma + tab[i];
    }
    return suma;
}

int SWBR(int *tab, int N)
{
    int suma=0;
    for(int i=0; i<N-1; ++i)
    {
        suma = suma + abs(tab[i+1]-tab[i]);
    }
    return suma;
}


void wybor(int tab[], int N)
{
    int t, j;
    int min, min_index;
    for (int i = 0; i < N - 1; i++)  //i jest granica posortowania
    {
        t = tab[i];  //zapamietuje liczbe na granicy
        min = tab[i];
        min_index = i;  //min poczatkowo ustawiane na granicy
        for (j = i + 1; j < N; j++)  //szukam minimum za granica
        {
            if (tab[j] < min)
            {
                min = tab[j];
                min_index = j;
            }
        }
        tab[i] = min;
        tab[min_index] = t;  //wstawiam najmniejsza liczbe na miejsce min(zamieniam miejscami)
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
    wybor(tab, N);
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

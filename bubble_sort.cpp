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


void babelkowo(int tab[], int N)
{
    for (int j = 0; j < N; ++j)  //petla do powtorzenia procesu
    {
        for (int i = 0; i < N - 1; ++i)  //petla do przejscia po kazdym elemencie tablicy
        {
            printf("Porównuję parę %d i %d\n", tab[i], tab[i + 1]);
            if (tab[i + 1] < tab[i])
            {
                printf("Zamieniam!\n");
                int t = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = t;
                wypisz(tab, N);
            }
        }
    }
}

int main()
{
    int N = 10;
    int *tab;
    tab=(int*)malloc(N*sizeof(int));

    for(int i=0; i<N; ++i){
        tab[i] = rand() % 100;
    }                             //wylosowanie tablicy liczb

    printf("Przed sortowniem:\n");
    wypisz(tab, N);
    printf("SL: %d\n", SL(tab, N));
    printf("SWBR: %d\n", SWBR(tab, N));

    double czas;
    clock_t start, end;

    start = clock();
    babelkowo(tab, N);
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


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

void wstawianie(int *tab, int N)
{
    int t, j;
    for (int i = 1; i < N; ++i)
    {
        t = tab[i];  //zapamietuje wartosc ktora chce przestawic
        j = i - 1;
        while (j >= 0 && tab[j] > t)
        {
            tab[j+1] = tab[j];  //przesuwanie elementow
            j--;
        }
        tab[j+1] = t;  //wstawienie poczatkowej wartosci w odpowiednie miejsce
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
    wstawianie(tab, N);
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

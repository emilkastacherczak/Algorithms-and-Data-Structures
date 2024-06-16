#include <iostream>

using namespace std;

void wypisz(int **pixel, int wysokosc, int szerokosc)
{
    for(int w=0; w<wysokosc; ++w)
    {
        for(int k = 0; k < szerokosc; ++k)
        {
            printf("%4d", pixel[w][k]);
        }
        printf("\n");
    }
}

int szukaj(int **pixel, int w, int k, int *licznik)
{
    pixel[w][k] = -1;

    //w gore
    if(pixel[w+1][k]==pixel[w][k]){
        licznik++;
        szukaj(pixel, w+1, k, licznik);
    }
    //w lewo
    if(pixel[w][k-1]==pixel[w][k]){
        licznik++;
        szukaj(pixel, w, k-1, licznik);
    }
    //w dol
    if(pixel[w-1][k]==pixel[w][k]){
        licznik++;
        szukaj(pixel, w-1, k, licznik);
    }
    //w prawo
    if(pixel[w][k+1]==pixel[w][k]){
        licznik++;
        szukaj(pixel, w, k+1, licznik);
    }

    int wynik = *licznik;
    return wynik;
}

int main()
{
    int licznik=0;
    int wysokosc, szerokosc;

    //wczytujemy obrazek
    FILE *plik;
    plik = fopen("mini.pgm", "r");
    if(!plik){
        printf("Problem z otwarciem pliku\n");
        exit(1);
    }

    //zczytujemy z obrazka wysokosc i szerokosc
    char format[2];
    fscanf(plik, "%s\n%d %d\n255\n", format, &szerokosc, &wysokosc);
    printf("Format: %s\n Szerokość: %d\n Wysokość: %d\n", format, szerokosc, wysokosc);

    //robie tablice pixel wysokosc x szerokosc int/short na numery kolorow pikseli
    int **pixel = new int*[wysokosc];
    for(int w=0; w<wysokosc; w++)
    {
        pixel[w] = new int[szerokosc];  //stworzenie dwuwymiarowej tablicy
    }

    //wczytanie obrazka do tablicy
    for(int w=0; w<wysokosc; ++w)
    {
        for(int k=0; k<szerokosc; ++k)
        {
            pixel[w][k] = fgetc(plik);
        }
    }
    fclose(plik);

    printf("Obrazek:\n");
    wypisz(pixel, wysokosc, szerokosc);

    //szukanie klastrow
    for(int w=0; w<wysokosc; w++)
    {
        for(int k=0; k<szerokosc; k++)
        {
            if(pixel[w][k] != -1)
            {
                printf("\nZnaleziono klaster w kolorze %d o wielkości %d\n", pixel[w][k], szukaj(pixel, w, k, &licznik));
            }
        }
    }

    printf("\nPo wyszukiwaniu:\n");
    wypisz(pixel, wysokosc, szerokosc);  //powinna zawierać same -1

    return 0;
}
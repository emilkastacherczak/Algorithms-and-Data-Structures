#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    char imie[20];
    char nazwisko[20];
    int wiek;
    int waga;
}Osoba;

queue <Osoba> kolejka;  //stworzona kolejka z Osobami

void zakolejkuj()
{
    //Osoba *nowa = (Osoba*)malloc(sizeof(Osoba));
    Osoba *nowa = new Osoba;

    printf("Podaj imie:");
    scanf("%s", nowa->imie);
    printf("Podaj nazwisko:");
    scanf("%s", nowa->nazwisko);
    printf("Podaj wiek:");
    scanf("%d", &(nowa->wiek));
    printf("Podaj wage:");
    scanf("%d", &(nowa->waga));

    printf("Dodaje na koncu %s\n", nowa->imie);
    kolejka.push(*nowa);
}

void pobierz(){
    kolejka.pop();
}

void rozmiar(){
    printf("W kolejece jest %d osob", kolejka.size());
}

int main()
{
    int wybor;
    printf("\nKolejka jest pusta\n");
    dalej:
    printf("\n1.Zakolejkuj"
           "\n2.Pobierz"
           "\n3.Rozmiar"
           "\n4.Zakończ");

    printf("\n\nWybierz działanie:");
    scanf("%d", &wybor);

    switch(wybor)
    {
        case 1:
            zakolejkuj();
            goto dalej;
        case 2:
            pobierz();
            goto dalej;
        case 3:
            rozmiar();
            goto dalej;
        case 4:
            printf("Zakończono");
            return 0;
        default:
            printf("Zły nr działania");
    }
    return 0;
}
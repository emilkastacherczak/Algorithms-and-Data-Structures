#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

stack<int> stos;

void odloz()
{
    int liczba;
    printf("Podaj liczbe:");
    scanf("%d", &liczba);
    printf("Dodaje liczbe %d\n", liczba);

    stos.push(liczba);
}

void zdejmij()
{
    printf("Zdejmuje liczbe ze stosu\n");
    stos.pop();
}

void podejrzyj()
{
    printf("Na wierzchu jest: %d\n", stos.top());
}

void ile()
{
    printf("Na stosie jest %d elementow\n", stos.size());
}

void czy_pusty()
{
    if(stos.empty()==true){
        printf("Stos jest pusty\n");
    }
    else{
        printf("Stos nie jest pusty\n");
    }
}


int main()
{
    int wybor;

    dalej:
    printf("\n1.Odloz liczbe na stos"
           "\n2.Zdejmij liczbe ze stosu"
           "\n3.Podejrzyj"
           "\n4.Sprawdz ile jest elementow na stosie"
           "\n5.Sprawdz czy stos jest pusty"
           "\n6.Zakoncz");

    printf("\nWybierz działanie:");
    scanf("%d", &wybor);

    switch(wybor)
    {
        case 1:
            odloz();
            goto dalej;
        case 2:
            zdejmij();
            goto dalej;
        case 3:
            podejrzyj();
            goto dalej;
        case 4:
            ile();
            goto dalej;
        case 5:
            czy_pusty();
            goto dalej;
        case 6:
            printf("Zakończono");
            return 0;
        default:
            printf("Zły nr działania");
    }
    return 0;
}
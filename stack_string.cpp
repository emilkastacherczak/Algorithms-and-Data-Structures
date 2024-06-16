#include <iostream>
#include <string>

using namespace std;

void odloz(string *tab, int *index)
{
    string wyraz;
    cout<<"Podaj wyraz:";
    cin>>wyraz;
    cout<<"Dodaje wyraz "<<wyraz<<" na index "<<*index<<endl;
    tab[*index]=wyraz;  //dodanie liczby do tablicy/zmiana jej wartosci
    ++(*index);  //zwiekszenie indexu - wskazuje miejsce na kolejna liczbe
    //jesli index>=rozmiar -> stos przepelniony
}

void zdejmij(string *tab, int *index)
{
    --(*index);  //'usuniecie' przez cofniecie indexu
    cout<<"Zdejmuje wyraz "<<tab[*index]<<endl;

}

void wypisz(string *tab, int index)
{
    for(int i=0; i<index; ++i){
        cout<<i<<": "<<tab[i]<<endl;
    }
}

void podejrzyj(string *tab, int index)
{
    if(index==0){
        cout<<"Stos jest pusty"<<endl;
    }
    else{
        cout<<"Ostatni element na stosie: "<<tab[index-1]<<endl;
    }
}

void ile(int index)
{
    cout<<"Na stosie jest "<<index<<" elementow"<<endl;
}

void czy_pusty(int index)
{
    if(index==0){
        cout<<"Stos jest pusty"<<endl;
    }
    else{
        cout<<"Stos nie jest pusty"<<endl;
    }
}

int main()
{
    string stos[100];
    int index=0;  //index zawsze wskazuje 1 miejsce za stosem

    int wybor;

    dalej:
    printf("\n1.Odloz wyraz na stos"
           "\n2.Zdejmij wyraz ze stosu"
           "\n3.Podejrzyj"
           "\n4.Sprawdz ile jest elementow na stosie"
           "\n5.Sprawdz czy stos jest pusty"
           "\n6.Wypisz"
           "\n7.Zakoncz");

    printf("\nWybierz działanie:");
    scanf("%d", &wybor);

    switch(wybor)
    {
        case 1:
            odloz(stos, &index);
            goto dalej;
        case 2:
            zdejmij(stos, &index);
            goto dalej;
        case 3:
            podejrzyj(stos, index);
            goto dalej;
        case 4:
            ile(index);
            goto dalej;
        case 5:
            czy_pusty(index);
            goto dalej;
        case 6:
            wypisz(stos, index);
            goto dalej;
        case 7:
            printf("Zakończono");
            return 0;
        default:
            printf("Zły nr działania");
    }
    return 0;
}
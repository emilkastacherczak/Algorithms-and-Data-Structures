#include <iostream>
#include <list>

using namespace std;

list <int> Mojalista;  //Tworze liste mogaca przechowywac int

void wypisz()
{
    cout<<"Lista: ";
    for(list<int>::iterator i=Mojalista.begin(); i!=Mojalista.end(); ++i){
        cout<<*i<<" ";  //wypisuje wartosci ktore wskazuje specjalny iterator
    }
    cout<<endl;
}

void wypisz_odwrotnie()
{
    cout<<"Lista: ";
    for(list<int>::iterator i=(--Mojalista.end()); i!=(--Mojalista.begin()); --i){
        cout<<*i<<" ";  //wypisuje wartosci ktore wskazuje specjalny iterator
    }
    cout<<endl;
}

void dodaj()
{
    int liczba;
    cout<<"Podaj liczbe:";
    cin>>liczba;
    Mojalista.push_back(liczba);
}

void dodaj_na_pozycje()
{
    int liczba, pozycja, licznik = 0;
    cout<<"Podaj liczbe:";
    cin>>liczba;
    cout<<"Podaj pozycje:";
    cin>>pozycja;
    cout<<"Wstawiam liczbe "<<liczba<<" na pozycje "<<pozycja;

    list<int>::iterator i = Mojalista.begin();
    while(licznik!=pozycja)
    {
        ++licznik;
        ++i;
    }
    Mojalista.insert(i, liczba);
}

void usun_z_pozycji()
{
    int pozycja, licznik = 0;
    cout<<"Podaj pozycje:";
    cin>>pozycja;

    list<int>::iterator i = Mojalista.begin();
    while(licznik!=pozycja)
    {
        ++licznik;
        ++i;
    }

    cout<<"Usuwam liczbe z pozycji "<<pozycja<<endl;
    Mojalista.erase(i);
}

void wyczysc()
{
    Mojalista.clear();
    cout<<"Lista jest pusta"<<endl;
}

void zamien()
{
    int pozycja1=0, pozycja2=0;
    cout<<"Podaj pozycje 1:";
    cin>>pozycja1;
    cout<<"Podaj pozycje 2:";
    cin>>pozycja2;

    list<int>::iterator i = Mojalista.begin();
    int licznik=0;
    while(licznik!=pozycja1)
    {
        ++licznik;
        ++i;
    }
    list<int>::iterator j = Mojalista.begin();
    licznik=0;
    while(licznik!=pozycja2)
    {
        ++licznik;
        ++j;
    }

    iter_swap(i, j);
}

int main()
{
    int wybor;
    printf("\nMasz pusta liste\n");
    dalej:
    printf("\n1.Dodaj liczbę na koniec listy"
           "\n2.Wstaw liczbę na podaną pozycje"
           "\n3.Usun liczbę z podanej pozycji"
           "\n4.Wyczysc"
           "\n5.Wypisz"
           "\n6.Wypisz odwrotnie"
           "\n7.Zamien"
           "\n8.Zakoncz");

    printf("\n\nWybierz działanie:");
    scanf("%d", &wybor);

    switch (wybor)
    {
        case 1:
            dodaj();
            goto dalej;
        case 2:
            dodaj_na_pozycje();
            goto dalej;
        case 3:
            usun_z_pozycji();
            goto dalej;
        case 4:
            wyczysc();
            goto dalej;
        case 5:
            wypisz();
            goto dalej;
        case 6:
            wypisz_odwrotnie();
            goto dalej;
        case 7:
            zamien();
            goto dalej;
        case 8:
            printf("Zakończono");
            return 0;
    }
    return 0;
}
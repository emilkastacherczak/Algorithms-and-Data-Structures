#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char imie[20];
    char nazwisko[20];
    int wiek;
    int waga;
    struct Osoba* next;
}Osoba;  //stworzony typ wezla

void wypisz(Osoba *head)
{
    printf("Kolejka: ");
    Osoba *wsk = head;  //dodatkowy wskaznik ktory przejdzie po calej liscie
    // najpierw wskazuje to co glowa - pierwszy element
    while(wsk!=NULL){
        printf("%s %s: %dlat %dkg ", wsk->imie, wsk->nazwisko, wsk->wiek, wsk->waga);
        wsk = wsk->next;  //przesuniecie wskaznika pomocniczego na kolejny wezel
    }
    printf("\n");
}

void zakolejkuj(Osoba **head_wsk)  //dzialamy na wskazniku na wskaznik head - zmieniamy oryginal
{
    Osoba *wsk = *head_wsk;  //wskaznik pomocniczy wskazuje na to co head
    Osoba *new = (Osoba*)malloc(sizeof(Osoba));  //stworzenie nowego wezla

    printf("Podaj imie:");
    scanf("%s", new->imie);
    printf("Podaj nazwisko:");
    scanf("%s", new->nazwisko);
    printf("Podaj wiek:");
    scanf("%d", &(new->wiek));
    printf("Podaj wage:");
    scanf("%d", &(new->waga));
    new->next=NULL;

    printf("Dodaje na koncu %s\n", new->imie);
    if(wsk == NULL)
    {
        *head_wsk = new;  //new staje sie glowa
    }
    else
    {
        while(wsk->next != NULL){
            wsk=wsk->next;
        }  //szukamy ostatniego elementu
        wsk->next = new;  //zmieniamy wskaznik w wezle na ktory wskazuje teraz wsk
    }
}

void pobierz(Osoba **head_wsk)
{
    Osoba *wsk = *head_wsk;  //wskaznik pomocniczy

    if(wsk == NULL)
    {
        printf("Kolejka jest pusta\n");
        return;
    }
    else
    {
        (*head_wsk)=wsk->next;
        printf("Pobieram pierwsza ososbe z kolejki\n");
        free(wsk);  //usuniecie pierwszej pozycji z listy
        return;
    }
}

void rozmiar(Osoba *head)
{
    Osoba *wsk = head;

    int licznik=1;
    while(wsk->next != NULL){
        wsk=wsk->next;
        ++licznik;
    }
    printf("W kolejece jest %d osob", licznik);
}

int main()
{
    //stworzenie glowy - wskaznika na null(pusta lista)
    Osoba *head = (Osoba*)malloc(sizeof(Osoba));
    head = NULL;

    int wybor;
    printf("\nKolejka jest pusta\n");
    dalej:
    printf("\n1.Zakolejkuj"
           "\n2.Pobierz"
           "\n3.Rozmiar"
           "\n4.Wypisz"
           "\n5.Zakończ");

    printf("\n\nWybierz działanie:");
    scanf("%d", &wybor);

    switch(wybor)
    {
        case 1:
            zakolejkuj(&head); //przekazuje do funkcji adres wskaznika head - dzialam na oryginale
            goto dalej;
        case 2:
            pobierz(&head);
            goto dalej;
        case 3:
            rozmiar(head);
            goto dalej;
        case 4:
            wypisz(head);
            goto dalej;
        case 5:
            printf("Zakończono");
            return 0;
        default:
            printf("Zły nr działania");
    }
    return 0;
}
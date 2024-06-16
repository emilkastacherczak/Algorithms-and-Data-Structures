#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int value;
    struct Node* next;
}Node;  //stworzony typ wezla

void wypisz(Node *head){
    printf("Lista:");
    Node *wsk = head;  //dodatkowy wskaznik ktory przejdzie po calej liscie
    //najpierw wskazuje to co glowa - pierwszy element
    while(wsk!=NULL){
        printf("%2d ", wsk->value);
        wsk = wsk->next;  //przesuniecie wskaznika pomocniczego na kolejny wezel
    }
    printf("\n");
}

void wypisz_odwrotnie(Node *head){
    if(head == NULL){
        return;
    }
    wypisz_odwrotnie(head->next);  //wykorzystujac rekurencje przemieszczamy sie na koniec listy
    printf("%2d ", head->value);  //wypisujemy wartosci 'w drodze powrotnej'
}

void dodaj(Node **head_wsk){  //dzialamy na wskazniku na wskaznik head - zmieniamy oryginal
    int liczba;
    printf("Podaj liczbe:");
    scanf("%d", &liczba);

    Node *wsk = *head_wsk;  //wskaznik pomocniczy wskazuje na to co head

    Node *new = (Node*)malloc(sizeof(Node));  //stworzenie nowego wezla
    new->value = liczba;
    new->next = NULL;

    printf("Dodaje na koncu liczbe %d\n", liczba);
    if(wsk == NULL){
        *head_wsk = new;  //new staje sie glowa
    }
    else{
        while(wsk->next != NULL){
            wsk=wsk->next;
        }                      //szukamy ostatniego elementu
        wsk->next = new;      //zmieniamy wskaznik w wezle na ktory wskazuje teraz wsk
    }
}

void dodaj_na_pozycje(Node **head_wsk){
    int licznik = 0;
    int liczba, pozycja;
    printf("Podaj liczbe:");
    scanf("%d", &liczba);
    printf("Podaj pozycje:");
    scanf("%d", &pozycja);

    Node *wsk = *head_wsk;

    Node *new = (Node*)malloc(sizeof(Node));
    new->value = liczba;

    printf("Dodaje liczbe %d na pozycje %d\n", liczba, pozycja);

    if(wsk == NULL){
        *head_wsk = new;
    }  //jesli lista jest pusta wstawiam na poczatek
    else{
        while(licznik != pozycja-1){  //szukamy miejsca na ktore mamy wstawic liczbe
            wsk=wsk->next;
            licznik++;
        }                            //wsk wskazuje na wezel przed pozycja
        new->next = wsk->next;
        wsk->next = new;
    }
}

void usun_z_pozycji(Node **head_wsk){
    int licznik = 0;
    int pozycja;

    printf("Podaj pozycje:");
    scanf("%d", &pozycja);

    Node *wsk = *head_wsk;  //wskaznik pomocniczy

    if(wsk == NULL){
        printf("Lista jest pusta\n");
        return;
    }
    else{
        if(pozycja==0){
            (*head_wsk)=wsk->next;
            printf("Usuwam liczbe z pozycji %d\n", pozycja);
            free(wsk);  //usuniecie pierwszej pozycji z listy
            return;
        }
        while (licznik != pozycja - 1) {
            wsk = wsk->next;  //wsk ustawiony na wezel przed tym ktory chce usunac
            licznik++;
            /*if(wsk->next = NULL){  //jesli dojdziemy do konca i nie znajdziemy pozycji
                printf("Podana pozycja jest poza na listą");
                return;
            }*/
        }
        printf("Usuwam liczbe z pozycji %d\n", pozycja);
        Node *pozycja_wsk = wsk->next;  //wskaznik pomocniczy na wezel na pozycji do usuniecia
        wsk->next = pozycja_wsk->next;  //wskaznik w wezle przed pozycja ustawiamy na wezel za pozycja
        free(pozycja_wsk);
    }
}

void wyczysc(Node **head_wsk){
    Node *delete = *head_wsk;  //wskaznik na usuwany element
    Node *wsk = *head_wsk;     //wskaznik do przesuniecia sie na kolejny element

    while(wsk != NULL){
        wsk = delete->next;
        free(delete);
        delete = wsk;  //usuwanie po kolei elementow
    }
    printf("Lista wyczyszczona\n");
    (*head_wsk)=NULL;  //lista znow pusta
}

void zamien(Node **head_wsk){
    int licznik = 0;
    int pozycja_1, pozycja_2;
    printf("Podaj pozycje (1):");
    scanf("%d", &pozycja_1);
    printf("Podaj pozycje (2):");
    scanf("%d", &pozycja_2);

    Node *wsk_1 = *head_wsk;
    Node *wsk_2 = *head_wsk;

    while(licznik != pozycja_1){
        wsk_1 = wsk_1->next;
        licznik++;
    }  //ustawienie wsk_1 na pierwsza pozycje
    licznik = 0;
    while(licznik != pozycja_2){
        wsk_2 = wsk_2->next;
        licznik++;
    }  //ustawienie wsk_2 na druga pozycje

    int t = wsk_1->value;
    wsk_1->value = wsk_2->value;
    wsk_2->value = t;  //zamiana wartosci
}

int main()
{
    //stworzenie glowy - wskaznika na null(pusta lista)
    Node *head = (Node*)malloc(sizeof(Node));
    head = NULL;

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

    switch(wybor){
        case 1:
            dodaj(&head); //przekazuje do funkcji adres wskaznika head - dzialam na oryginale
            goto dalej;
        case 2:
            dodaj_na_pozycje(&head);
            goto dalej;
        case 3:
            usun_z_pozycji(&head);
            goto dalej;
        case 4:
            wyczysc(&head);
            goto dalej;
        case 5:
            wypisz(head);
            goto dalej;
        case 6:
            printf("Lista odwrotnie:");
            wypisz_odwrotnie(head);
            goto dalej;
        case 7:
            zamien(&head);
            goto dalej;
        case 8:
            printf("Zakończono");
            return 0;
        default:
            printf("Zły nr działania");
    }
    return 0;
}
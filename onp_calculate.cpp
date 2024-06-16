#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX = 100;

float oblicz_onp(queue<char>wyrazenie)  //przekazanie do funkcji kopii kolejki z wyrazeniem onp
{

    printf("\nZaczynam liczyć\n");
    stack<float> stos;  //stos do przchowywania dzialan i wyniku

    while(!wyrazenie.empty())
    {
        char element = wyrazenie.front();
        printf("\nRozpatruje element: %c\n", element);

        if(element>='0' && element<='9')  //jesli jest liczba odloz na stos
        {
            float liczba = (element - '0');  //zamiana char na float
            stos.push(liczba);
            printf("Element jest liczbą %f, odkładam na stos\n", liczba);
        }
        else  //jesli jest operatorem
        {
            printf("Element jest operatorem %c\n\n", element);
            float a, b;
            b=stos.top();
            stos.pop();
            a=stos.top();
            stos.pop();  //zdejmij ze stosu 2 liczby

            printf("Liczba a: %f\n", a);
            printf("Liczba b: %f\n", b);

            switch(element)
            {
                case '+':
                    stos.push(a+b);  //odlóż na stos wynik
                    break;
                case '-':
                    stos.push(a-b);
                    break;
                case '*':
                    stos.push(a*b);
                    break;
                case '/':
                    stos.push(a/b);
                    break;
                default:
                    printf("Niepoprawny operator");
                    break;
            }
        }
        wyrazenie.pop();
    }
    float wynik = stos.top();
    return wynik;
}

void wypisz(queue<char>wyjscie)
{
    while(!wyjscie.empty())
    {
        cout << wyjscie.front();
        wyjscie.pop();
    }
    cout << endl;
}

int main()
{
    char wyrazenie[MAX];
    cout << "Podaj wyrazenie:";
    cin >> wyrazenie;

    queue<char> wyjscie;
    stack<char> stos;  //stos do przechowywania operatorow
    int t, u, w;

    for(int i=0; i<MAX; ++i)
    {
        if(wyrazenie[i]>='0' && wyrazenie[i]<='9')  //jesli jest cyfra - na wyjscie
        {
            wyjscie.push(wyrazenie[i]);
        }
        else if(wyrazenie[i]=='(')  //jesli jest nawiasem otwierajacym - na stos
        {
            stos.push(wyrazenie[i]);
        }
        else if(wyrazenie[i]==')')  //jesli jest nawiasem zamykajacym
        {
            while(stos.top()!='(')  //sciagam operatory ze stosu na wyjscie az do "("
            {
                t = stos.top();
                wyjscie.push(t);
                stos.pop();
            }
            stos.pop();  //usuwam "(" ze stosu
        }
        else  //jesli jest operatorem
        {
            if(stos.empty())  //jesli stos jest pusty - operator na stos
            {
                stos.push(wyrazenie[i]);
            }
            else  //porownuje priorytet biezacego operatora z tym na stosie
            {
                if(wyrazenie[i]=='+' || wyrazenie[i]=='-')
                {
                    while(stos.top()=='*' || stos.top()=='/' || stos.top()=='+' || stos.top()=='-')  // dopóki na szczycie stosu znajduje się operator o priorytecie wyższym lub równym od priorytetu operatora wczytanego
                    {
                        u = stos.top();  //sciagam ze stosu i odkladam na wyjscie
                        wyjscie.push(u);
                        stos.pop();
                        if(stos.empty()){  //przerywam gdy zdejme wszystkie operatory ze stosu
                            break;
                        }
                    }
                    stos.push(wyrazenie[i]);  //odkladam biezacy na stos
                }
                else if(wyrazenie[i]=='*' || wyrazenie[i]=='/')
                {
                    while(stos.top()=='*' || stos.top()=='/')
                    {
                        w = stos.top();
                        wyjscie.push(w);
                        stos.pop();
                        if(stos.empty()){
                            break;
                        }
                    }
                    stos.push(wyrazenie[i]);
                }
                else  //odkladam go na stos
                {
                    stos.push(wyrazenie[i]);
                }
            }
        }
    }

    int x;
    while(!stos.empty())  //po dojsciu do konca odkladam na wyjscie reszte operatorow ze stosu
    {
        x = stos.top();
        wyjscie.push(x);
        stos.pop();
    }

    cout << "Wyrazenie w ONP: ";
    wypisz(wyjscie);

    int wartosc = oblicz_onp(wyjscie);
    cout << "Wynik: " << wartosc << endl;

    return 0;
}
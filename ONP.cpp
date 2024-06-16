#include <iostream>
#include <stack>
#include <queue>

const int MAX = 100;
using namespace std;

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
            if(stos.empty()){  //jesli stos jest pusty - operator na stos
                stos.push(wyrazenie[i]);
            }
            else  //porownuje priorytet biezacego operatora z tym na stosie
            {
                if(wyrazenie[i]=='+' || wyrazenie[i]=='-')
                {
                    while(stos.top()=='*' || stos.top()=='/' || stos.top()=='+' || stos.top()=='-')  //dopóki na szczycie stosu znajduje się operator o priorytecie wyższym lub równym od priorytetu operatora wczytanego
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
    for(int i=0; i<MAX; ++i)
    {
        cout << wyjscie.front();
        wyjscie.pop();
    }

    return 0;
}
//Antoni Lasoñ 15.12.2020
//wersja chyba stabilna
//!UWAGA!
//Począwszy od dnia 24.11.2020 KAŻDA edycja kodu wymaga odpowiedniej korekcji sekcji Kody i funkcjie na wiki programu
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

//**************************
//DEKLARACJE FUNKCJI

void menu();                            //jakieœ tam menu/powitanie

void instr();                           //Instrukcja obsługi programu

string inp();                           //wczytuje dane

void out(string s1);                    //wypisanie wyniku w formie tablicy prawdy
//                                      //UWAGA! czyści ekran przez system("cls")

void first2line(string sentence, int nOV, string sv);  //wypisuje pierwsze 2 linie tablicy prawdy

string variableseparator(string sentence);  //Wyszukuje niepowtarzalne przesłanki

int variablecounter(string sentence);   //Liczy ilość zmiennych/przesłanek w wpisanym zdaniu
//                                      //Sprawdzony, działa

void otherline(string sentence, int nOV, string sv);        //reszta lini wraz z ich rozwiązaniami

string logika(string wyr);              //Oblicza wartości logiczne pojedyńczych zdań, użwyane wielokrotnie w otherline

string dec_to_bin(int n,int l);                  //porzyczone od Zogfryda generuje odpowiedni ciąg 0 i 1

string koniunkcja(char a, char b);      //|
//                                      //|
string alternatywa(char a, char b);     //|
//                                      //|operacje logiczne
string rownowaznosc(char a, char b);    //|
//                                      //|
string implikacja(char a, char b);      //|

string negacja(char a);                 //

void DNF(string s1);                    //Sprowadza formułę do postaci DNF

void CNF(string s1);                    //Sprowadza formułę do postaci CNF
//**************************

int main()
{
    system("chcp 65001");    //Miało zrobić polskie znaki, ale nie zrobiło
    system("cls");
    menu();

    return 0;
}

//**************************
//DEFINICJE FUNKCJI

void menu()
{
    cout<<"Witaj w aplikacji kalkulator logiczny \n \nWybierz:"<<endl;
    cout<<" 1 aby przejść do trybu wprowadzania zdań do rozwarzenia \n 2 aby zobaczyć instrukcje obsługi (na razie nie działa) \n 3 aby przekształcić formułę do postaci DNF \n 4 aby przekształcić formułę do postaci CNF \n e aby zakończyć działanie programu"<<endl;

    char ch;                 //wybieranie opcji w menu
    while(true)
    {
        ch = getch();
        switch(ch)
        {
        case '1':
        {
            cout<<"Wybrano opcję "<< ch <<endl;
            cout<<"Wprowadź zdanie"<<endl;
            out(inp());
            break;
        }
        case '2':
        {
            cout<<"Wybrano opcję "<< ch <<endl;

            instr();
            break;
        }
        case '3':
        {
            cout<<"Wybrano opcję "<< ch <<endl;
            cout<<"Wprowadź zdanie"<<endl;
            cout<<"Prepraszamy, opcja nie dostępna"<<endl;
            DNF(inp());
            break;
        }
        case '4':
        {
            cout<<"Wybrano opcję "<< ch <<endl;
            cout<<"Wprowadź zdanie"<<endl;
            cout<<"Prepraszamy, opcja nie dostępna"<<endl;
            CNF(inp());
            break;
        }
        case 'e':
        {
            cout<<"Wybrano opcję "<< ch <<endl;
            exit(0);
            break;
        }
            case 't':
        {
            cout<<"Wybrano opcję "<< ch <<endl;
            cout<<"test variableseparator"<<endl;
            cout<<variableseparator(inp())<<endl;
            break;
        }
        default:
        {
            cout<<"Wybrano opcję domyślną" <<endl;
            cout<<"Wybrana opcja nie istnieje"<<endl;
            break;
        }

        }
        cout<<"Wróciłeś do menu"<<endl;
    }

}

void instr() //Odsyłanie do instrukcji w internecie
{
    cout<<"Instrukcja dostępna na stronie  https://github.com/AGH-Narzedzia-Informatyczne/Przelicznik_Wartosci_-Logicznych/wiki/Manual "<<endl;
}

string inp()
{
    string sentence;
    cin>>sentence;
    return sentence;
}

void out(string s1)
{
    system("cls");          //Czyści ekran
    string s2 = s1;
    string sv = variableseparator(s2);
    int nOV = variablecounter(sv);
    first2line(s2, nOV, sv);
    otherline(s2, nOV, sv);
}

string variableseparator(string sentence) //sprawdzone, działa poprawnie
{
    string uniqvar;

    for(int i = 0 ; i < sentence.size(); i++)
    {
        if((sentence[i]>='A' && sentence[i]<='Z')||(sentence[i]>='a' && sentence[i]<='z'))
        {
                uniqvar += sentence[i];
                break;
        }
    }

    for(int i = 0 ; i < sentence.size(); i++)
    {
        if((sentence[i]>='A' && sentence[i]<='Z')||(sentence[i]>='a' && sentence[i]<='z'))
            {
                for(int j = 0; j < uniqvar.size(); j++)
                {
                    if(uniqvar[j] == sentence[i])
                        break;
                    if((j == uniqvar.size()-1) && (uniqvar[j] != sentence[i]))
                        uniqvar+=sentence[i];
                }
            }
    }
    return uniqvar;
}

int variablecounter(string sentence)
{
    int numOfVar = 0;
    for(int i = 0 ; i < sentence.size(); i++)
    {
        if((sentence[i]>='A' && sentence[i]<='Z')||(sentence[i]>='a' && sentence[i]<='z'))
            numOfVar++;
    }
    if(numOfVar==0)
        cout<<"UWAGA! NIE WYKRYTO PRZESŁANEK/ZMIENNYCH LOGICZNYCH"<<endl;
    return numOfVar;

}

void first2line(string sv, int nOV, string sentence)///Uwaga! sv i sentence zamienone miejscami celowo
{
    for(int i = 0; i < sentence.size(); i++)
    {
        //if((sentence[i]>='A' && sentence[i]<='Z')||(sentence[i]>='a' && sentence[i]<='z'))  //Mam nadzieję, że to jest już zbędne
            cout<<"| "<<sentence[i]<<" ";
    }
    cout<<"| "<<sv<<" |"<<endl;
    for(int i = 0; i <= nOV; i++)
    {
        cout<<"+---";
    }
    for(int i = 1 ; i < sv.size(); i++)
    {
        cout<<"-";
    }
    cout<<"|"<<endl;
}

void otherline(string sentence, int nOV, string sv)
{


    string logicvalue;
    for(int i = 0; i < pow(2, nOV); i++)
    {
        string s;
        logicvalue = dec_to_bin( i, nOV);
        int k = 0;
        for(int j = 0 ; j<sentence.size(); j++)
        {
            if((sentence[j]>='A' && sentence[j]<='Z')||(sentence[j]>='a' && sentence[j]<='z'))
            {

                for(int k = 0; k<sv.size(); k++)
                {
                    if(sentence[j] == sv[k])
                    {
                        s+=logicvalue[k];
                    }

                }

            }
            else
            {
                s+=sentence[j];
            }
        }

        for(int j = 0; j <= nOV; j++)
        {
            cout<<"| "<<logicvalue[j]<<" ";
        }
        cout<<logika(s);
        for(int j = 1; j<sentence.size(); j++)
        {
            cout<<" ";
        }
        cout<<"|"<<endl;

        for(int j = 0; j <= nOV; j++)
        {
            cout<<"+---";
        }
        for(int j = 1 ; j < sentence.size(); j++)
        {
            cout<<"-";
        }
        cout<<"|"<<endl;
    }
}

string logika(string wyr)
{

    string wyr2=wyr;

    unsigned int i = 0;

    while(i<wyr2.size())
    {
        if(wyr2[i]==')')
        {
            if(wyr2[i-2]=='\\' && wyr2[i-3]=='/') // koniunkcja
            {
                wyr2.replace(i-5, 6, koniunkcja(wyr2[i-4], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='/' && wyr2[i-3]=='\\') // alternatywa
            {
                wyr2.replace(i-5, 6, alternatywa(wyr2[i-4], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='>' && wyr2[i-3]=='=' && wyr2[i-4]=='<') // równoważność
            {
                wyr2.replace(i-6, 7, rownowaznosc(wyr2[i-5], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='>' && wyr2[i-3]=='=') // implikacja
            {
                wyr2.replace(i-5, 6, implikacja(wyr2[i-4], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='~') // negacja
            {
                wyr2.replace(i-3, 4, negacja(wyr2[i-1]));
            }
            else
            {
                cout<<"Nieprzewidziane działanie lub niepoprawne wejście"<<endl;
                return "Error string logika(string wyr)";
            }
            i=0;
        }
        else
            i++;

    }
    return wyr2;


}


string dec_to_bin(int n,int l)
{
    string o;
    for(int i=0;i<l;i++)
    {
        if(n%2==1)
            o+="1";
        else
            o+="0";
        n/=2;
    }
    return o;
}

void DNF(string s1)
{

}

void CNF(string s1)
{

}

//*************************
//Funkcje odpowiedzialne za operacje logiczne

string koniunkcja(char a, char b)
{
    if(a=='1' && b=='1')
    {
        return "1";
    }
    return "0";
}

string alternatywa(char a, char b)
{
    if(a=='0' && b=='0')
    {
        return "0";
    }
    return "1";
}

string rownowaznosc(char a, char b)
{
    if(a=='1' && b=='1')
    {
        return "1";
    }
    if(a=='0' && b=='1')
    {
        return "0";
    }
    if(a=='1' && b=='0')
    {
        return "0";
    }
    if(a=='0' && b=='0')
    {
        return "1";
    }
    return "0";
}

string implikacja(char a, char b)
{
    if(a=='1'&& b=='0')
    {
        return "0";
    }
    else
    {
        return "1";
    }
}

string negacja(char a)
{
    if(a=='1')
        return "0";
    else
        return "1";

}



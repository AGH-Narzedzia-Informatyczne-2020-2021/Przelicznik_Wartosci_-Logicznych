//Antoni Lasoñ 14.11.2020
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

void first2line(string sentence, int nOV);  //wypisuje pierwsze 2 linie tablicy prawdy

int variablecounter(string sentence);   //Liczy ilość zmiennych/przesłanek w wpisanym zdaniu
//                                      //Sprawdzony, działa

void otherline(string sentence, int nOV);        //reszta lini wraz z ich rozwiązaniami

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
//**************************

int main()
{
    setlocale( LC_ALL, "" );            //Miało zrobić polskie znaki, ale nie zrobiło
    menu();

    return 0;
}

//**************************
//DEFINICJE FUNKCJI

void menu()
{
    cout<<"Witaj w aplikacji kalkulator logiczny \n \nWybierz:"<<endl;
    cout<<" 1 aby przejœæ do trybu wprowadzania zdañ do rozwarzenia \n 2 aby zobaczyæ instrukcje obs³ugi (na razie nie dzia³a)"<<endl;

    int ch;                 //wybieranie opcji w menu
    while(true)
    {
        ch = getch();
        switch(ch)
        {
        case '1':
        {
            cout<<"Wprowadź zdanie"<<endl;
            out(inp());
            break;
        }
        case '2':
        {
            instr();
            break;
        }
        case 'e':
        {
            cout<<"tu będzie wyjście"<<endl;
            break;
        }
        default:
        {
            cout<<"Wybrana opcja nie istnieje"<<endl;
            break;
        }

        }
        cout<<"Wróciłeś do menu"<<endl;
    }

}

void instr() // funkcja nieukończona
{
    cout<<"Jeszcze nie ma"<<endl;
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
    int nOV = variablecounter(s2);
    first2line(s2, nOV);
    otherline(s2, nOV);
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

void first2line(string sentence, int nOV)
{
    for(int i = 0; i < sentence.size(); i++)
    {
        if((sentence[i]>='A' && sentence[i]<='Z')||(sentence[i]>='a' && sentence[i]<='z'))
            cout<<"| "<<sentence[i]<<" ";
    }
    cout<<"| "<<sentence<<" |"<<endl;
    for(int i = 0; i <= nOV; i++)
    {
        cout<<"+---";
    }
    for(int i = 1 ; i < sentence.size(); i++)
    {
        cout<<"-";
    }
    cout<<"|"<<endl;
}

void otherline(string sentence, int nOV)
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

                s+=logicvalue[k];
                k++;
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
        cout<<logika(s)<<"  |"<<endl;


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

//Antoni Lasoñ 2020.10.18 12:00
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//FUNKCJE (definicje na końcu)
string koniunkcja(char a, char b);

string alternatywa(char a, char b);

string rownowaznosc(char a, char b);

string alternatywawykluczajaca(char a, char b);

string implikacja(char a, char b);

int liczbaZmiennych(string formula);

//************************************
//MAIN

int main()
{
    string wyr;
    getline (cin, wyr);
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
            else if(wyr2[i-2]=='>' && wyr2[i-3]=='=') // implikacja
            {
                wyr2.replace(i-5, 6, implikacja(wyr2[i-4], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='>' && wyr2[i-3]=='=' && wyr2[i-4]=='<') // równoważność
            {
                wyr2.replace(i-6, 7, rownowaznosc(wyr2[i-5], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='~') // negacja
            {
                //wyr2.replace(i-3, 4, negacja(wyr2[i-1]));
            }
            else
            {
                cout<<"Nieprzewidziane działanie lub niepoprawne wejście"<<endl;
                return 1;
            }
            i=0;
        }
        else
            i++;

    }
    cout<<wyr2<<endl;


}

//DEFINICJE FUNKCJI



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

int liczbaZmiennych(string formula)
{

}

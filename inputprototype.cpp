//Antoni Lasoñ 2020.10.18 12:00
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//FUNKCJE (definicje na końcu)
string koniunkcja(char a, char b);



main()
{
    string wyr;
    getline (cin, wyr);
    string wyr2=wyr;

    unsigned int i = 0;

    while(i<wyr2.size())
    {
        if(wyr2[i]==')')
        {
            if(wyr2[i-2]=='\\' && wyr2[i-3]=='/')
            {
                wyr2.replace(i-5, 6, koniunkcja(wyr2[i-4], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='/' && wyr2[i-3]=='\\')
            {
                wyr2.replace(i-5, 6, alternatywa(wyr2[i-4], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='>' && wyr2[i-3]=='=')
            {
                wyr2.replace(i-5, 6, implikacja(wyr2[i-4], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='>' && wyr2[i-3]=='=' && wyr2[i-4]=='<')
            {
                wyr2.replace(i-6, 7, rownowaznosc(wyr2[i-5], wyr2[i-1]));
            }
            else if(wyr2[i-2]=='~')
            {
                wyr2.replace(i-3, 4, negacja(wyr2[i-1]));
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
/*
NOTATKI
**************************
KODY ASCII
**************************
    spacja = 32
    zero = 48
*/

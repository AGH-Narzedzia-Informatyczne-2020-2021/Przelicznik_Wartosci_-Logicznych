//Antoni Lasoñ 2020.10.17 20:00
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
            if(wyr2[i-2]=='\\')
            {
                wyr2.replace(i-5, 6, koniunkcja(wyr2[i-4], wyr2[i-1]));
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

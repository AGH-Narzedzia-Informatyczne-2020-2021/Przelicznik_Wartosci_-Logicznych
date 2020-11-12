
//Antoni Lasoñ 2020.10.18 12:00
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//FUNKCJE (definicje na końcu)
string koniunkcja(char a, char b);

string alternatywa(char a, char b);

string rownowaznosc(char a, char b);

string alternatywawykluczajaca(char a, char b);

string implikacja(char a, char b);

string dec_to_bin(int n,int l);



int main()
{
    cout <<"podaj liczbę zmiennych";
    int li;
    cin >>li;
    char* znak = new char [li];
    for(int i=0;i<li;i++)
    {
        cout <<"Podaj znak: ";
        cin>>znak[i];
    }
    cout <<"podaj formułe";
    string wyr;
    cin >> wyr;
    string przyp[(int)pow(2,li)+2];
    for(int i=0;i<li;i++)
    {
        przyp[0]+="| ";
        przyp[0]+=znak[i];
        przyp[0]+=" ";
    }
    przyp[0]+="|";
    for(int i=0;i<przyp[0].length();i++)
        przyp[1]+='-';
    for(int i=2;i<((int)pow(2,li)+2);i++)
        przyp[i] = dec_to_bin(i-2,li);
        cout<<endl;
    for (int i=0;i<((int)pow(2,li)+2);i++)
    cout<<przyp[i]<<endl;

    string zap;
    for(int i=2;i<((int)pow(2,li)+2);i++)
    {
        zap=wyr;
        for(int j=0;j<zap.length();j++)
        {

        }
    }
    return 0;
}


char logika(string wyr)
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

/*
char alternatywawykluczajaca(char a, char b)
{
    if(a=='0' && b=='0')
    {
        return "0";
    }
    else if(a=='1' && b=='1')
    {
        return "0";
    }
    else
    {
        return "1";
    }
}
*/
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
string dec_to_bin(int n,int l)
{
    string out;
    for(int i=0;i<l;i++)
    {
        if(n%2==1)
            out+="| 1 ";
        else
            out+="| 0 ";
        n/=2;
    }
    out+="|";
    for(int i=2;i<out.length()/2;i+=4)
        swap(out[i],out[out.length()-1-i]);

        return out;
}



//Antoni Lasoñ 2020.10.18 12:00
//Zogfryt 2020.11.14
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <clocale>

using namespace std;


//FUNKCJE (definicje na końcu)
string koniunkcja(char a, char b);

string alternatywa(char a, char b);

string rownowaznosc(char a, char b);

string alternatywawykluczajaca(char a, char b);

string implikacja(char a, char b);

string dec_to_bin(int n,int l);

char logika (string wyr);



int main()
{

    setlocale(LC_ALL,"");
    char wyb;
    while(1)
    {

    cout <<"podaj liczbe zmiennych: ";
    int li;
    cin >>li;
    char* znak = new char [li];
    for(int i=0;i<li;i++)
    {
        cout <<"Podaj znak[" << i+1 << "]: ";
        cin>>znak[i];
    }
    cout <<"podaj formule: \n";
    string wyr;
    cin >> wyr;
    string przyp[(int)pow(2,li)+2];
    for(int i=0;i<li;i++)
    {
        przyp[0]+="| ";
        przyp[0]+=znak[i];
        przyp[0]+=" ";
    }
    przyp[0]+="| ";
    przyp[0]+=wyr;
    przyp[0]+=" |";
    for(int i=0;i<przyp[0].length();i++)
        przyp[1]+='-';
    for(int i=2;i<((int)pow(2,li)+2);i++)
        przyp[i] = dec_to_bin(i-2,li);
        cout<<endl;


    string zap;
    for(int i=2;i<((int)pow(2,li)+2);i++)
    {
        zap=wyr;
        for(int j=0;j<zap.length();j++)
        {
           for(int z=0;z<li;z++)
           if(zap[j]==znak[z])
           zap[j]=przyp[i][2+4*z];
        }
        for(int j=4*li;j<(przyp[0].length()-2);j++)
            przyp[i]+=" ";
        przyp[i]+="|";
        przyp[i][(4*li-1)+(wyr.length()/2)+2]=logika(zap);
    }

    for (int i=0;i<((int)pow(2,li)+2);i++)
    cout<<przyp[i]<<endl;
    cout <<"czy chcesz sprawdzic kolejna(Y/N): ";
    cin >> wyb;
    if(wyb=='Y' || wyb=='y')
        system("cls");
    else if(wyb=='N' || wyb=='n')
        break;
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
    return wyr2[0];


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


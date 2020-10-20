#include <iostream>
#include <math.h>
#include <algorithm>

std::string dec_to_bin(int,int);

int main()
{
    using namespace std;
    string wej;
    int n;
    cout << "podaj liczbê zmiennych: ";
    cin >> n;
    /*char *znaki = new char [n];
    for(int i=0;i<n;i++)
    {
        cout << "znak " << i+1 << ": " ;
        cin >> znaki[i];
    }
    cout <<"Podaj formule: ";
    cin << wej; */
    string przyp[(int)pow(2,n)];
    for(int i=0;i<(int)pow(2,n);i++)
    {
        przyp[i] = dec_to_bin(i,n);
        cout <<"."<<endl;
        cout << przyp[i]<<endl;
    }
    return 0;
}

std::string dec_to_bin(int n,int l)
{
    std::string out;
    for(int i=0;i<l;i++)
    {
        if(n%2==1)
            out+='1';
        else
            out+='0';
        n/=2;
    }
    for(int i=0;i<l/2;i++)
        std::swap(out[i],out[l-1-i]);

        return out;
}

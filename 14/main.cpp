#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

void one()
{
    int iSize = 11;
    for(int i=0; i < iSize; i++)
    {
        for(int j=0; j < iSize; j++)
        {
            if((j%2==0&&i%2==0)||(j%2!=0&&i%2!=0))
            {
                cout<<'*';
            }
            else
                cout<<'_';
        }
        cout<<'\n';
    }
}
int two(char c [])
{
    int iSize = 0;
    int iTotal = 0;
    for(int i=strlen(c)-1; i >= 0; i--)
    {
        if((c[i]>=48)&&(c[i]<=57))
        {
            iSize++;
            int k = c[i]-'0';
            k *= round(pow(10,(iSize-1)));
            iTotal = iTotal+ k;
        }
    }
    return iTotal;
}

void mySubStr(char c[], int pos1, int pos2)
{
    char c1 [99];
    for(int i = 0; i < pos2-pos1; i++)
    {
        c1[i]=c[pos1+i];
    }
    c1[pos2-pos1]='\0';
    cout<<c1;
}

int main()
{
    one();

    char c [99]= {'2','3','b','5','6'};
    char c1 [99] = {'b'};
    //cin >> c;

   // cout<<two(c);
    //one();
    mySubStr(c,1,2);


}

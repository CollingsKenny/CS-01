#include <iostream>
#include <math.h>

using namespace std;

const int iSIZE = 999;

void foo(int* i)
{
    *i = 2;
}

void foo2(int &i)
{
    i = 3;
}

int stringToInt(char carr[])
{
    char cTemp[iSIZE];
    int cTSize = 0;

    int toInt=0;


    //finds length and removes unwanted characters
    for(int i = 0; i < iSIZE; i++)
    {
        if((carr[i] >= 48 && carr[i] <= 57))
        {
            cTemp[cTSize]=carr[i];
            cTSize++;
        }
    }

    //adds all
    for(int i = cTSize-1; i >= 0; i--)
    {
        int j = cTemp[i];
        j = j-48;
        j = j*round(pow(10,(cTSize-i-1)));
        toInt += j;
    }
    return toInt;
}


int main()
{

   // char sTring[iSIZE] = {'1','2','3',',','4','5'};

    //int i = stringToInt(sTring);

    int i =10;
    foo(&i);
    cout<<i;
}

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    const int MAX_VAL = 10;
    const int MAX_AMT = 21;

    srand(time(0));
    int iaRan[MAX_AMT];
    int iLarg = 0;
    int iSum = 0;

    float fS;
    float fL;

    for(int i = 0; i < MAX_AMT; i++)
    {
        iaRan[i]= rand()%MAX_VAL+1;
        iSum += iaRan[i];
        if(iaRan[i]>iLarg)
            iLarg = iaRan[i];
    }
    cout<<setprecision(3)<<fixed;
    fS = iSum;
    fL = MAX_AMT;
    cout<<"The biggest number is: "<<iLarg<<"\nThe sum of all the numbers is: "<<iSum<<"\nThe average is: "<<fS/fL;
}

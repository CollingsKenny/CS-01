#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int iNput;
    int iMax = 3;
    int iMin = 0;
    int iNumInRow = 1;
    int icolor = 100;

    cout<<"Enter a number: ";
    cin>> iNput;
    cout<<endl;

    for(int iRows = 0; true ;iRows++)
        {
         if(iRows%3 == 0){
            iMax++;
            iMin++;
            iNumInRow = iMin;
        }
        for(int iPrintTimes = 0; iPrintTimes < iNumInRow; iPrintTimes++)
        {
            SetConsoleTextAttribute(hConsole, icolor);
            cout<<"*";
        }

        icolor++;
        iNumInRow++;
        cout<<endl;
    }

}

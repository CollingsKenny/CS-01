#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

using namespace std;
int icolor = 1;
HANDLE hConsole;

void everyOther(int i);
void ex(int i);
void incColor();



int main()
{
    srand(time(0));
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     while(true)
    {
        if(rand()%12==3)
            everyOther(100);
        ex(100);
    }
    return 0;
}
void everyOther(int i)
{
    for(int row = 0; row < i; row++)
    {
        for(int col = 0; col < i; col++)
        {
            if(((col%2)&&!(row%2))||(!(col%2)&&(row%2)))
            {
                SetConsoleTextAttribute(hConsole, icolor);incColor();
                cout<<"stop judging me";
                SetConsoleTextAttribute(hConsole, 0);
                cout<<" ";
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 0);
                cout<<" ";
            }
        }
        cout<<endl;
        Sleep(2);
    }
}

void ex(int i)
{
    for(int row = 0; row < i; row++)
    {
        for(int col = 0; col < i; col++)
        {
            if((col==row)||((i-col-1)==(row)))
            {
                SetConsoleTextAttribute(hConsole, icolor);incColor();
                cout<<"I was bored, okay?!";
            }
            else
            {

                cout<<" ";
            }
        }
        cout<<endl;
        Sleep(2);
    }
}
void incColor()
{
    icolor++;
    if(icolor==256)
            icolor =1;
}

#include "lpclib.h"
#include <conio.h>
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

    int iY = 300;
    int iX = 300;
    int iSize = 10;

void reDraw(){

    DrawCircle(iX, iY, iSize, "black", true);
    UpdateDisplay();
}

int main()
{
    GraphicsWindow(600, 600, "white");
    reDraw();

    cout<<"anything";
    int c =0;
    while(1){
        c = 0;
        switch((c=getch())){
        case KEY_UP:
            iY-=iSize;
            reDraw();
            break;
        case KEY_DOWN:
            iY+=iSize;
            reDraw();
            break;
        case KEY_LEFT:
            iX -=iSize;
            reDraw();
            break;
        case KEY_RIGHT:
            iX +=iSize;
            reDraw();
            break;
        }
     }
    return 0;
}

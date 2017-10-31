#include <iostream>

using namespace std;

int main()
{
    float fDiam;
    float fPi = 3.1416;
    float fCir;

    cout<<"Enter a diameter: ";
    cin>>fDiam;

    fCir = fDiam*fPi;

    int iCir = (fCir+500)/1000;
    iCir = iCir*1000;


    cout<<"The circumference is: "<<iCir<<endl;
}

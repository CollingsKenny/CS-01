#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double dA;
    double dB;
    double dC;
    cout<<"Enter a side of a right triangle: ";
    cin>>dA;
    cout<<endl;
    cout<<"Enter another side: ";
    cin>>dB;
    cout<<endl;

    dC = sqrt((dA*dA) + (dB*dB));

    cout<<"The hipponoantuskljase is: "<<dC;

    cout<<endl;


}

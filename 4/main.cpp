#include <iostream>


using namespace std;

int main()
{
    int iYear;
    int iThisYear = 2015;
    string saZodiac[12] = {"Rat","Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig"};

    cout<<"Year: ";
    cin>>iYear;

    if(iYear > iThisYear){
        cout<<"The year "<<iYear<<" is ";
        cout<<iYear-iThisYear<<" years in the future";
    }else if(iYear < iThisYear){
        cout<<"The year "<<iYear<<" is ";
        cout<<iThisYear-iYear<<" years in the past";
    }
    else{
        cout<<"The year "<<iYear<<" is ";
        cout<<"this year";
    }
    if(iYear%4==0){
        cout<<", and its a leap year";
    }
    int iZodIndex = iYear-4/12;
    cout<<", and its the year of the "<<saZodiac[iZodIndex];

}

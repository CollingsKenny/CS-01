#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int biggestNumber(int arr[], int length);
int sum(int arr[], int length);
float average(int arr[], int length);

int main()
{
    const int MAX_VAL = 10;
    const int SIZE = 21;

    srand(time(0));
    int iaRan[SIZE];
    int iLarg = 0;
    int iSum = 0;

    for(int i = 0; i < SIZE; i++)
    {
        iaRan[i]= rand()%MAX_VAL+1;
    }
    cout<<setprecision(3)<<fixed;
    cout<<"The biggest number is: "<<biggestNumber(iaRan, SIZE)<<"\nThe sum of all the numbers is: "<<sum(iaRan, SIZE)<<"\nThe average is: "<<average(iaRan, SIZE);
}
int biggestNumber(int arr[], int length)
{
    int iMax = 0;
    for(int i = 0; i < length; i++)
    {
        if(arr[i]>iMax)
            iMax = arr[i];
    }
    return iMax;
}
int sum(int arr[], int length)
{
    int iSum = 0;

    for(int i = 0; i < length; i++)
    {
        iSum+=arr[i];
    }
    return iSum;
}
float average(int arr[], int length)
{
   float fS = sum(arr,length);
   float fL = length;
   return fS/fL;
}



#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;



int main()
{
    srand(time(0));
    int size = 10;
    int arr[size];
    int iMax = 0;

    for(int i = 0; i < size;i++)
    {
        arr[i]=rand()%10;
        cout<<arr[i]<<" ";
    }
    for(int i = 0; i < size;i++)
    {
        if(arr[i]>iMax)
            iMax = arr[i];
    }

    cout<<"\nThe biggest number is: "<<iMax;

}

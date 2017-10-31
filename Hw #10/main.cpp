#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int searchList(int arr[], int iSize, int iVal);

int main()
{
   srand(time(0));
   const int SIZE = 10;
   int arr[SIZE];

   int iVal = rand()%9+1;
   int iVDex;

   //populate array
   for(int i = 0; i < SIZE; i++)
    {
        arr[i]= rand()%9+1;
    }

    //print
   for(int i=0; i < SIZE; i++)
    {
        cout<<arr[i]<<" ";
    }

    iVDex = searchList(arr, SIZE, iVal);

    cout<<"\nThe first closest value to "<<iVal<<" is "<<arr[iVDex]<<" whose index in the array is "<<iVDex;
}

int searchList(int arr[], int iSize, int iVal)
{
    int iDiff = abs(iVal-arr[0]);
    int iNdex = 0;

    for(int i=1; i < iSize; i++)
    {
        int iCompa = abs(iVal-arr[i]);
        if(iCompa < iDiff)
        {
            iDiff = iCompa;
            iNdex = i;
        }
    }
    return iNdex;
}

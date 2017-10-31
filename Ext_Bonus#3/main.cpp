#include <cstdlib>
#include <iostream>
#include <ctime>
#include <climits>

using namespace std;

int part(int data[], int iMin, int iMax);
void quickSort(int data[], int iMin, int iMax);

int main()
{
    const int MAX_VAL = 10;
    const int SIZE = 21;

    srand(time(0));
    int iaRan[SIZE];
    int iLarg = 0;
    int iSum = 0;

    //fill array with random numbers
    for(int i = 0; i < SIZE; i++)
    {
        iaRan[i]= rand()%MAX_VAL+1;
        iSum += iaRan[i];
        if(iaRan[i]>iLarg)
            iLarg = iaRan[i];
    }

    //sort and print
    quickSort(iaRan, 0, SIZE-1);
    cout<<"The Median is: "<<iaRan[SIZE/2];
}

int part(int data[], int iMin, int iMax)
{
    int i = iMin;
    int j = iMax;
    int tmp;
    int iPiv = data[(iMin+iMax)/2];
    while(i <= j)
    {
        while (data[i] < iPiv)
            i++;
        while (data[j] > iPiv)
            j--;
        if(i <= j)
        {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(int data[],int iMin, int iMax)
{
    int index = part(data, iMin, iMax);
    if(iMin < index-1)
        quickSort(data, iMin, index-1);
    if(index < iMax)
        quickSort(data, index, iMax);
}

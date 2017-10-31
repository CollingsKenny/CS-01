//this program demonstrates the vector pop_back function
//Program 7-29
#include <iostream>
using namespace std;

const int MAX_VALUE = 99;

int main()
{
    int arrVal[MAX_VALUE];
    int iLeng = 0;

    //arrVal[2,4,6];
    iLeng += 3;

    cout<<arrVal[3];

    //report the number of elements in the vector
    cout << "The size of the values is " << iLeng << endl;

    //Remove a value from the vector
    cout << "Popping a value from the vector...\n";
    iLeng--;
    cout << "The size of values is now " << iLeng << endl;

    //now remove another value from the vector
    cout << "Pooping a value from the vector...\n";
    iLeng--;
    cout << "The size of values is now " << iLeng << endl;

    //remove the last value from the vector.
    cout << "Popping a value from the vector...\n";
    iLeng--;
    cout << "The size of values is now " << iLeng << endl;

    return 0;
}


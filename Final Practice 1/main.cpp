#include <iostream>

using namespace std;

int main()
{
    const int DAYS_IN_YEARS = 365;     //define constants

    int iInput = 0;       //define variables
    int iYears = 0;
    int iDays = 0;

    cout << "Please input a number of days to convert to Years & Days: ";        //prompt user for input
    cin >> iInput;

    iYears = iInput / DAYS_IN_YEARS;    //calculate the number of years that the input equals
    iDays = iInput % DAYS_IN_YEARS;     //calculate the number of days leftover after getting the number of years

    cout << "=================" << endl;
    cout << iInput << " days equals: " << iYears << " years and " << iDays << " days" << endl;

    return 0;
}

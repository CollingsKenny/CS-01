#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void days(),totalInts(), readAndReport();



int main()
{
    //days();
    //totalInts();
    readAndReport();

}

void days()
{
    const int IDAYS_IN_YEAR = 365;
    int idays, iYears, iRem;

    cout<<"Enter an amount of days: ";
    cin>>idays;
    iYears = idays/IDAYS_IN_YEAR;
    iRem = idays%IDAYS_IN_YEAR;
    cout<<"That is "<<iYears<<" years, and "<<iRem<<" days.";
}

void totalInts()
{
    int iNum;
    int iSum = 0;
    char cAns;
    bool cont;

    while(cont){
        cout<<"Enter a number: ";
        cin>>iNum;
        iSum += iNum;


        cout<<"Continue?(y/n) ";
        cin>>cAns;

        cont = (cAns=='y');
    }
    cout<<"The total is: "<<iSum;
}

void readAndReport()
{
    int inum = 0;
    int inumcount =0;
    int isum = 0;
    int iaverage = 0;
    string sinput = "";

    ifstream readfile;
    readfile.open ("Scores.txt");

    if (readfile.is_open())
        while (readfile >> sinput)
        {
            inum = atoi(sinput.c_str());
            isum+=inum;
            inumcount++;
        }

    iaverage = isum/inumcount;
    readfile.close();

    ofstream writefile ("Result.txt");

    writefile << "Sum of numbers: " << isum << endl;
    writefile << "Average of numbers: " << iaverage << endl;

}

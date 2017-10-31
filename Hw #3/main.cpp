#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>

using namespace std;

string sOccur = "Occurences";
string sPerc = "Percentages";

int numberOfDigits(int iNumber){
    int iDigits = 0;
    while (iNumber > 0){
        iNumber /= 10;
        iDigits++;
    }
    return iDigits;
}

void spaces(int i){
    cout<<setfill(' ')<<setw(10-i)<<"";
}

void border(){
    spaces(sOccur.size()-1);
    cout<<setfill('=')<<setw(sOccur.size())<<"";
    spaces(sPerc.size()-5);
    cout<<setfill('=')<<setw(sPerc.size())<<"";
    cout<<endl;
}

int main()
{
    int iaCounter [6] = {};
    int iTotalTimes = 0;
    double dTotalPerc = 0.0;
    int iRollTimes = 6000;
    cout<<fixed<<setprecision(3);

    srand(time(NULL));

    for(int iTimes = iRollTimes; iTimes > 0; iTimes--){

        int iRan = rand() % 6 + 1;
        iaCounter[iRan-1]++;
    }

    spaces(sOccur.size()-1);
    cout<<sOccur;
    spaces(sPerc.size()-5);
    cout<<sPerc;
    cout<<endl;

    border();

    for(int i = 0; i < 6; i++){
        cout<<i+1;
        spaces(numberOfDigits(iaCounter[i]));
        cout<<iaCounter[i];
        double dPercent = iaCounter[i];
        dPercent /= iRollTimes;
        dPercent *= 100.0;
        spaces(numberOfDigits(dPercent));
        cout<<dPercent<<'%';
        cout<<endl;

        dTotalPerc += dPercent;
        iTotalTimes += iaCounter[i];
    }

    border();

    spaces(numberOfDigits(iTotalTimes)-1);
    cout<<iTotalTimes;
    spaces(numberOfDigits(dTotalPerc));
    cout<<dTotalPerc<<"%"<<endl;

    return 0;
}

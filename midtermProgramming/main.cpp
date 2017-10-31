#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <istream>
#include <sstream>
using namespace std;
void randomGuess1(), randomDice2();
int main()
{
    randomGuess1();
    randomDice2();
    return 0;
}
void randomGuess1()
{
//The average number of guesses is probably around 7. This is assuming a worst case amount of guesses at 9--three for each 10's place.
//In the worst case the user would input 5, then would be told to either go higher or lower. If it says to go higher than the user would guess 7. Then if still not correct, the user would know this 10's place to be 6 or 8.
//If the user followed this algorithm, and in the worst case he would have made 9 guesses. Not every case is the worst, so I figured 7 guesses is a good amount.
    srand(time(0));
    int iAns = rand() % 1000 + 1;
    int iGuess;
    do
    {
        cout<<"Guess a number between 1 and 1000: ";
        cin>>iGuess;
        if(iGuess>1000||iGuess<1)
            cout<<"Try within the bounds"<<endl;
        else
        {
            if(iGuess>iAns)
                cout<<"Try lower"<<endl;
            if(iGuess<iAns)
                cout<<"Try higher"<<endl;
        }
    }
    while(iGuess!=iAns);
    cout<<"Good Job! The answer was: "<<iAns;
}
void randomDice2()
{
    string sLine;
    ifstream ranFile ("randomNumbers.txt");
    float fTimes[6];
    int iTotalTimes = 0;
    if(!ranFile)
    {
        cout<<"Wheres the file?";
        return;
    }
    while(getline(ranFile,sLine))
    {
        stringstream ss(sLine);
        int iRand;
        for(int i = 0; ss>>iRand; i++)
        {
            fTimes[iRand%6]++;
            iTotalTimes++;
        }
    }
    cout<<setprecision(3)<<fixed;
    for(int i=0; i<6; i++)
    {
        cout<<"Side "<<i+1<<":";
        cout<<setw(8)<<(fTimes[i]/iTotalTimes)*100<<"%"<<endl;
    }
}

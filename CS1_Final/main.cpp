#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

struct Student
{
    int iTra;
    int iId;
    string sName;
    string sCourse;
    int iCred;
    int iScore;
};

bool addRecord(vector <Student> &studVec, int iId, string sName, string sCourse, int iCred, int iScore)
{
    for(int i=0; i<studVec.size(); i++)
    {
        if((iId == studVec[i].iId)&&(sCourse == studVec[i].sCourse))
        {
            return false;
        }
    }
    Student stu;
    stu.iId = iId;
    stu.sName = sName;
    stu.sCourse = sCourse;
    stu.iCred = iCred;
    stu.iScore = iScore;
    studVec.push_back(stu);
    return true;
}

bool updateRecord(vector <Student> &studVec, int iId, string sCourse, int iScore)
{
    for(int i=0; i<studVec.size(); i++)
    {
        if((iId == studVec[i].iId)&&(sCourse == studVec[i].sCourse))
        {
            studVec[i].iScore = iScore;
            return true;
        }
    }
    return false;
}

bool delRecord(vector <Student> &studVec, int iId, string sCourse)
{
    for(int i=0; i<studVec.size(); i++)
    {
        if((iId == studVec[i].iId)&&(sCourse == studVec[i].sCourse))
        {
            studVec.erase(studVec.begin()+i);
            return true;
        }
    }
    return false;
}

bool delAllRecords(vector <Student> &studVec, int iId)
{
    for(int i=0; i<studVec.size(); i++)
    {
        if(iId == studVec[i].iId)
        {
            studVec.erase(studVec.begin()+i);
            return true;
        }
    }
    return false;
}

void doReport(vector <Student> &studVec)
{

    for (int i = 0; i < studVec.size(); i++)
    {

        printf("%7i %10s %6s %6i %6i \n", studVec[i].iId, studVec[i].sName.c_str(),studVec[i].sCourse.c_str(), studVec[i].iCred, studVec[i].iScore);

    }
    return;
}



void one()
{
    ifstream inputFile;
    ofstream errorFile;

    int iTra;
    char cOp;
    int iId;
    string sName;
    string sCourse;
    int iCred;
    int iScore;

    vector <Student> studVec;

    inputFile.open("studentRecordOps.txt");
    errorFile.open("errorLog.txt");

    while (inputFile >> iTra >> cOp >> iId >> sName >> sCourse >> iCred >> iScore)
    {
        if(cOp=='A')
        {
            if(!addRecord(studVec, iId, sName, sCourse, iCred, iScore))
            {
                errorFile << iTra <<" No record was added.\n";
            }
        }
        if(cOp=='U')
        {
            if(!updateRecord(studVec, iId, sCourse, iScore))
            {
                errorFile << iTra <<" No record was updated.\n";
            }
        }
        if(cOp=='D')
        {
            if(!delRecord(studVec, iId, sCourse))
            {
                errorFile << iTra <<" No record was deleted.\n";
            }
        }
        if(cOp=='E')
        {
            if(!delAllRecords(studVec, iId))
            {
                errorFile << iTra <<" No record was deleted.\n";
            }
        }
    }
    inputFile.close();
    errorFile.close();
    doReport(studVec);
}




void two()
{
    int iSize;
    cout<<"Enter a number: ";
    cin>>iSize;

    for(int i=0; i < iSize; i++)
    {
        for(int j=0; j < iSize; j++)
        {
            if((j%2==0&&i%2==0)||(j%2!=0&&i%2!=0))
            {
                cout<<'*';
            }
            else
                cout<<'_';
        }
        cout<<'\n';
    }
}

int three(char c [])
{
    int iSize = 0;
    int iTotal = 0;
    for(int i=strlen(c)-1; i >= 0; i--)
    {
        if((c[i]>=48)&&(c[i]<=57))
        {
            iSize++;
            int k = c[i]-'0';
            k *= round(pow(10,(iSize-1)));
            iTotal = iTotal+ k;
        }
    }
    cout<<'\n'<<iTotal<<'\n';
    return iTotal;
}

bool isPrime(int i)
{

    if(i==1)
        return true;
    if(i<1)
    {
        return false;
    }
    else if(i<=3)
    {
        return true;
    }
    else if((i%2==0)||(i%3)==0)
    {
        return false;
    }
    int iPiv = i/2;
    for(int j=2; j < iPiv; j++)
    {
        if(i%6==0)
            return false;
    }
    return true;
}


void bonus()
{
    int iMax;
    cout<<"Enter a number: ";
    cin>>iMax;
    for(int i=1; i <= iMax; i++)
    {
        if(isPrime(i))
            cout<<i<<" ";
    }
}


int main()
{
    one();
    two();
    three("123,456");
    bonus();

    return 0;
}

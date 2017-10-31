#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

///QUESTION 1
/*
int main()
{
    int iNput;
    cout<<"Enter a number: ";
    cin>>iNput;
    for(int row = 0; row < iNput; row++)
    {
        for(int col = 0; col< iNput; col++)
        {
           if((col>=iNput-row-1&&col<=row)||(col<=iNput-row-1&&col>=row))
                cout<<'*';
            else
                cout<<' ';
        }
        cout<<'\n';
    }
}

*/



///Question 2
//*


const int iStudSize = 999;
const int iMaxCourseAmt = 99;

struct Student
{
    int iId;
    string sName;
    string sCourse;
    int iCredit;
    int iScore;
    int iGrade;
};


void doReport(vector <Student> &studVec);
int getGrade(int iScore);
void addRecord(vector <Student> &studVec, int iId, string sName, string sCourse, int iCredit, int iScore);
bool updateRecord(vector <Student> &studVec, int iId, string sName, string sCourse, int iCredit, int iScore);
void deleteOne(vector <Student> &studVec, int iId, string sCourse);
void deleteAll(vector <Student> &studVec, int iId);


int main()
{

    ifstream inputFile;
    string sFilePath = "StudentRecords.txt";

    int iId, iScore, iCredit, iGrade;
    string sName, sCourse;

    vector <Student> studVec;

    inputFile.open(sFilePath.c_str());

    while (inputFile >> iId >> sName >> sCourse >> iCredit >> iScore)
    {
        if(0<=iScore&&iScore<=100)
        {
            if(!updateRecord(studVec,iId,sName,sCourse,iCredit,iScore))
            {
                addRecord(studVec, iId, sName, sCourse, iCredit, iScore);
            }
        }
        else if(iScore==998)
        {
            deleteOne(studVec,iId,sCourse);
        }
        else if(iScore==999)
        {
            deleteAll(studVec,iId);
        }
    }

    doReport(studVec);
    inputFile.close();

    return 0;
}

// Display report for all students
void doReport(vector <Student> &studVec)
{

    for (int i = 0; i < studVec.size(); i++)
    {

        printf("%7s %10s %6i %6i %6i \n", studVec[i].sName.c_str(),studVec[i].sCourse.c_str(), studVec[i].iCredit, studVec[i].iScore, studVec[i].iGrade);

    }
    return;
}

// Converts score to GPA
int getGrade(int iScore)
{
    int iGrade = -1;

    if (iScore >= 90)
       iGrade = 4;
    else if (iScore >= 80 && iScore <= 89)
       iGrade = 3;
    else if (iScore >= 70 && iScore <= 79)
       iGrade = 2;
    else if (iScore >= 60 && iScore <= 69)
       iGrade = 1;
    else
       iGrade =0;

    return iGrade;
}

//Adds a new record with given information
void addRecord(vector <Student> &studVec, int iId, string sName, string sCourse, int iCredit, int iScore)
{
        Student astud;
        int iGrade = getGrade(iScore);

        astud.iId = iId;
        astud.sName = sName;
        astud.sCourse = sCourse;
        astud.iCredit = iCredit;
        astud.iScore = iScore;
        astud.iGrade = iGrade;

        studVec.push_back(astud);
}

// Returns true if array was updated
bool updateRecord(vector <Student> &studVec, int iId, string sName, string sCourse, int iCredit, int iScore)
{
    for(int i=0; i < studVec.size(); i++)
    {
        if(studVec[i].iId==iId && studVec[i].sCourse==sCourse)
        {
            studVec[i].iScore = iScore;
            studVec[i].iGrade = getGrade(iScore);
            return true;
        }
    }
    return false;
}

//Removes ONE student with given ID and Course Name
void deleteOne(vector <Student> &studVec, int iId, string sCourse)
{
    for(int i=0; i < studVec.size(); i++)
    {
        if(studVec[i].iId==iId && studVec[i].sCourse==sCourse)
            studVec.erase(studVec.begin()+i);
    }
}

//Removes ALL students with given ID
void deleteAll(vector <Student> &studVec, int iId)
{
    for(int i=0; i < studVec.size(); i++)
    {
        if(studVec[i].iId==iId)
            studVec.erase(studVec.begin()+i);
    }
}


//*/

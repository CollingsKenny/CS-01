#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cmath>
using namespace std;

const int iRecSize = 999;

struct Student
{
    int iId;
	string sName;
	string sCourse;
	int iCredit;
	int iScore;
	int iGrade;
};

void doReport(Student studArr[], int iCount);
int getGrade(int iScore);
int addRecord(Student studArr[], int iId, string sName, string sCourse, int iCredit, int iScore, int iRecCount);
bool updateRecord(Student studArr[], int iId, string sName, string sCourse, int iCredit, int iScore, int iRecCount);
int deleteOne(Student studArr[], int iId, string sCourse, int iRecCount);
int deleteAll(Student studArr[], int iId, int iRecCount);
int deleteStud(Student studArr[], int index, int iRecCount);


int main()
{

    ifstream inputFile;
    string sFilePath = "StudentRecords.txt";

    int iId, iScore, iCredit;
    string sName, sCourse;
    int iRecCount = 0;

    Student studArr[iRecSize];

    inputFile.open(sFilePath.c_str());

    while (inputFile >> iId >> sName >> sCourse >> iCredit >> iScore)
    {
        if(0<=iScore&&iScore<=100)
        {
            if(!updateRecord(studArr,iId,sName,sCourse,iCredit,iScore,iRecCount))
            {
                iRecCount = addRecord(studArr,iId,sName,sCourse,iCredit,iScore,iRecCount);
            }
        }
        else if(iScore==998)
        {
            iRecCount = deleteOne(studArr,iId,sCourse,iRecCount);
        }
        else if(iScore==999)
        {
            iRecCount = deleteAll(studArr,iId,iRecCount);
        }
    }

    doReport(studArr, iRecCount);
    inputFile.close();

    return 0;
}


///Display report for ALL students
void doReport(Student studArr[], int iCount)
{

    for (int i = 0; i < iCount; i++)
    {

        printf("%7s %10s %6i %6i %6i \n", studArr[i].sName.c_str(),studArr[i].sCourse.c_str(), studArr[i].iCredit, studArr[i].iScore, studArr[i].iGrade);

    }
    return;
}


/// Converts score to GPA
int getGrade(int iScore)
{
    int iGrade = (iScore/10)-5;  //calculate score
    if(iGrade < 0)
        return iGrade = 0;
    if(iGrade > 4)
        return iGrade = 4;

    return iGrade;
}

/// Returns the amount of students in the array.
int addRecord(Student studArr[], int iId, string sName, string sCourse, int iCredit, int iScore, int iRecCount)
{
    studArr[iRecCount].iId = iId;
    studArr[iRecCount].sName = sName;
    studArr[iRecCount].sCourse = sCourse;
    studArr[iRecCount].iCredit = iCredit;
    studArr[iRecCount].iScore = iScore;
    studArr[iRecCount].iGrade = getGrade(iScore);

    return iRecCount+=1;

}


/// Returns true if array was updated
bool updateRecord (Student studArr[], int iId, string sName, string sCourse, int iCredit, int iScore, int iRecCount)
{
    for(int i=0; i < iRecCount; i++)
    {
        if(studArr[i].iId==iId && studArr[i].sCourse==sCourse)
        {
            studArr[i].iScore = iScore;
            studArr[i].iGrade = getGrade(iScore);
            return true;
        }
    }
    return false;
}

/// Removes one student with given ID and course name and returns the new array size
int deleteOne(Student studArr[], int iId, string sCourse, int iRecCount)
{
    for(int i=0; i < iRecCount; i++)
    {
        if(studArr[i].iId==iId && studArr[i].sCourse==sCourse)
            iRecCount = deleteStud(studArr, i, iRecCount);
    }
    return iRecCount;
}

/// Removes all students with the given ID and returns the new array size
int deleteAll(Student studArr[], int iId, int iRecCount)
{
    for(int i=0; i < iRecCount; i++)
    {
        if(studArr[i].iId==iId)
            iRecCount = deleteStud(studArr, i, iRecCount);
    }
    return iRecCount;
}

/// `Removes a student from an array and shifts remaining students  and returns the new array size
int deleteStud(Student studArr[], int index, int iRecCount)
{
    for(int i = index; i<iRecCount-1; i++)
    {
        studArr[i]=studArr[i+1];
    }
    return iRecCount-=1;
}


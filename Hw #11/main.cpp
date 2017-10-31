#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

const int MAX_STUDENTS = 999;
const int MAX_COURSES = 99;
struct Course
{
    string sCourseName;
    int iCredit, iScore, iGrade;
};
struct Student
{
    int iId;
    string sName;
    Course cCourse[MAX_COURSES];
    int iNumCour = 0;

};

void doReport(Student studArr[], int iSize);

int main()
{
    Student studArr[MAX_STUDENTS];
    int iStuds = 0; //Number of Unique Students

    ifstream inputFile("StudentRecords.txt");
    if(!inputFile)
    {
        printf("Error opening file StudentRecords.txt");
        return 1;
    }

    int iId;
    string sName, sCourse;
    int iCredit, iScore, iGrade;

    while(inputFile >> iId >> sName >> sCourse >> iCredit >> iScore)
    {
        Student stu;
        int iStuLoc = iStuds; //student to edit
        Course cor;

        //create a course & populate
        cor.sCourseName = sCourse;
        cor.iCredit = iCredit;
        cor.iScore = iScore;
        iGrade = (iScore/10)-5;  //calculate score
        if(iGrade < 0)
            iGrade = 0;
        if(iGrade > 4)
            iGrade = 4;
        cor.iGrade = iGrade;

        //linear search to see if student already exists
        //if student exits, then set the student to edit(iStuLoc) as that one, and break loop
        for(int i = 0; i < iStuds; i++)
        {
            if(studArr[i].iId==iId)
            {
                iStuLoc = i;
                iStuds--;
                break;
            }
        }

        //create the student & populate
        studArr[iStuLoc].iId = iId;
        studArr[iStuLoc].sName = sName;
        studArr[iStuLoc].iNumCour++;
        studArr[iStuLoc].cCourse[studArr[iStuLoc].iNumCour-1]=cor;

        iStuds++;
    }
    inputFile.close();
    doReport(studArr, iStuds);
    return 0;
}

/**
Takes in the Student Array, and the amount of students
Prints out all information
*/
void doReport(Student studArr[], int iSize)
{
    for(int i=0; i < iSize; i++)
    {
        Student stu = studArr[i];
        int iGpa1=0;
        int iGpa2=0;

        printf(" %-10s\n",studArr[i].sName.c_str());
        printf("%10s %5s %5s %5s \n", "Course", "Credit", "Score", "Grade");
        printf("%10s %5s %5s %5s \n", "------", "------", "-----", "-----");

        for(int j=0; j<stu.iNumCour; j++)
        {
            Course cor = stu.cCourse[j];
            iGpa1 += cor.iCredit*cor.iGrade;
            iGpa2 += cor.iCredit;
            printf("%10s %5i %5i %5i \n", cor.sCourseName.c_str(), cor.iCredit, cor.iScore, cor.iGrade);

        }
        float fGpa = static_cast<float> (iGpa1/iGpa2);
        printf("%10s %5s %5s %5s \n", "------", "------", "-----", "-----");
        printf("%10s%5.2f\n" , "Gpa: ", fGpa);

        printf("\n\n");
    }
}

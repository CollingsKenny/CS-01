#include <iostream>
#include <fstream>

void createFiles(char sFile1[], char sFile2[]);
void combineFiles(char sFile1[], char sFile2[]);

using namespace std;

const int iSize = 7;

 int main()
{
    char charArr[iSize];

    const int iFNameSize=10;
    char sFile1[iFNameSize] = "test1.dat";
    char sFile2[iFNameSize] = "test2.dat";

    createFiles(sFile1, sFile2);
    combineFiles(sFile1, sFile2);

    return 0;
}



void combineFiles(char sFile1[], char sFile2[])
{
    fstream file1;
    fstream file2;
    char charArr[iSize];


    file2.open(sFile2, ios::in|ios::binary);
    file2.read(charArr, sizeof(charArr));

    file2.close();

    file1.open(sFile1, ios::out|ios::binary|ios::app);
    file1.write(charArr, sizeof(charArr));

    file1.close();
}

void createFiles(char sFile1[], char sFile2[])
{
    char charArr1[iSize] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char charArr2[iSize] = {'H', 'I', 'J', 'K', 'L', 'M', 'N'};

    fstream file1;
    fstream file2;

    file1.open(sFile1, ios::out|ios::binary);
    file1.write(charArr1, sizeof(charArr1));

    file1.close();

    file2.open(sFile2, ios::out|ios::binary);
    file2.write(charArr2, sizeof(charArr2));

    file2.close();

}

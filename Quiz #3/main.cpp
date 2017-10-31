#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

const int MAX_WORD_SIZE = 20;
struct Pal
{
    string sName;
    int iOcc = 1;
};


int myStrLen(char str[]);
int myStrCmp(char str1[], char str2[]);
bool isPalindomic(char str[]);
string cleanStr(string s);
int part(Pal data[], int iMin, int iMax);
void quickSort(Pal data[],int iMin, int iMax);


int main()
{
    char sCh[MAX_WORD_SIZE];
    Pal palArray[50];
    int iNumPals = 0;

    ifstream inputFile("NotesBetweenTwoSisters.txt");
    if(!inputFile)
    {
        cout<<"Where is NotesBetweenTwoSisters.txt?";
        return 1;
    }
    while(inputFile >> sCh)
    {
        string s = sCh;
        strcpy(sCh, cleanStr(s).c_str());
        if(isPalindomic(sCh))
        {
            bool bCont = true;
            for(int i =0; i<iNumPals&&bCont; i++)
            {
                char ch1[20];
                strcpy(ch1, palArray[i].sName.c_str());

                if(myStrCmp(ch1,sCh))
                {
                    palArray[i].iOcc++;
                    bCont=false;
                }
            }
            if(bCont)
            {
                palArray[iNumPals].sName = sCh;
                iNumPals++;
            }
       }
    }
    quickSort(palArray, 0, iNumPals-1);
    printf(" %15s %15s\n", "Palindrome", "Occurrences");
    printf(" %15s %15s\n", "--------", "-------");
    for(int i = iNumPals-1; i>=0; i--)
    {
        Pal p = palArray[i];
        printf(" %15s %15i\n", p.sName.c_str(), p.iOcc);
    }
    return 0;
}


int myStrLen(char str[])
{
    int i = 0;
    for (i=0; str[i] != '\0'; i++);
    return i;
}

int myStrCmp(char str1[], char str2[])
{
    for(int i = 0; str1[i] != '\0'; i++)
    {
        if(toupper(str1[i])!=toupper(str2[i]))
        {
            return 0;
        }
    }
    return 1;
}

bool isPalindomic(char str[])
{
    int iL = myStrLen(str);
    for(int i=0; i<(iL/2)+1; i++)
    {
        if(toupper(str[i])!=toupper(str[iL-1-i]))
            return false;
    }
    return true;
}

string cleanStr(string s)
{
    for(int i = s.size()-1; i >= 0; i--)
    {
        if(ispunct(s[i]))
        {
            s.erase(i, 1);
        }
    }
    return s;
}

int part(Pal data[], int iMin, int iMax)
{
    int i = iMin;
    int j = iMax;
    Pal tmp;
    int iPiv = data[(iMin+iMax)/2].iOcc;
    while(i <= j)
    {
        while (data[i].iOcc < iPiv)
            i++;
        while (data[j].iOcc > iPiv)
            j--;
        if(i <= j)
        {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(Pal data[],int iMin, int iMax)
{
    int index = part(data, iMin, iMax);
    if(iMin < index-1)
        quickSort(data, iMin, index-1);
    if(index < iMax)
        quickSort(data, index, iMax);
}

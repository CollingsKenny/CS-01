#include <iostream>

using namespace std;

void mystrcpy(char str1[], char str2[]);
void mystrcat(char str1[], char str2[]);
void mystrcatBounds(char str1[], char str2[], int length);
int mystrlen(char str[]);
bool isPalindomic(char str[]);

int main()
{
    char s1[6] = "bb" ;
    char s2[30] = "12345678";
    char s3[30] = "racecar";
    if(isPalindomic(s3))
        cout<<s3<<" is a palindrome"<<endl;
    //cout<<s1;
    cout<<"s1: "<<s1<<endl;
    cout<<"s2: "<<s2<<endl;
    //cout<<s3<<endl;
    cout<<endl;
    mystrcatBounds(s1,s2,6);


    cout<<"s1: "<<s1<<endl;
    cout<<"s2: "<<s2<<endl;
    //cout<<s3<<endl;
}
void mystrcpy(char str1[], char str2[]){
    int i = 0;
    for (i=0; str2[i] != '\0'; i++)
        str1[i] = str2[i];  // Content of s1 is replaced by that of s2
    str1[i] = '\0'; // Finally assign null char to the end of the C-string
}

void mystrcat(char str1[], char str2[])
{
    int i1L = mystrlen(str1);
    int i2L = mystrlen(str2);
    for (int i=0; str2[i] != '\0'; i++)
    {
        str1[i1L+i]=str2[i];
    }
    str1[i1L+i2L]='\0';

}

void mystrcatBounds(char str1[], char str2[], int length)
{
    int iL = mystrlen(str1);
    int i;
    for (i=0; (str2[i] != '\0')&&(iL+i < length-1); i++)
    {
        str1[iL+i]=str2[i];
    }
    str1[iL+i]='\0';
}


int mystrlen(char str[])
{
    int i = 0;
    for (i=0; str[i] != '\0'; i++);
    return i;
}

bool isPalindomic(char str[])
{
    int iL = mystrlen(str);
    for( int i = 0; str[i] != '\0';i++)
        str[i]=toupper(str[i]);
    for(int i=0; i<iL/2; i++)
    {
        if(str[i]!=str[iL-1-i])
            return false;
    }
    return true;
}

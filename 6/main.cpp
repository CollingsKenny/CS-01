#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int iMaze [5][5];
void printLoc(int iRow, int iCol)
{
    int iLoc = iMaze[iRow,iCol];

    if(iLoc==0)
            cout<<"Theres a wall"<<endl;
    else if(iLoc==1)
            cout<<"Theres space"<<endl;
    else(iLoc==2)
            cout<<"Theres a monster"<<endl;



}
int main()
{



        iMaze [0][0]=0;iMaze [0][1]=0;iMaze [0][2]=0;iMaze [0][3]=0;iMaze [0][4]=0;iMaze [0][5]=0;
        iMaze [1][0]=0;iMaze [1][1]=1;iMaze [1][2]=1;iMaze [1][3]=1;iMaze [1][4]=1;iMaze [1][5]=0;
        iMaze [2][0]=0;iMaze [2][1]=0;iMaze [2][2]=1;iMaze [2][3]=0;iMaze [2][4]=2;iMaze [2][5]=0;
        iMaze [3][0]=0;iMaze [3][1]=1;iMaze [3][2]=1;iMaze [3][3]=1;iMaze [3][4]=1;iMaze [3][5]=0;
        iMaze [4][0]=0;iMaze [4][1]=0;iMaze [4][2]=0;iMaze [4][3]=1;iMaze [4][4]=0;iMaze [4][5]=0;
        iMaze [5][0]=0;iMaze [5][1]=0;iMaze [5][2]=0;iMaze [5][3]=0;iMaze [5][4]=0;iMaze [5][5]=0;

    int iPlayer_Row = 4;
    int iPlayer_Col = 3;
    int iaMod [3] = {-1,1};

    while(true)
    {
        if(iMaze[iPlayer_Row][iPlayer_Col]==2)
        {
            cout<<"\nlol the monster ate you";
            break;
        }
        else
        {
            string answer;
            cout<<"In front of you ";
            printLoc(iPlayer_Row+1,iPlayer_Col);

            cout<<"Behind you ";
            printLoc(iPlayer_Row-1,iPlayer_Col);

            cout<<"To your right ";
            printLoc(iPlayer_Row,iPlayer_Col+1);

            cout<<"To your left ";
            printLoc(iPlayer_Row,iPlayer_Col-1);

            cout<<"Where would you like to go (up,down,left,right)";
            cin>>answer;

            if(answer=="up")
                iPlayer_Row++;
            else if(answer=="down")
                cout<<"lol";
        }
    }


    return 0;
}

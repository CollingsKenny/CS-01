#include <iostream>

using namespace std;


void tri(int iNput)
{

    for(int row = 0; row < iNput; row++)
    {
        //2*iNput-1
        for(int col = 1; col <= row+iNput; col++)
        {
            if(col>=iNput-row)
                cout<<'*';
            else
                cout<<'_';
        }
        cout<<'\n';
    }
}

void one(int iNput)
{
    for(int row = 0; row < iNput; row++)
    {
        for(int col = 0; col < row+1; col++)
        {
                cout<<'*';
        }
        cout<<'\n';
    }
}
void two(int iNput)
{
    for(int row = 0; row < iNput; row++)
    {
        for(int col = 0; col < iNput; col++)
        {
            if(col > row)
                cout<<'*';
            else
                cout<<'_';
        }
        cout<<'\n';
    }
}

void three(int iNput)
{
    for(int row = 0; row < iNput; row++)
    {
        for(int col = 0; col <= iNput-row-1; col++)
        {
           //col<=iNput-row&&
            if(col<=iNput-row-1&&col>=row)
                cout<<'*';
            else
                cout<<'_';
        }
        cout<<'\n';
    }
}
void four(int iNput)
{
    for(int row = 0; row < iNput; row++)
    {
        for(int col = 0; col<=iNput-row-1&&col<=row; col++)
        {
           cout<<'*';
        }
        cout<<'\n';
    }
}

void five(int iNput)
{
    for(int row = 0; row < iNput; row++)
    {
        for(int col = 0; col< iNput; col++)
        {
           if(col>=iNput-row-1&&col<=row)
                cout<<'*';
            else
                cout<<'_';
        }
        cout<<'\n';
    }
}
void six(int iNput)
{
    for(int row = 0; row < iNput; row++)
    {
        for(int col = 0; col< iNput; col++)
        {
           if(col>=iNput-row-1&&col>=row)
                cout<<'*';
            else
                cout<<'_';
        }
        cout<<'\n';
    }
}
void seven(int iNput)
{
    for(int row = 0; row < iNput; row++)
    {
        for(int col = 0; col< iNput; col++)
        {
           if((col>=iNput-row-1&&col<=row)||(col<=iNput-row-1&&col>=row))
                cout<<'*';
            else
                cout<<'_';
        }
        cout<<'\n';
    }
}
void eight(int iNput)
{
    for(int row = 0; row < iNput; row++)
    {
        for(int col = 0; col< iNput; col++)
        {
           if((col<=iNput-row-1&&col<=row)||(col>=iNput-row-1&&col>=row))
                cout<<'*';
            else
                cout<<'_';
        }
        cout<<'\n';
    }
}

void whole(int iNput)
{
    for(int row = 0; row < iNput*8; row++)
    {

        cout<<row;
        for(int col = 0; col < iNput; col++)
        {

            if(row<iNput)
            {
                if(col>row)
                    cout<<'_';
                else
                    cout<<'*';
            }
            else if(row>=iNput&&row<iNput*2)
            {

                if(col > row-iNput-1)
                    cout<<'*';
                else
                    cout<<'_';
            }
            else if(row>=iNput*2&&row<iNput*3)
            {
                 if(col<=(iNput*3)-row-1&&col>=row-(iNput*2))
                    cout<<'*';
                else
                    cout<<'_';
            }
            else if(row>=iNput*3&&row<iNput*4)
            {
                 if(col<=(iNput*4)-row-1&&col<=row-(iNput*3))
                    cout<<'*';
                else
                    cout<<'_';
            }
            else if(row>=iNput*4&&row<iNput*5)
            {
                 if(col<=(iNput*5)-row-1&&col>=row-(iNput*4))
                    cout<<'*';
                else
                    cout<<'_';
            }
            else if(row>=iNput*5&&row<iNput*6)
            {
                 if(col>=(iNput*6)-row-1&&col>=row-(iNput*5))
                    cout<<'*';
                else
                    cout<<'_';
            }
            else if(row>=iNput*6&&row<iNput*5)
            {
                 if((col>=(iNput*5)-row-1&&col<=row-(iNput*6))||(col<=(iNput*5)-row-1&&col>=row-(iNput*6)))
                    cout<<'*';
                else
                    cout<<'_';
            }
            else if(row>=iNput*7&&row<iNput*8)
            {
                 if(col<=(iNput*7)-row-1&&col<=row-(iNput*8))
                    cout<<'*';
                else
                    cout<<'_';
            }
        }
        cout<<'\n';
    }
}


int main()
{
    int iNput=11;

//    cout<<"#: ";
//    cin>>iNput;


    one(iNput);
    two(iNput);
    three(iNput);
    four(iNput);
    five(iNput);
    six(iNput);
    seven(iNput);
    eight(iNput);


//    whole(iNput);


    return 0;
}

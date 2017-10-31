#include <iostream>

using namespace std;

int getSum(int x)
{
    if(x==0)
        return x;
    return x + getSum(x-1);
}

int main()
{
    cout << getSum (10);
    return 0;
}

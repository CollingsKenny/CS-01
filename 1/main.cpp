#include <iostream>

using namespace std;
void ex3(){
    bool bRepeat = true;
        while(bRepeat){
            int iInput;

            cout<< "Enter a Number: "<<endl;
            cin >> iInput;
            if(iInput==0)
                bRepeat = false;
            else{
                for(int iOutTimes = iInput; iOutTimes>0 ;iOutTimes--)
                {
                    for(int iRow = iOutTimes; iRow >0; iRow--)
                        cout<< "*";


                    cout<<endl;
                }
                for(int iOutTimes = iInput-1; iOutTimes>0 ;iOutTimes--)
                {
                    for(int iRow = iInput-iOutTimes+1; iRow >0; iRow--)
                        cout<< "*";


                    cout<<endl;
                }
            }
        }
}

int ex4()
{
    int iSize = 0;
    short int iShortInt  = 0;
    iSize = sizeof('1');
    cout << "Size of  char '1':" << iSize << endl;
    iSize = sizeof(1);
    cout << "Size of  int 1:" << iSize << endl;
    iSize = sizeof(iShortInt );
    cout << "Size of a short int:" << iSize << endl;
    iSize = sizeof("1");
    cout << "Size of string 1:" << iSize << endl;
    // Why the size of “1” is 2?

    char cLetter;
   	cLetter = 65;     //  65 = 64 + 1
 	cout << cLetter << endl;   // What is displayed?
	cLetter = 66;     // 66 = 64 + 2
   	cout << cLetter << endl;  // What is displayed?


    return 1;


}



int main()
{
    //ex4();
    ex3();

    return 0;
}

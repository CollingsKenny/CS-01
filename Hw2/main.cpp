#include <iostream>
#include <iomanip>

using namespace std;

int numberOfDigits(int iNumber){
    int iDigits = 0;
    while (iNumber > 0){
        iNumber /= 10;
        iDigits++;
    }
    return iDigits;
}

void spaces(string sPhrase, int i){
    cout<<sPhrase;
    int iFill = 50-(sPhrase.size()+i);

    cout<<setfill(' ')<<setw(iFill)<<"";


    /*

    for(int iSpaces = 50-(sPhrase.size()+i); iSpaces > 0; iSpaces--){
            cout<<" ";
        }
    */
}
void border(){
    cout<<setfill('=')<<setw(50)<<""<<endl;
}

int main()
{
    int iAmount = 751;
    double dPrice = 35.125;
    double dPaid = iAmount*dPrice;
    double dCom = dPaid*.02;

    cout<<fixed;
    cout<<setprecision(3);

    border();

    spaces("The price per share:",numberOfDigits(dPrice)+5);
    cout<<"$"<<dPrice<<endl;

    spaces("The amount of shares purchased:",numberOfDigits(iAmount));
    cout<<iAmount<<endl;

    cout<<setprecision(2);
    spaces("The amount paid for the stock:",numberOfDigits(dPaid)+4);
    cout<<"$"<<dPaid<<endl;

    spaces("The amount of commission:",numberOfDigits(dPaid*.02)+4);
    cout<<"$"<<dPaid*.02<<endl;

    spaces("The total:",numberOfDigits(dPaid+dCom)+4);
    cout<<"$"<<dPaid+dCom<<endl;

    border();

    return 0;
}

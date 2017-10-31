#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>
#include <iomanip>
#include <cmath>


using namespace std;

int main()
{
    double const COM_RATE = .01;
    vector<double> dNS;
    vector<double> dSP;
    vector<double> dSC;
    vector<double> dPP;
    vector<double> dPC;

    vector<double> dProfit;

    ifstream stockFile ("StockTransactions.txt");
    if(!stockFile)
    {
        cout<<"Wheres the file?";
        return 1;
    }
    string sLine;

    //import from file
    while(getline(stockFile,sLine))
    {
        stringstream ss(sLine);
        double dTNS;
        double dTSP;
        double dTPP;

        if(ss>>dTNS)
        {
            ss>>dTSP>>dTPP;
            dNS.push_back(dTNS);
            dSP.push_back(dTSP);
            dPP.push_back(dTPP);
        }
    }

    stockFile.close();

    //calculate
    for(int i = 0; i < dNS.size(); i++)
    { //this is a open bracket
        dSC.push_back((dNS[i]*dSP[i])*COM_RATE); //commission
        dPC.push_back((dNS[i]*dPP[i])*COM_RATE);
        dProfit.push_back(((dNS[i]*dSP[i])-dSC[i])-((dNS[i]*dPP[i])+dPC[i]));  //profit
        int itemp =((dSC[i]*100)+.5)/100;
        dSC[i] = itemp;
    }

    //Print
    cout<<left<<setw(10)<<"NS"<<setw(10)<<"SP"<<setw(10)<<"SC"<<setw(10)<<"PP"<<setw(10)<<"PC"<<setw(10)<<"Profit/Loss"<<"\n----------\n";
    for(int i = 0; i < dNS.size(); i++)
    {
        cout<<setprecision(0)<<fixed;
        cout<<setw(10)<<dNS[i]<<setprecision(2)<<setw(10)<<dSP[i]<<setw(10)<<dSC[i]<<setw(10)<<dPP[i]<<setw(10)<<dPC[i]<<setw(10)<<abs(dProfit[i])<<'\n';
    }
    return 0;
}

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ifstream scoresFile;
    ofstream reportFile;
    string sCores,sTemp;
    vector<string> vScores;
    vector<int> vLegitScores;

    int iAmountValid = 0;
    double dAverage;

    scoresFile.open("scores.txt",ios::in);
    getline(scoresFile,sCores);
    scoresFile.close();

//create list of possible scores
    for(int i = 0; i < sCores.size(); i++)
    {
        char c = sCores[i];
        string s;
        stringstream ss;

        if(c==' ')
        {
            if(sTemp.size() > 0)
            {
                vScores.push_back(sTemp);
                sTemp.clear();
            }
        }
        else
        {
            ss << c;
            ss >> s;
            sTemp = sTemp.append(s);
        }
    }

//Validate possible scores
    for(int i = vScores.size()-1; i >= 0; i--)
    {

        int iTemp;

        istringstream iss(vScores[i]);

        if(!(iss >> iTemp).fail())
        {
            if(iTemp>=0&&iTemp<=100){
                vLegitScores.push_back(iTemp);
                vScores.erase(vScores.begin()+i);
            }
        }
    }

//report scores
    reportFile.open("report.txt");
    reportFile << "The amount of valid scores is:     " << vLegitScores.size() << "\nThe valid scores are:     ";
    for(int i = vLegitScores.size()-1; i >= 0; i--)
    {
        reportFile<<vLegitScores[i]<<";";
        dAverage += vLegitScores[i];
    }
    dAverage = dAverage/vLegitScores.size();
    reportFile<<"\nThe average score is:     " << dAverage <<"\n===="<<"\nThe amount of invalid scores is:     "<<vScores.size()<<"\nThe invalid scores are:     ";
    for(int i = 0; i < vScores.size(); i++)
    {
        reportFile<<vScores[i]<<";";
    }


    reportFile.close();
    return 0;
}

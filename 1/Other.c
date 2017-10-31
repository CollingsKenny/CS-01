#include <iostream>

using namespace std;

main(){

int iSize = 0;
Short int iShortInt  = 0;
iSize = sizeof('1');
 cout << "Size of  char ‘1’:" << iSize << endl;
 iSize = sizeof(1);
 cout << "Size of  int 1:" << iSize << endl;
 iSize = sizeof(iShortInt );
 cout << "Size of a short int:" << iSize << endl;
 iSize = sizeof("1");
 cout << "Size of string “1”:" << iSize << endl;
// Why the size of “1” is 2?

}



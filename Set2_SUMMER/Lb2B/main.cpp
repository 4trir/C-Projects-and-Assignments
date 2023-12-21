#include <iostream>
using namespace std;

int main(){
    int iNum = 9;
    double dNUM = 14.25;
    int *pINum1, *pINum2;
    double *pDNum;
    
    pINum1 = &iNum;
    cout << "Address of iNum value:" << endl << pINum1 << endl;
    cout << "Value of iNum:" << endl << *pINum1 << endl;

    /*pINum2 = &dNUM;
    main.cpp:13:14: error: invalid conversion from 'double*' to 'int' [-fpermissive]
     pINum2 = &dNUM;

    */
   pDNum = &dNUM;
   cout << "Address of dNum value:" << endl << pDNum << endl;
   cout << "Value of dNum:" << endl << *pDNum << endl;

   iNum = 7;
   cout << "New value of iNum:" << endl << *pINum1 << endl;
   pINum2 = pINum1;
   cout << "Adress of pInum2 value:" << endl << pINum2 << endl;
   cout << "Value of pInum2:" << endl << *pINum2 << endl;

   *pINum2 = 12;
   cout << "Final value of pINum1:" << endl << *pINum1 << endl;
   cout << "Final value of pINum2:" << endl << *pINum2 << endl;
   cout << "Final value of iNum:" << endl << iNum << endl;
}
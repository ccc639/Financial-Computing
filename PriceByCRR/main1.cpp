// HW1 Part 1-slide #24
//

#include "BinModel01.h"
#include "Options01.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
	double S0,U,D,R;
	// doble 
	if (GetInputData(S0,U,D,R)==1) return 1;

	double K;   //strike price
	int N;      //steps to expiry

	cout << "Enter call option data:" << endl;
	GetInputData(N,K);

	double *pricePtr = new double[N+1];

	cout << "European call option price = "
        << PriceByCRR(S0,U,D,R,N,K, pricePtr)
        << endl << endl;
   
	delete [] pricePtr;

    cout << "Calculate European call option price by HW1 Function: "
        << HW1PriceByCRR(S0,U,D,R,N,K)
        << endl << endl;
  
	cout << "Calculate European call option price by HW1 Function V2: "
        << HW1V2PriceByCRR(S0,U,D,R,N,K)
        << endl << endl;

	char c = getchar();
   
	do {
	   cout << "Temerminate the program (Y/N)?";
		c = getchar();
   } while ( c != 'Y' && c != 'y' );

   return 0;

}

/*
Enter S0: 106
Enter U:  0.15125
Enter D:  -0.13138
Enter R:  0.00545

Input data checked
There is no arbitrage

Enter call option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European call option price = 21.6811

Calculate European call option price by HW1 Function: 21.6811

Calculate European call option price by HW1 Function V2: 21.6811

Temerminate the program (Y/N)?
*/
#include "Options01.h"
#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(int& N, double& K)
{
   cout << "Enter steps to expiry N: "; cin >> N;
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;
   return 0;
}

double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K, double *Price)
{
   double q=RiskNeutProb(U ,D,R);
   //double Price[N+1];
   for (int i=0; i<=N; i++)
   {
      Price[i]=CallPayoff(S(S0,U,D,N,i),K);
   }
   for (int n=N-1; n>=0; n--)
   {
      for (int i=0; i<=n; i++)
      {
         Price[i]=(q*Price[i+1]+(1-q)*Price[i])/(1+R);
      }
   }
   return Price[0];
}

double CallPayoff(double z, double K)
{
   if (z>K) return z-K;
   return 0.0;
}

double HW1Function(int N, int n)
{
   if (n<0 || n>N) return 0;
   double result=1;
   for (int i=1; i<=n; i++) result=result*(N-n+i)/i;
   return result;
}

double HW1PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
   double p=RiskNeutProb(U,D,R);
   double Price=0;
   for (int n=0; n<=N; n++)
   {
      Price=Price+HW1Function(N,n)*pow(p,n)*pow(1-p,N-n)*CallPayoff(S(S0,U,D,N,n),K)/pow(1+R,N);
   }
   return Price;
}

double HW1Factorial(int n)
{
	double num = 1.0;
	if (n <= 0 )
		return num;

	do {
		num = num * n;
		n--;
	} while ( n > 0 );

	return num;
}

double HW1V2PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
	double p=RiskNeutProb(U,D,R);
	double Price=0;

	double FactorialN = HW1Factorial(N);
	for (int n=0; n<=N; n++)
	{
		Price=Price+(FactorialN/(HW1Factorial(n)*HW1Factorial(N-n)))
			*pow(p,n)*pow(1-p,N-n)*CallPayoff(S(S0,U,D,N,n),K)/pow(1+R,N);
	}
	return Price;
}
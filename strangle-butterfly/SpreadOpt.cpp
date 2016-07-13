#include "SpreadOpt.h"
#include <iostream>
using namespace std;

int StrangleOpt::GetInputData()
{
	cout << "Enter European strangle option spread data:" << endl;
	int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	cout << "Enter parameter K1:      "; cin >> K1;
	cout << "Enter parameter K2:      "; cin >> K2;
	cout << endl;
	return 0;
}

double StrangleOpt::Payoff(double z)
{
	if (z <= K1) return K1 - z;
	if (z>K2) return z - K2;
	return 0.0;
}

int ButterflyOpt::GetInputData()
{
	cout << "Enter European butterfly spread option data:" << endl;
	int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	cout << "Enter parameter K1:      "; cin >> K1;
	cout << "Enter parameter K2:      "; cin >> K2;
	cout << endl;
	return 0;
}

double ButterflyOpt::Payoff(double z)
{
	if (K1<z && z <= (K1 + K2)*0.5) return z - K1;
	if ((K1 + K2)*0.5<z && z <= K2) return K2 - z;
	return 0.0;
}

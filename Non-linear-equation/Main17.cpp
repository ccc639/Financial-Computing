#include "Solver03.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class Bond
{
private:
	double F, T;
	vector<double> C;
	vector<double> t;

public:
	Bond(double F_, double T_, vector<double>& C_, vector<double>& t_)
	{
		F = F_; T = T_; C = C_; t = t_;
	}
	double Value(double y)
	{
		double P = 0.0;
		for (unsigned int n = 0; n<C.size(); n++)
		{
			P += C[n] * exp(-y*t[n]);
		}
		P += F*exp(-y*T);

		return P;
	}
	double Deriv(double y)
	{
		double D = 0.0;
		for (unsigned int n = 0; n<C.size(); n++)
		{
			D += -t[n] * C[n] * exp(-y*t[n]);
		}
		D += -T*F*exp(-y*T);

		return D;
	}
};

int main()
{
	double F = 100.0;
	double T = 3.0;
	vector<double> C;
	C.push_back(1.2); C.push_back(1.2); C.push_back(1.2);
	vector<double> t;
	t.push_back(1.0); t.push_back(2.0); t.push_back(3.0);
	double P = 98.56;

	Bond MyBond(F, T, C, t);

	cout << "Face value F= " << F << endl;
	cout << "Maturity T= " << T << endl;
	cout << "Fixed coupons C: ";
	for (unsigned int n = 0; n<C.size(); n++)
	{
		cout << C[n] << "  ";
	}
	cout << endl;
	cout << "Time t: ";
	for (unsigned int n = 0; n<t.size(); n++)
	{
		cout << t[n] << "  ";
	}
	cout << endl;
	cout << "Bond price at t0, P= " << P << endl << endl;

	double LEnd = 0.0;
	double REnd = 1.0;
	double Acc = 0.0001;
	cout << "Yield by bisect: "
		<< SolveByBisect(&MyBond, P, LEnd, REnd, Acc) * 100 << "%"
		<< endl;

	double Guess = 0.2;
	cout << "Yield by Newton-Raphson: "
		<< SolveByNR(&MyBond, P, Guess, Acc) * 100 << "%"
		<< endl;
	char x; cin >> x;
	return 0;
}


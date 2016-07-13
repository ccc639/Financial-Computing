#include "BinModel02.h"
#include "BSModel.h"
#include "Options09.h"
#include <iostream>


int main()
{
	double S0 = 106.0;
	double r = 0.058;
	double sigma = 0.46;
	double T = (double)9 / 12;
	double K = 100.0;
	int    N = 8;

	cout << setiosflags(ios::fixed) << setprecision(5);

	cout << "S0 =    " << S0 << endl;
	cout << "r =     " << r << endl;
	cout << "sigma = " << sigma << endl;
	cout << "T =     " << T << endl;
	cout << "K =     " << K << endl;
	cout << "N =     " << N << endl;
	cout << endl;

	BSModel Model(S0, r, sigma);
	double h = T / N;
	BinModel ApproxModel = Model.ApproxBinModel(h);
	cout << "U = " << ApproxModel.GetU() << endl;
	cout << "D = " << ApproxModel.GetD() << endl;
	cout << "R = " << ApproxModel.GetR() << endl;

	Put Option(N, K);
	BinLattice<double> PriceTree;
	BinLattice<bool> StoppingTree;
	Option.PriceBySnell(ApproxModel, PriceTree, StoppingTree);
	cout << "American put option price: " << PriceTree.GetNode(0, 0) << endl;
	char x; cin >> x;
	return 0;
}

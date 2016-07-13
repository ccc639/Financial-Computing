#ifndef BinModel02_h
#define BinModel02_h

class BinModel
{
private:
	double S0, U, D, R;

public:
	BinModel(double S0_, double U_, double D_, double R_)
	{
		S0 = S0_; U = U_; D = D_; R = R_;
	}
	double RiskNeutProb();
	double S(int n, int i);
	int GetInputData();

	double GetU();
	double GetD();
	double GetR();
};

#endif

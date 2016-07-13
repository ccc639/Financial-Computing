#ifndef SpreadOpt_h
#define SpreadOpt_h

#include "Options06.h"

class StrangleOpt : public EurOption
{
private:
	double K1; //parameter 1
	double K2; //parameter 2
public:
	int GetInputData();
	double Payoff(double z);
};

class ButterflyOpt : public EurOption
{
private:
	double K1; //parameter 1
	double K2; //parameter 2
public:
	int GetInputData();
	double Payoff(double z);
};

#endif

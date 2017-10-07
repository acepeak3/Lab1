#include "GenerateMethods.h"

GenerateMethods::GenerateMethods() :
	methodNumber_(1)
{
}

GenerateMethods::~GenerateMethods()
{
}

void GenerateMethods::setMethod(const int _methodNumber)
{
	methodNumber_ = _methodNumber;

	switch (methodNumber_)
	{
	case 3:
		SetupMethod3Random();
	case 2:
		SetupMethod2Random();
	default:
		SetupMethod1Random();
	}
	 
}

double GenerateMethods::rand()
{
	switch (methodNumber_)
	{
	case 3:
		return Method3Random();
	case 2:
		return Method2Random();
	default:
		return Method1Random();
	}
}

void GenerateMethods::SetupMethod1Random()
{
	X_ = Method1Parameters::X0;
}

double GenerateMethods::Metod1X()
{
	return (Method1Parameters::a * X_ + Method1Parameters::c) % Method1Parameters::m;
}


double GenerateMethods::Method1Random()
{
	const uint64_t X = X_;
	X_ = Metod1X();
	return (double)X / Method1Parameters::m;
}

void GenerateMethods::SetupMethod2Random()
{
	X_ = Method2Parameters::X0;
}

double GenerateMethods::Metod2X()
{
	return (Method2Parameters::d * X_ * X_ + Method2Parameters::a * X_ + Method2Parameters::c) % Method2Parameters::m;
}

double GenerateMethods::Method2Random()
{
	const uint64_t X = X_;
	X_ = Metod2X();
	return (double)X / Method2Parameters::m;
}

void GenerateMethods::SetupMethod3Random()
{
	previousX_ = Method3Parameters::X0;
	X_ = Method3Parameters::X1;
}

double GenerateMethods::Method3Random()
{
	const uint64_t previousX = previousX_;
	previousX_ = X_;
	X_ = (previousX + previousX_) % Method3Parameters::m;
	return (double)previousX / Method3Parameters::m;
}

uint64_t GenerateMethods::Inverse(uint64_t _value, uint64_t _mod)
{
	uint64_t result = 1;

	while (_value * result %  _mod != 1) result++;

	return result;
	
	/*
	int i = 1;

	while ((x4*i) % p != 1) i++;

	x4 = (e * i + f) % p;

	u = static_cast<double>(x4) / m;

	return u;
	*/

}

void GenerateMethods::SetupMethod4Random()
{
	X_ = Method4Parameters::X0;
}

double GenerateMethods::Method4Random()
{
	const uint64_t X = X_;
	X_ = (Method4Parameters::a * Inverse(X_, Method4Parameters::m) + Method4Parameters::c) % Method4Parameters::m;
	return (double)X / Method4Parameters::m;
}

void GenerateMethods::SetupMethod5Random()
{
	X_ = Method4Parameters::X0;
}

double GenerateMethods::Method5Random()
{
	const uint64_t X = X_;

	X_ = Metod1X();
	Y_ = Metod2X();
	X_ = (X_ - Y_) % Method5Parameters::m;

	return (double)X / Method1Parameters::m;
}
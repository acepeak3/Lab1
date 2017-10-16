#include "GenerateMethods.h"

GenerateMethods::GenerateMethods() :
	methodNumber_(3),
	Sum_(0)
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
	case 6:
		SetupMethod6Random();
	case 5:
		SetupMethod5Random();
	case 4:
		SetupMethod4Random();
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
	case 6:
		return Method6Random();
	case 5:
		return Method5Random();
	case 4:
		return Method4Random();
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

uint64_t GenerateMethods::Inverse(const uint64_t _value, const uint64_t _mod)
{
	uint64_t n = _value, m = _mod, a = 1, b = 0, c = 0, d = 1;

	if (n >= m)
	{
		n %= m;
	}

	bool evenStep = true;

	while ((n != 1) && (m != 1))
	{
		if (evenStep)
		{
			uint64_t k = m / n;
			m %= n;
			a += c*k;
			b += d*k;
		}
		else
		{
			uint64_t k = n / m;
			n %= m;
			c += a*k;
			d += b*k;
		}

		evenStep = !evenStep;
	}

	return (evenStep ? d : _mod - b);

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

void GenerateMethods::SetupMethod6Random()
{
	X_ = Method4Parameters::X0;
}

double GenerateMethods::Method6Random()
{
	const uint64_t X = X_;

	for (size_t i = 0; i < Method6Parameters::twelve; ++i)
		Sum_ += Method1Random();

	return X_ = Method6Parameters::mu + (Sum_ - Method6Parameters::six) * Method6Parameters::sigma;
}

void GenerateMethods::SetupMethod7Random()
{
	X_ = Method4Parameters::X0;
}

double GenerateMethods::Method7Random()
{
	const uint64_t X = X_;

	X_ = Metod1X();
	Y_ = Metod2X();

	uint64_t V1 = 2 * X_ - 1;
	uint64_t V2 = 2 * Y_ - 1;

	X_ = V1 * V1 + V2 * V2;

	if (X_ < 1)
	{
		X_ = V1 * sqrt(-2 * log(X_) / X_);
		Y_ = V2 * sqrt(-2 * log(X_) / X_);
	}

	//if
		return X_;
}

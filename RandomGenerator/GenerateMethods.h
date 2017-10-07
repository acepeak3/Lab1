#pragma once

#include <cstdint>

#include "MethodParameters.h"

class GenerateMethods
{
public:

	GenerateMethods();
	~GenerateMethods();

	void setMethod(const int _methodNumber);

	double rand();

private:

	uint8_t methodNumber_;

	uint64_t X_, previousX_, Y_;

	double Metod1X();
	void SetupMethod1Random();
	double Method1Random();

	double Metod2X();
	void SetupMethod2Random();
	double Method2Random();

	void SetupMethod3Random();
	double Method3Random();

	uint64_t Inverse(uint64_t _value, uint64_t _mod);
	void SetupMethod4Random();
	double Method4Random();

	void SetupMethod5Random();
	double Method5Random();
};
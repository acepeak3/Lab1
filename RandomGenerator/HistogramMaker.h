#pragma once

#include <cstdint>
#include <vector>

#include "GenerateMethods.h"

class HistogramMaker
{
public:
	HistogramMaker(
		const size_t _methodNumber,
		const size_t _numberCount,
		const size_t _intervalCount);
	~HistogramMaker();

	std::vector<double> makeHistogram();

private:

	const size_t
		numberCount_,
		intervalCount_;

	GenerateMethods generateMethods_;

	std::vector<size_t> counts_;
};
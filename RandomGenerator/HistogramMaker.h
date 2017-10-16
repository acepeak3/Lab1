#pragma once

#include <cstdint>
#include <vector>
#include <iostream>

#include "GenerateMethods.h"

struct HistogramSignature
{
	const size_t intervalCount_;
	
	const double
		bottomBoundary_,
		topBoundary_;
};

class HistogramMaker
{
public:
	HistogramMaker(
		const size_t _methodNumber,
		const size_t _numberCount);
	~HistogramMaker();

	void makeHistogram();
	
	void printHistogram();


private:

	const size_t
		methodNumber_,
		numberCount_;

	HistogramSignature signature_;

	const double intervalLength_;
	
	std::vector<size_t> counts_;

	std::vector<double> histogram_;

	GenerateMethods generateMethods_;

	HistogramSignature chooseHistogramSignature();
	
};
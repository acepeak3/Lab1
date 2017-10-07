#include "HistogramMaker.h"

HistogramMaker::HistogramMaker(
	const size_t _methodNumber,
	const size_t _numberCount,
	const size_t _intervalCount) :
	generateMethods_(),
	numberCount_(_numberCount),
	intervalCount_(_intervalCount),
	counts_(_intervalCount, 0)
{
	generateMethods_.setMethod(_methodNumber);
}

HistogramMaker::~HistogramMaker()
{
}

std::vector<double> HistogramMaker::makeHistogram()
{
	for (size_t i = 0; i < numberCount_; i++)
	{
		const double nextX = generateMethods_.rand();
		const size_t intervalNumber = static_cast<size_t>(floor(nextX * intervalCount_));
		counts_[intervalNumber]++;
	}

	std::vector<double> histogram(intervalCount_);

	std::vector<double>::iterator histogramItarator = histogram.begin();

	for (std::vector<size_t>::iterator countIterator = counts_.begin(); countIterator != counts_.end(); countIterator++)
	{
		*histogramItarator = static_cast<double>(*countIterator) / numberCount_;
		histogramItarator++;
	}

	return histogram;
}
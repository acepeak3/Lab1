#include "HistogramMaker.h"

HistogramMaker::HistogramMaker(
	const size_t _methodNumber,
	const size_t _numberCount) :
	methodNumber_(_methodNumber),
	generateMethods_(),
	numberCount_(_numberCount),
	signature_(chooseHistogramSignature()),
	intervalLength_((signature_.topBoundary_ - signature_.bottomBoundary_) / signature_.intervalCount_),
	counts_(signature_.intervalCount_, 0),
	histogram_(signature_.intervalCount_)
{
	generateMethods_.setMethod(_methodNumber);
}

HistogramMaker::~HistogramMaker()
{
}

void HistogramMaker::makeHistogram()
{
	for (size_t i = 0; i < numberCount_; i++)
	{
		const double nextX = generateMethods_.rand();

		if ((nextX >= signature_.bottomBoundary_) && (nextX < signature_.topBoundary_))
		{
			const size_t intervalNumber = static_cast<size_t>
				(floor((nextX - signature_.bottomBoundary_) / intervalLength_));
			counts_[intervalNumber]++;
		}
	}

	std::vector<double>::iterator histogramItarator = histogram_.begin();

	for (std::vector<size_t>::iterator countIterator = counts_.begin(); countIterator != counts_.end(); countIterator++)
	{
		*histogramItarator = static_cast<double>(*countIterator) / numberCount_;
		histogramItarator++;
	}
}

void HistogramMaker::printHistogram()
{
	double summ = 0;

	for (size_t i = 0; i < signature_.intervalCount_; i++)
	{
		const double 
			intervalBottom = signature_.bottomBoundary_ + i * intervalLength_,
			intervalTop = intervalBottom + intervalLength_;
		std::cout << "[" << intervalBottom << ", " << intervalTop << "): " << histogram_[i] << "\n";

		summ += histogram_[i];
	}
	std::cout << summ << "\n";
}

HistogramSignature HistogramMaker::chooseHistogramSignature()
{
	switch (methodNumber_)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			return HistogramSignature{ 10, 0, 1 };
		case 6:
		case 7:
		case 8:
			return HistogramSignature{ 6, -3, 3 };
		case 9:
		case 10:
			return HistogramSignature{ 100, 0, 100 };
	}
}

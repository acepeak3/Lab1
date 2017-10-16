#include <iostream>
#include "HistogramMaker.h"

using namespace std;

void main()
{
	const size_t numberCount = 1000000;
	size_t	methodNumber;

	cin >> methodNumber;

	HistogramMaker histogramMaker(methodNumber, numberCount);

	histogramMaker.makeHistogram();

	histogramMaker.printHistogram();

	system("pause");
}
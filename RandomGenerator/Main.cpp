#include <iostream>
#include "HistogramMaker.h"

using namespace std;

/*
#include "GenerateMethods.h"

void main()
{	
	GenerateMethods generateMethods;

	generateMethods.setMethod(1);

	for (int i = 0; i < 100; i++)
	{
		std::cout << generateMethods.rand() << "\n";
	}

	system("pause");
}
*/

void coutHistogram(std::vector<double> histogram /*, size_t countOfSegments*/)
{
	cout << "[0, " << "0.1]\t" << histogram[0] << endl;

	double n = histogram[0];
	for (size_t i = 1; i < 9; ++i)
	{
		cout << "(0." << i << ", " << 0 << "." << i + 1 << "]\t" << histogram[i] << endl;
		n += histogram[i];
	}
	cout << "(0.9, " << 1 << "]\t" << histogram[9] << endl << endl;
	n += histogram[9];

	cout << n << endl;
}

void main()
{
	HistogramMaker histogramMaker(4, 50000, 10);

	std::vector<double> histogram = histogramMaker.makeHistogram();

	coutHistogram(histogram);

	system("pause");
}
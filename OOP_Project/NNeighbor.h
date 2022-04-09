#pragma once
#include "Classifier.h"
#define MAXSIDES 6
#define FAILEDTOFIND "Failed to match coordinates"

class NNeighbor : public Classifier
{

	std::vector<Data> dataSet;
	std::string evaluateClosest(Data);
	std::string evaluateMeans(Data);

public:
	void train(Data&);
	std::string predict(Data&);
	std::vector<Data> getDataSet();
	friend std::ostream& operator<<(std::ostream&, NNeighbor& model);
};


#pragma once
#include "Classifier.h"
#define MAXSIDES 6

class NNeighbor : public Classifier
{

	std::vector<Data> dataSet;


public:
	void train(Data&);
	std::string predict(Data&);
	std::vector<Data> getDataSet();
	friend std::ostream& operator<<(std::ostream&, NNeighbor& model);
};


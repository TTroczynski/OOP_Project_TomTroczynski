#pragma once
#include "Classifier.h"
#define MAXSIDES 6

class NNeighbor : public Classifier
{

	std::vector<Data> dataSet;


public:
	void train(Data&);
	std::string predict(Data&);
	void addData(Data&);
	

};


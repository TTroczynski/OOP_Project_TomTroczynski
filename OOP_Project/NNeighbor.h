
//! NNeighbor Class
/*!
* A machine learning model that inherits from the Classifier class.
* This model makes is trained using Data objects containing x, y, z coordinates and a classifier label.
* Predicitions are made first by checking for an edge case, 2 equidistant points,
* This class implements:
* @see train()
* @see predict()
* behaviours from the Classifier class.
*/
#pragma once
#include "Classifier.h"
#define MAXSIDES 6
#define FAILEDTOFIND "Failed to match coordinates"

class NNeighbor : public Classifier
{

	std::vector<Data> dataSet;
	std::string evaluateClosest(Data&);
	std::string evaluateMeans(Data&);

public:
	void train(Data&);
	std::string predict(Data&);
	std::vector<Data> getDataSet();
	friend std::ostream& operator<<(std::ostream&, NNeighbor& model);
};


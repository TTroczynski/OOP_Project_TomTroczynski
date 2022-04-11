
//! NNeighbor Class
/*!
* A machine learning model that inherits from the Classifier class.
* This model is trained using Data objects containing x, y, z coordinates and a classifier label.
* Predicitions are made first by checking for an edge case, 2 equidistant points,
* The closest point is selected when classifying a vector. If there are two equidistant points
* then, the mean location for each set containing each label is evaluated. The closes mean is chosen.
* 
* This class implements:
* @see train()
* @see predict()
* behaviours from the Classifier class.
*/
#pragma once
#include "Classifier.h"
#define MAXSIDES 6
#define FAILEDTOFIND "Failed to match vector"

class NNeighbor : protected Classifier
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


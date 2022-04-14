
//! NNeighbor Class
/*!
* A machine learning model that inherits from the Classifier class.
* This model is trained using Data objects containing x, y, z coordinates and a classifier label.
* Predicitions are made first by checking for an edge case, 2 equidistant points,
* The closest point is selected when classifying a vector. If there are two equidistant points
* then, the mean distance is calculated between the new point and each point of every classification
* The shortest mean distance is chosen. The label of the vectors whose mean distance is shortest is given to
* the new vector.
* 
* This class implements:
* @see train()
* @see predict()
* behaviours from the Classifier class.
*/
#pragma once
#include "Classifier.h"
#include "Exception.h"

#define MAXSIDES 6
#define FAILEDTOFINDCLOSEST "Failed to find closest vector"
#define FAILEDTOFINDMEAN "Failed to find closest mean"
#define COIN 2

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

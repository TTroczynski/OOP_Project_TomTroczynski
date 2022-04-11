#include "NNeighbor.h"

/*! \brief Makes prediction based on shortest distance
*
* Attempts to predict the label by returning the label
* of the closest point, unless two different points
* are equidistant
* Calls getDistance() and getLabel()
* @see getDistance
* @see getLabel()
* 
* @param Data object reference
* @return label of closest point
*/
std::string NNeighbor::evaluateClosest(Data& newData)
{
	int vectorSize = (int)this->dataSet.size();
	double tempCurrentDistance = 0;
	double tempLeastDistance = DBL_MAX;
	int bestMatchIndex = -1;
	std::string prediction;

	for (int j = 0; j < vectorSize; j++) {

		tempCurrentDistance = newData.getDistance(this->dataSet[j]);

		if (tempLeastDistance == tempCurrentDistance) {

		return FAILEDTOFIND;
		}
		if (tempCurrentDistance < tempLeastDistance) {

			tempLeastDistance = tempCurrentDistance;
			bestMatchIndex = j;
		}
		
		prediction = this->dataSet[bestMatchIndex].getLabel();
	}
	return prediction;
}

/*! \brief Makes prediction based on mean distance
*
* If we fail to find a closest due to a second equidistant point, we predict 
* using the mean distance of all labels to find the closest mean and return that label
* Calls getMeanDistance()
* @see getMeanDistance()
* 
* @param Data object reference
* @return label of closest mean of all classified points
*/
std::string NNeighbor::evaluateMeans(Data& newData)
{
	int vectorSize = (int)this->dataSet.size();
	std::string prediction;
	double closest = DBL_MAX;

	for (int i = 1; i < MAXSIDES; i++) {

		std::string label = std::to_string(i);

		double labeledMean = newData.getMeanDistance(this->dataSet, label);

		if (labeledMean < closest) {

			closest = labeledMean;
			prediction = label;
		}
	}
	if (!prediction.empty()) {
		return prediction;
	}
	else {
		return FAILEDTOFIND;
	}
}

/*! \brief Adds the data point to the model
*
* Adds data point to model so that it can be used to predict unknown (unlabeled) points
* 
* @param Data object reference
*/
void NNeighbor::train(Data& newData)
{
	this->dataSet.push_back(newData);
}


/*! \brief Makes a prediction based on the modeled data
*
* Returns the label of the closest matching point or closest means label. Each mean is calculated using a sum of all distances of points with each label.
* @see evaluateClosest()
* @see evaluateMeans()
* 
* @param Data object reference
* @return predicted label
*/
std::string NNeighbor::predict(Data& newData)
{
	std::string prediction;
	if ((prediction = evaluateClosest(newData)) != FAILEDTOFIND) {
		return prediction;
	}
	else if((prediction = evaluateMeans(newData)) != FAILEDTOFIND) {
		return prediction;
	}
	return FAILEDTOFIND;
}

/*! \brief Retrieves the models data set
*
* returns a vector containing all the points the model has been trained with
* 
* @return this NNeighbor's trained data set
*/
std::vector<Data> NNeighbor::getDataSet()
{
	return this->dataSet;
}

/*! \brief Overloads the << operator
*
* Makes printing NNeighbor objects with the << operator possible. Calls getDataSet()
* @see getDataSet()
* 
* @param ostream object reference
* @param NNeighbour object reference
* 
* @return ostream object
*/
std::ostream& operator<<(std::ostream& cout, NNeighbor& model)
{
	for (Data element : model.getDataSet()) {
		cout << element;
	}
	return cout;
}

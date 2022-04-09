#include "NNeighbor.h"

/*! \brief Adds the data point to the model
*
* Adds data point to model so that it can be used to predict unknown (unlabeled) points
*/
void NNeighbor::train(Data& newData)
{
	this->dataSet.push_back(newData);
}


/*! \brief Makes a prediction based on the modeled data
*
* Returns the label of the closest matching point or closest means label.
* Each mean is calculated using a sum of all distances of points with each label.
*/
std::string NNeighbor::predict(Data& newData)
{
	double tempLeastDistance = DBL_MAX;
	double tempCurrentDistance = 0;
	int bestMatchIndex = 0;

	int vectorSize = this->dataSet.size();

	for (int j = 0; j < vectorSize; j++) {

		tempCurrentDistance = newData.getDistance(this->dataSet[j]);

		if (tempCurrentDistance == tempLeastDistance) {

			double closest = DBL_MAX;
			std::string labelMemory;

			for (int i = 1; i < MAXSIDES; i++) {

				std::string label = std::to_string(i);
				
				double labeledMean = newData.getMeanDistance(this->dataSet, label);

				if (labeledMean < closest) {

					closest = labeledMean;
					labelMemory = label;
				}
			}
			return labelMemory;
		}
		else if (tempCurrentDistance < tempLeastDistance) {

			tempLeastDistance = tempCurrentDistance;
			bestMatchIndex = j;
		}
	}
	
	return this->dataSet[bestMatchIndex].getLabel();
}

/*! \brief Retrieves the models data set
*
* returns a vector containing all the points the model has been trained with
*/
std::vector<Data> NNeighbor::getDataSet()
{
	return this->dataSet;
}

/*! \brief Overloads the << operator
*
* Makes printing NNeighbor objects with the << operator possible
*/
std::ostream& operator<<(std::ostream& cout, NNeighbor& model)
{
	for (Data element : model.getDataSet()) {
		cout << element;
	}
	return cout;
}

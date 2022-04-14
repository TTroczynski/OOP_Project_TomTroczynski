#include "OtherModel.h"

/*! \brief Adds the data point to the model
*
* Adds data point to model so that it can be used to predict unknown (unlabeled) points
*
* @param Data object reference
*/

void OtherModel::train(Data& newData)
{
	std::cout << "training OtherModel with new vector" << std::endl;
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

std::string OtherModel::predict(Data& newData)
{
	std::cout << "Predicting new vectors label" << std::endl;
	return newData.getLabel();
}

/*! \brief Overloads the << operator
*
* Makes printing NNeighbor objects with the << operator possible. Calls getDataSet()
* @see getDataSet()
*
* @param ostream object reference
* @param OtherModel object reference
*
* @return ostream object
*/

std::ostream& operator<<(std::ostream& cout, OtherModel& model)
{
	cout << "Printing this OtherModel object with << operator" << std::endl;
	return cout;
}

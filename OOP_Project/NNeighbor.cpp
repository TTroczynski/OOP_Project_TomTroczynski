#include "NNeighbor.h"

void NNeighbor::train(Data& newData)
{
	this->dataSet.push_back(newData);
}

std::string NNeighbor::predict(Data& newData)
{
	double tempLeastDistance = DBL_MAX;
	double tempCurrentDistance = 0;
	int bestMatchIndex = 0;
	std::string matchedLabel;

	int vectorSize = this->dataSet.size();

	for (int j = 0; j < vectorSize; j++) {

		tempCurrentDistance = newData.getDistance(this->dataSet[j]);

		if (tempCurrentDistance < tempLeastDistance) {

			tempLeastDistance = tempCurrentDistance;
			bestMatchIndex = j;
			matchedLabel = this->dataSet[bestMatchIndex].getLabel();
		}

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
	}
	
	return this->dataSet[bestMatchIndex].getLabel();
}

std::vector<Data> NNeighbor::getDataSet()
{
	return this->dataSet;
}


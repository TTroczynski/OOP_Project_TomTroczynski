#include "OtherModel.h"

void OtherModel::train(Data& newData)
{
	std::cout << "training OtherModel with new vector" << std::endl;
}

std::string OtherModel::predict(Data& newData)
{
	std::cout << "Predicting new vectors label" << std::endl;
	return newData.getLabel();
}

std::ostream& operator<<(std::ostream& cout, OtherModel& model)
{
	cout << "Printing this OtherModel object with << operator" << std::endl;
	return cout;
}

#pragma once
#include "Data.h"

class Classifier : public Data
{

protected:
/*! \brief Trains model 
*
* Trains the model with data points consisting of an x,y,z value
*/
	virtual void train(Data&) = 0;

/*! \brief Predicts label
*
* preicts label based on the supplied Data point by comapring against the entire set
*/
	virtual std::string predict(Data&) = 0;
};

